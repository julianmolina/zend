
/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Zend\Barcode\Object;

/**
 * Class for generate Interleaved 2 of 5 barcode
 */
class Code25 extends AbstractObject
{
    /**
     * Coding map
     * - 0 = narrow bar
     * - 1 = wide bar
     * @var array
     */
    protected codingMap = [
        '0' : '00110',
        '1' : '10001',
        '2' : '01001',
        '3' : '11000',
        '4' : '00101',
        '5' : '10100',
        '6' : '01100',
        '7' : '00011',
        '8' : '10010',
        '9' : '01010',
    ];

    /**
     * Width of the barcode (in pixels)
     * @return int
     */
    protected function calculateBarcodeWidth()
    {
        let quietZone       = this->getQuietZone();
        let startCharacter  = (2 * this->barThickWidth + 4 * this->barThinWidth) * this->factor;
        let characterLength = (3 * this->barThinWidth + 2 * this->barThickWidth + 5 * this->barThinWidth)
                         * this->factor;
        let encodedData     = strlen(this->getText()) * characterLength;
        let stopCharacter   = (2 * this->barThickWidth + 4 * this->barThinWidth) * this->factor;
        return quietZone + startCharacter + encodedData + stopCharacter + quietZone;
    }

    /**
     * Partial check of interleaved 2 of 5 barcode
     * @return void
     */
    protected function checkSpecificParams()
    {
        this->checkRatio();
    }

    /**
     * Prepare array to draw barcode
     * @return array
     */
    protected function prepareBarcode()
    {
        let barcodeTable = [];

        // Start character (30301)
        let barcodeTable[] = [1, this->barThickWidth, 0, 1];
        let barcodeTable[] = [0, this->barThinWidth, 0, 1];
        let barcodeTable[] = [1, this->barThickWidth, 0, 1];
        let barcodeTable[] = [0, this->barThinWidth, 0, 1];
        let barcodeTable[] = [1, this->barThinWidth, 0, 1];
        let barcodeTable[] = [0, this->barThinWidth];

        let text = str_split(this->getText());
        for chars in text {
            let barcodeChar = str_split(this->codingMap[chars]);
            for c in barcodeChar {
                /* visible, width, top, length */
                let width = c ? this->barThickWidth : this->barThinWidth;
                let barcodeTable[] = [1, width, 0, 1];
                let barcodeTable[] = [0, this->barThinWidth];
            }
        }

        // Stop character (30103)
        let barcodeTable[] = [1, this->barThickWidth, 0, 1];
        let barcodeTable[] = [0, this->barThinWidth, 0, 1];
        let barcodeTable[] = [1, this->barThinWidth, 0, 1];
        let barcodeTable[] = [0, this->barThinWidth, 0, 1];
        let barcodeTable[] = [1, this->barThickWidth, 0, 1];
        return barcodeTable;
    }

    /**
     * Get barcode checksum
     *
     * @param  string text
     * @return int
     */
    public function getChecksum(text)
    {
        this->checkText(text);
        let factor   = 3;
        let checksum = 0;

        let i = strlen(text);
        for i > 0 {
            let checksum += intval(text{i - 1}) * factor;
            let factor    = 4 - factor;
            let i --;
        }

        let checksum = (10 - (checksum % 10)) % 10;

        return checksum;
    }
}
