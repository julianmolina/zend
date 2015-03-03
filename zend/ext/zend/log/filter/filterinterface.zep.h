
extern zend_class_entry *zend_log_filter_filterinterface_ce;

ZEPHIR_INIT_CLASS(Zend_Log_Filter_FilterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_log_filter_filterinterface_filter, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, event, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zend_log_filter_filterinterface_method_entry) {
	PHP_ABSTRACT_ME(Zend_Log_Filter_FilterInterface, filter, arginfo_zend_log_filter_filterinterface_filter)
  PHP_FE_END
};
