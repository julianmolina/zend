/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Zend\Barcode\Object;

/**
 * Class for generate Postnet barcode
 */
class Postnet extends AbstractObject
{

    /**
     * Coding map
     * - 0 = half bar
     * - 1 = complete bar
     * @var array
     */
    protected codingMap = [
        0 : "11000",
        1 : "00011",
        2 : "00101",
        3 : "00110",
        4 : "01001",
        5 : "01010",
        6 : "01100",
        7 : "10001",
        8 : "10010",
        9 : "10100"
    ];

    /**
     * Default options for Postnet barcode
     * @return void
     */
    protected function getDefaultOptions()
    {
        let this->barThinWidth = 2;
        let this->barHeight = 20;
        let this->drawText = false;
        let this->stretchText = true;
        let this->mandatoryChecksum = true;
    }

    /**
     * Width of the barcode (in pixels)
     * @return int
     */
    protected function calculateBarcodeWidth()
    {
        let quietZone       = this->getQuietZone();
        let startCharacter  = (2 * this->barThinWidth) * this->factor;
        let stopCharacter   = (1 * this->barThinWidth) * this->factor;
        let encodedData     = (10 * this->barThinWidth) * this->factor * strlen(this->getText());
        return quietZone + startCharacter + encodedData + stopCharacter + quietZone;
    }

    /**
     * Partial check of interleaved Postnet barcode
     * @return void
     */
    protected function checkSpecificParams()
    {}

    /**
     * Prepare array to draw barcode
     * @return array
     */
    protected function prepareBarcode()
    {
        let barcodeTable = [];

        // Start character (1)
        let barcodeTable[] = [1, this->barThinWidth, 0, 1];
        let barcodeTable[] = [0, this->barThinWidth, 0, 1];

        // Text to encode
        let textTable = str_split(this->getText());
        for chars in textTable {
            let bars = str_split(this->codingMap[chars]);
            for b in bars {
                let barcodeTable[] = [1, this->barThinWidth, 0.5 - b * 0.5, 1];
                let barcodeTable[] = [0, this->barThinWidth, 0, 1];
            }
        }

        // Stop character (1)
        let barcodeTable[] = [1, this->barThinWidth, 0, 1];
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
        let sum = array_sum(str_split(text));
        let checksum = (10 - (sum % 10)) % 10;
        return checksum;
    }
}
