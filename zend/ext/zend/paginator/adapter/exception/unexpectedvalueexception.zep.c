
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
ZEPHIR_INIT_CLASS(Zend_Paginator_Adapter_Exception_UnexpectedValueException) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Paginator\\Adapter\\Exception, UnexpectedValueException, zend, paginator_adapter_exception_unexpectedvalueexception, zend_paginator_exception_unexpectedvalueexception_ce, NULL, 0);

	zend_class_implements(zend_paginator_adapter_exception_unexpectedvalueexception_ce TSRMLS_CC, 1, zend_paginator_adapter_exception_exceptioninterface_ce);
	return SUCCESS;

}

