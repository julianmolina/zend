
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(Zend_Authentication_Adapter_DbTable_Exception_ExceptionInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Authentication\\Adapter\\DbTable\\Exception, ExceptionInterface, zend, authentication_adapter_dbtable_exception_exceptioninterface, NULL);

	zend_class_implements(zend_authentication_adapter_dbtable_exception_exceptioninterface_ce TSRMLS_CC, 1, zend_authentication_adapter_exception_exceptioninterface_ce);
	return SUCCESS;

}

