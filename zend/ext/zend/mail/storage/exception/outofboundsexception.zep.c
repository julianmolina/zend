
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * Exception for Zend\Mail component.
 */
ZEPHIR_INIT_CLASS(Zend_Mail_Storage_Exception_OutOfBoundsException) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Mail\\Storage\\Exception, OutOfBoundsException, zend, mail_storage_exception_outofboundsexception, zend_mail_exception_outofboundsexception_ce, NULL, 0);

	zend_class_implements(zend_mail_storage_exception_outofboundsexception_ce TSRMLS_CC, 1, zend_mail_storage_exception_exceptioninterface_ce);
	return SUCCESS;

}

