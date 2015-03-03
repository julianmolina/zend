
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(Zend_Stdlib_ArraySerializableInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Stdlib, ArraySerializableInterface, zend, stdlib_arrayserializableinterface, zend_stdlib_arrayserializableinterface_method_entry);

	return SUCCESS;

}

/**
 * Exchange internal values from provided array
 *
 * @param  array $array
 * @return void
 */
ZEPHIR_DOC_METHOD(Zend_Stdlib_ArraySerializableInterface, exchangeArray);

/**
 * Return an array representation of the object
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Zend_Stdlib_ArraySerializableInterface, getArrayCopy);

