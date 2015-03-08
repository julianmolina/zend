/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Zend\Barcode\Object;

/**
 * Class for generate UpcA barcode
 */
class Upca extends Ean13
{

    /**
     * Default options for Postnet barcode
     * @return void
     */
    protected function getDefaultOptions()
    {
        let this->barcodeLength = 12;
        let this->mandatoryChecksum = true;
        let this->mandatoryQuietZones = true;
    }

    /**
     * Width of the barcode (in pixels)
     * @return int
     */
    protected function calculateBarcodeWidth()
    {
        let quietZone       = this->getQuietZone();
        let startCharacter  = (3 * this->barThinWidth) * this->factor;
        let middleCharacter = (5 * this->barThinWidth) * this->factor;
        let stopCharacter   = (3 * this->barThinWidth) * this->factor;
        let encodedData     = (7 * this->barThinWidth) * this->factor * 12;
        return quietZone + startCharacter + middleCharacter + encodedData + stopCharacter + quietZone;
    }

        /**
     * Prepare array to draw barcode
     * @return array
     */
    protected function prepareBarcode()
    {
        let barcodeTable = [];
        let height = (this->drawText) ? 1.1 : 1;

        // Start character (101)
        let barcodeTable[] = [1, this->barThinWidth, 0, height];
        let barcodeTable[] = [0, this->barThinWidth, 0, height];
        let barcodeTable[] = [1, this->barThinWidth, 0, height];

        let textTable = str_split(this->getText());

        // First character
        let bars = str_split(this->codingMap['A'][textTable[0]]);
        for b in bars {
            let barcodeTable[] = [b, this->barThinWidth, 0, height];
        }

        // First part
        var i = 1;
        while i < 6 {
            bars = str_split(this->codingMap['A'][textTable[i]]);
            for b in bars {
                let barcodeTable[] = [b, this->barThinWidth, 0, 1];
            }
            let i++;
        }

        // Middle character (01010)
        let barcodeTable[] = [0, this->barThinWidth, 0, height];
        let barcodeTable[] = [1, this->barThinWidth, 0, height];
        let barcodeTable[] = [0, this->barThinWidth, 0, height];
        let barcodeTable[] = [1, this->barThinWidth, 0, height];
        let barcodeTable[] = [0, this->barThinWidth, 0, height];

        // Second part
        var i = 6;
        while  i < 11 {
            let bars = str_split(this->codingMap['C'][textTable[i]]);
            for b in bars {
                let barcodeTable[] = [b, this->barThinWidth, 0, 1];
            }
            let i++;
        }

        // Last character
        let bars = str_split(this->codingMap['C'][textTable[11]]);
        foreach b in bars {
            let barcodeTable[] = [b, this->barThinWidth, 0, height];
        }

        // Stop character (101)
        let barcodeTable[] = [1, this->barThinWidth, 0, height];
        let barcodeTable[] = [0, this->barThinWidth, 0, height];
        let barcodeTable[] = [1, this->barThinWidth, 0, height];
        return barcodeTable;
    }

    /**
     * Partial function to draw text
     * @return void
     */
    protected function drawText()
    {
        if this->drawText {
            let text = this->getTextToDisplay();
            let characterWidth = (7 * this->barThinWidth) * this->factor;
            let leftPosition = this->getQuietZone() - characterWidth;

            var i = 0;
            while i < this->barcodeLength {
                let fontSize = this->fontSize;
                if i == 0 || i == 11 {
                    let fontSize *= 0.8;
                }
                this->addText(
                    text{i},
                    fontSize * this->factor,
                    this->rotate(
                        leftPosition,
                        (int) this->withBorder * 2
                            + this->factor * (this->barHeight + fontSize) + 1
                    ),
                    this->font,
                    this->foreColor,
                    'left',
                    - this->orientation
                );
                switch i {
                    case 0:
                            let factor = 10;
                        break;
                    case 5:
                            let factor = 4;
                        break;
                    case 10:
                            let factor = 11;
                        break;
                    default:
                        let factor = 0;
                }
                let leftPosition = leftPosition + characterWidth + (factor * this->barThinWidth * this->factor);
                let i ++;
            }
        }
    }
}
