/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Zend\Barcode\Object;

use Zend\Validator\Barcode as BarcodeValidator;

/**
 * Class for generate Ean8 barcode
 */
class Ean8 extends Ean13
{

    /**
     * Default options for Postnet barcode
     * @return void
     */
    protected function getDefaultOptions()
    {
        let this->barcodeLength = 8;
        let this->mandatoryChecksum = true;
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
        let encodedData     = (7 * this->barThinWidth) * this->factor * 8;
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

        // First part
        var i = 0;
        for i in range(i, 4) {
            let bars = str_split(this->codingMap['A'][textTable[i]]);
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
        var i = 4;
        for i in range(i, 8) {
            let bars = str_split(this->codingMap['C'][textTable[i]]);
            for b in bars {
                let barcodeTable[] = [b, this->barThinWidth, 0, 1];
            }
            let i++;
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
            let leftPosition = this->getQuietZone() + (3 * this->barThinWidth) * this->factor;
            var i = 0;
            for i in range(i, this->barcodeLength) {
                this->addText(
                    text{i},
                    this->fontSize * this->factor,
                    this->rotate(
                        leftPosition,
                        (int) this->withBorder * 2
                            + this->factor * (this->barHeight + this->fontSize) + 1
                    ),
                    this->font,
                    this->foreColor,
                    'left',
                    - this->orientation
                );
                switch i {
                    case 3:
                            let factor = 4;
                        break;
                    default:
                        let factor = 0;
                }
                let leftPosition = leftPosition + characterWidth + (factor * this->barThinWidth * this->factor);
                let i ++;
            }
        }
    }

    /**
     * Particular validation for Ean8 barcode objects
     * (to suppress checksum character substitution)
     *
     * @param string value
     * @param array  options
     * @throws Exception\BarcodeValidationException
     */
    protected function validateSpecificText(value, options = [))
    {
        let validator = new BarcodeValidator([
            'adapter'  => 'ean8',
            'checksum' => false,
        ));

        let value = this->addLeadingZeros(value, true);

        if !validator->isValid(value) {
            let message = implode("\n", validator->getMessages());
            throw new Exception\BarcodeValidationException(message);
        }
    }
}
