
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * Base exception interface for barcode objects
 */
ZEPHIR_INIT_CLASS(Zend_Barcode_Object_Exception_ExceptionInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Barcode\\Object\\Exception, ExceptionInterface, zend, barcode_object_exception_exceptioninterface, NULL);

	zend_class_implements(zend_barcode_object_exception_exceptioninterface_ce TSRMLS_CC, 1, zend_barcode_exception_exceptioninterface_ce);
	return SUCCESS;

}

