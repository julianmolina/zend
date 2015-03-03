
extern zend_class_entry *zend_stdlib_initializableinterface_ce;

ZEPHIR_INIT_CLASS(Zend_Stdlib_InitializableInterface);

ZEPHIR_INIT_FUNCS(zend_stdlib_initializableinterface_method_entry) {
	PHP_ABSTRACT_ME(Zend_Stdlib_InitializableInterface, init, NULL)
  PHP_FE_END
};
