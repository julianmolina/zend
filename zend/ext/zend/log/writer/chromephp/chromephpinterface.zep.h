
extern zend_class_entry *zend_log_writer_chromephp_chromephpinterface_ce;

ZEPHIR_INIT_CLASS(Zend_Log_Writer_ChromePhp_ChromePhpInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_log_writer_chromephp_chromephpinterface_error, 0, 0, 1)
	ZEND_ARG_INFO(0, line)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_log_writer_chromephp_chromephpinterface_warn, 0, 0, 1)
	ZEND_ARG_INFO(0, line)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_log_writer_chromephp_chromephpinterface_info, 0, 0, 1)
	ZEND_ARG_INFO(0, line)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_log_writer_chromephp_chromephpinterface_trace, 0, 0, 1)
	ZEND_ARG_INFO(0, line)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_log_writer_chromephp_chromephpinterface_log, 0, 0, 1)
	ZEND_ARG_INFO(0, line)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zend_log_writer_chromephp_chromephpinterface_method_entry) {
	PHP_ABSTRACT_ME(Zend_Log_Writer_ChromePhp_ChromePhpInterface, error, arginfo_zend_log_writer_chromephp_chromephpinterface_error)
	PHP_ABSTRACT_ME(Zend_Log_Writer_ChromePhp_ChromePhpInterface, warn, arginfo_zend_log_writer_chromephp_chromephpinterface_warn)
	PHP_ABSTRACT_ME(Zend_Log_Writer_ChromePhp_ChromePhpInterface, info, arginfo_zend_log_writer_chromephp_chromephpinterface_info)
	PHP_ABSTRACT_ME(Zend_Log_Writer_ChromePhp_ChromePhpInterface, trace, arginfo_zend_log_writer_chromephp_chromephpinterface_trace)
	PHP_ABSTRACT_ME(Zend_Log_Writer_ChromePhp_ChromePhpInterface, log, arginfo_zend_log_writer_chromephp_chromephpinterface_log)
  PHP_FE_END
};
