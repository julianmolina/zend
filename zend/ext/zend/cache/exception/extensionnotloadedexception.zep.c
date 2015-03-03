
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
ZEPHIR_INIT_CLASS(Zend_Cache_Exception_ExtensionNotLoadedException) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Cache\\Exception, ExtensionNotLoadedException, zend, cache_exception_extensionnotloadedexception, zend_cache_exception_runtimeexception_ce, NULL, 0);

	return SUCCESS;

}

