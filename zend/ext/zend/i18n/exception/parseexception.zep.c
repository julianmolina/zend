
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
ZEPHIR_INIT_CLASS(Zend_I18n_Exception_ParseException) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\I18n\\Exception, ParseException, zend, i18n_exception_parseexception, zend_i18n_exception_runtimeexception_ce, NULL, 0);

	zend_class_implements(zend_i18n_exception_parseexception_ce TSRMLS_CC, 1, zend_i18n_exception_exceptioninterface_ce);
	return SUCCESS;

}

