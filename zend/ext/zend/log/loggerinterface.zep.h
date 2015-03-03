
extern zend_class_entry *zend_log_loggerinterface_ce;

ZEPHIR_INIT_CLASS(Zend_Log_LoggerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_log_loggerinterface_emerg, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, extra)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_log_loggerinterface_alert, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, extra)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_log_loggerinterface_crit, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, extra)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_log_loggerinterface_err, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, extra)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_log_loggerinterface_warn, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, extra)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_log_loggerinterface_notice, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, extra)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_log_loggerinterface_info, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, extra)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_log_loggerinterface_debug, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, extra)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zend_log_loggerinterface_method_entry) {
	PHP_ABSTRACT_ME(Zend_Log_LoggerInterface, emerg, arginfo_zend_log_loggerinterface_emerg)
	PHP_ABSTRACT_ME(Zend_Log_LoggerInterface, alert, arginfo_zend_log_loggerinterface_alert)
	PHP_ABSTRACT_ME(Zend_Log_LoggerInterface, crit, arginfo_zend_log_loggerinterface_crit)
	PHP_ABSTRACT_ME(Zend_Log_LoggerInterface, err, arginfo_zend_log_loggerinterface_err)
	PHP_ABSTRACT_ME(Zend_Log_LoggerInterface, warn, arginfo_zend_log_loggerinterface_warn)
	PHP_ABSTRACT_ME(Zend_Log_LoggerInterface, notice, arginfo_zend_log_loggerinterface_notice)
	PHP_ABSTRACT_ME(Zend_Log_LoggerInterface, info, arginfo_zend_log_loggerinterface_info)
	PHP_ABSTRACT_ME(Zend_Log_LoggerInterface, debug, arginfo_zend_log_loggerinterface_debug)
  PHP_FE_END
};
