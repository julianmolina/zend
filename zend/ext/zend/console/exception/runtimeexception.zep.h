
extern zend_class_entry *zend_console_exception_runtimeexception_ce;

ZEPHIR_INIT_CLASS(Zend_Console_Exception_RuntimeException);

PHP_METHOD(Zend_Console_Exception_RuntimeException, __construct);
PHP_METHOD(Zend_Console_Exception_RuntimeException, getUsageMessage);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_console_exception_runtimeexception___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, usage)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zend_console_exception_runtimeexception_method_entry) {
	PHP_ME(Zend_Console_Exception_RuntimeException, __construct, arginfo_zend_console_exception_runtimeexception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zend_Console_Exception_RuntimeException, getUsageMessage, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
