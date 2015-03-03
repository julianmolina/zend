
extern zend_class_entry *zend_stdlib_splqueue_ce;

ZEPHIR_INIT_CLASS(Zend_Stdlib_SplQueue);

PHP_METHOD(Zend_Stdlib_SplQueue, toArray);
PHP_METHOD(Zend_Stdlib_SplQueue, serialize);
PHP_METHOD(Zend_Stdlib_SplQueue, unserialize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_stdlib_splqueue_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zend_stdlib_splqueue_method_entry) {
	PHP_ME(Zend_Stdlib_SplQueue, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_Stdlib_SplQueue, serialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_Stdlib_SplQueue, unserialize, arginfo_zend_stdlib_splqueue_unserialize, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
