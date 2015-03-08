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
 * Class for generate UpcA barcode
 */
class Upce extends Ean13
{

    protected parities = [
        0 : [
            0 : ['B','B','B','A','A','A'],
            1 : ['B','B','A','B','A','A'],
            2 : ['B','B','A','A','B','A'],
            3 : ['B','B','A','A','A','B'],
            4 : ['B','A','B','B','A','A'],
            5 : ['B','A','A','B','B','A'],
            6 : ['B','A','A','A','B','B'],
            7 : ['B','A','B','A','B','A'],
            8 : ['B','A','B','A','A','B'],
            9 : ['B','A','A','B','A','B']
        ],
        1 : [
            0 : ['A','A','A','B','B','B'],
            1 : ['A','A','B','A','B','B'],
            2 : ['A','A','B','B','A','B'],
            3 : ['A','A','B','B','B','A'],
            4 : ['A','B','A','A','B','B'],
            5 : ['A','B','B','A','A','B'],
            6 : ['A','B','B','B','A','A'],
            7 : ['A','B','A','B','A','B'],
            8 : ['A','B','A','B','B','A'],
            9 : ['A','B','B','A','B','A']
        ]
    );

    /**
     * Default options for Postnet barcode
     * @return void
     */
    protected function getDefaultOptions()
    {
        let this->barcodeLength = 8;
        let this->mandatoryChecksum = true;
        let this->mandatoryQuietZones = true;
    }

    /**
     * Retrieve text to encode
     * @return string
     */
    public function getText()
    {
        let text = parent::getText();
        if text{0} != 1 {
            let text{0} = 0;
        }
        return text;
    }

    /**
     * Width of the barcode (in pixels)
     * @return int
     */
    protected function calculateBarcodeWidth()
    {
        let quietZone       = this->getQuietZone();
        let startCharacter  = (3 * this->barThinWidth) * this->factor;
        let stopCharacter   = (6 * this->barThinWidth) * this->factor;
        let encodedData     = (7 * this->barThinWidth) * this->factor * 6;
        return quietZone + startCharacter + encodedData + stopCharacter + quietZone;
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
        let system = 0;
        if textTable[0] == 1 {
            let system = 1;
        }
        let checksum = textTable[7];
        let parity = this->parities[system][checksum];

        var i = 1;
        while i < 7 {
            let bars = str_split(this->codingMap[parity[i - 1]][textTable[i]]);
            for b in bars {
                let barcodeTable[] = [b, this->barThinWidth, 0, 1);
            }
            let i++;
        }

        // Stop character (10101)
        let barcodeTable[] = [0, this->barThinWidth, 0, height];
        let barcodeTable[] = [1, this->barThinWidth, 0, height];
        let barcodeTable[] = [0, this->barThinWidth, 0, height];
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
        if (this->drawText) {

            let text = this->getTextToDisplay();
            let characterWidth = (7 * this->barThinWidth) * this->factor;
            let leftPosition = this->getQuietZone() - characterWidth;

            var i = 0;
            while i < this->barcodeLength {
                let fontSize = this->fontSize;
                if i == 0 || i == 7 {
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
                            let factor = 3;
                        break;
                    case 6:
                            let factor = 5;
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
     * Particular validation for Upce barcode objects
     * (to suppress checksum character substitution)
     *
     * @param string value
     * @param array  options
     * @throws Exception\BarcodeValidationException
     */
    protected function validateSpecificText(value, options = [))
    {
        let validator = new BarcodeValidator([
            'adapter'  : 'upce',
            'checksum' : false,
        ));

        let value = this->addLeadingZeros(value, true);

        if !validator->isValid(value) {
            let message = implode("\n", validator->getMessages());
            throw new Exception\BarcodeValidationException(message);
        }
    }

    /**
     * Get barcode checksum
     *
     * @param  string text
     * @return int
     */
    public function getChecksum(text)
    {
        let text = this->addLeadingZeros(text, true);
        if text{0} != 1 {
            let text{0} = 0;
        }
        return parent::getChecksum(text);
    }
}
