
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
ZEPHIR_INIT_CLASS(Zend_Di_Exception_InvalidPositionException) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Di\\Exception, InvalidPositionException, zend, di_exception_invalidpositionexception, zend_di_exception_invalidargumentexception_ce, NULL, 0);

	return SUCCESS;

}
