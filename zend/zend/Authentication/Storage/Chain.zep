
/**
 * Zend Framework (http://framework.zend.com/)
 *
 * Zephir translate by Julián Arturo Molina zendphpcolombia@gmail.com
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Zend\Authentication\Storage;

use Zend\Authentication\Storage\StorageInterface;
use Zend\Stdlib\PriorityQueue;

class Chain implements StorageInterface
{
    /**
     * Contains all storage that this authentication method uses. A storage
     * placed in the priority queue with a higher priority is always used
     * before using a storage with a lower priority.
     *
     * @var PriorityQueue
     */
    protected storageChain;

    /**
     * Initializes the priority queue.
     */
    public function __construct()
    {
        this->storageChain = new PriorityQueue();
    }

    /**
     * @param StorageInterface storage
     * @param int          priority
     */
    public function add(<StorageInterface> storage, priority = 1)
    {
        this->storageChain->insert(storage, priority);
    }

    /**
     * Loop over the queue of storage until a storage is found that is non-empty. If such
     * storage is not found, then this chain storage itself is empty.
     *
     * In case a non-empty storage is found then this chain storage is also non-empty. Report
     * that, but also make sure that all storage with higher priorty that are empty
     * are filled.
     *
     * @see StorageInterface::isEmpty()
     */
    public function isEmpty()
    {
        storageWithHigherPriority = array();

        // Loop invariant: storageWithHigherPriority contains all storage with higher priorty
        // than the current one.
        for storage in this->storageChain {
            if storage->isEmpty() {
                storageWithHigherPriority[] = storage;
                continue;
            }

            storageValue = storage->read();
            for higherPriorityStorage in storageWithHigherPriority {
                higherPriorityStorage->write(storageValue);
            }

            return false;
        }

        return true;
    }

    /**
     * If the chain is non-empty then the storage with the top priority is guaranteed to be
     * filled. Return its value.
     *
     * @see StorageInterface::read()
     */
    public function read()
    {
        return this->storageChain->top()->read();
    }

    /**
     * Write the new contents to all storage in the chain.
     *
     * @see StorageInterface::write()
     */
    public function write(contents)
    {
        for storage in this->storageChain {
            storage->write(contents);
        }
    }

    /**
     * Clear all storage in the chain.
     *
     * @see StorageInterface::clear()
     */
    public function clear()
    {
        for storage in this->storageChain {
            storage->clear();
        }
    }
}
