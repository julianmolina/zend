
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
 * Runtime exception
 */
ZEPHIR_INIT_CLASS(Zend_Math_BigInteger_Exception_RuntimeException) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Math\\BigInteger\\Exception, RuntimeException, zend, math_biginteger_exception_runtimeexception, zend_math_exception_runtimeexception_ce, NULL, 0);

	zend_class_implements(zend_math_biginteger_exception_runtimeexception_ce TSRMLS_CC, 1, zend_math_biginteger_exception_exceptioninterface_ce);
	return SUCCESS;

}

