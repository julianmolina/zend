
extern zend_class_entry *zend_db_adapter_driver_sqlsrv_exception_errorexception_ce;

ZEPHIR_INIT_CLASS(Zend_Db_Adapter_Driver_Sqlsrv_Exception_ErrorException);

PHP_METHOD(Zend_Db_Adapter_Driver_Sqlsrv_Exception_ErrorException, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_db_adapter_driver_sqlsrv_exception_errorexception___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, errors)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zend_db_adapter_driver_sqlsrv_exception_errorexception_method_entry) {
	PHP_ME(Zend_Db_Adapter_Driver_Sqlsrv_Exception_ErrorException, __construct, arginfo_zend_db_adapter_driver_sqlsrv_exception_errorexception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};