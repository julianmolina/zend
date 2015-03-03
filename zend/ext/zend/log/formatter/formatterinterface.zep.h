
extern zend_class_entry *zend_log_formatter_formatterinterface_ce;

ZEPHIR_INIT_CLASS(Zend_Log_Formatter_FormatterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_log_formatter_formatterinterface_format, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_log_formatter_formatterinterface_setdatetimeformat, 0, 0, 1)
	ZEND_ARG_INFO(0, dateTimeFormat)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zend_log_formatter_formatterinterface_method_entry) {
	PHP_ABSTRACT_ME(Zend_Log_Formatter_FormatterInterface, format, arginfo_zend_log_formatter_formatterinterface_format)
	PHP_ABSTRACT_ME(Zend_Log_Formatter_FormatterInterface, getDateTimeFormat, NULL)
	PHP_ABSTRACT_ME(Zend_Log_Formatter_FormatterInterface, setDateTimeFormat, arginfo_zend_log_formatter_formatterinterface_setdatetimeformat)
  PHP_FE_END
};
