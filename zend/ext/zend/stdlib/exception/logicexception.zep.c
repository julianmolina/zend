
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(Zend_Stdlib_Exception_LogicException) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Stdlib\\Exception, LogicException, zend, stdlib_exception_logicexception, spl_ce_LogicException, NULL, 0);

	zend_class_implements(zend_stdlib_exception_logicexception_ce TSRMLS_CC, 1, zend_stdlib_exception_exceptioninterface_ce);
	return SUCCESS;

}

