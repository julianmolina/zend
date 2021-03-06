
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
/**
 * Runtime argument exception
 */
ZEPHIR_INIT_CLASS(Zend_Math_Exception_RuntimeException) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Math\\Exception, RuntimeException, zend, math_exception_runtimeexception, spl_ce_RuntimeException, NULL, 0);

	zend_class_implements(zend_math_exception_runtimeexception_ce TSRMLS_CC, 1, zend_math_exception_exceptioninterface_ce);
	return SUCCESS;

}

