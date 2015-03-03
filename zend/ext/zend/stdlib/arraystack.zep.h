
extern zend_class_entry *zend_stdlib_arraystack_ce;

ZEPHIR_INIT_CLASS(Zend_Stdlib_ArrayStack);

PHP_METHOD(Zend_Stdlib_ArrayStack, getIterator);

ZEPHIR_INIT_FUNCS(zend_stdlib_arraystack_method_entry) {
	PHP_ME(Zend_Stdlib_ArrayStack, getIterator, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
