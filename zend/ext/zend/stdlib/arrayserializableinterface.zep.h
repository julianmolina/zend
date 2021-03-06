
extern zend_class_entry *zend_stdlib_arrayserializableinterface_ce;

ZEPHIR_INIT_CLASS(Zend_Stdlib_ArraySerializableInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_stdlib_arrayserializableinterface_exchangearray, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, array, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zend_stdlib_arrayserializableinterface_method_entry) {
	PHP_ABSTRACT_ME(Zend_Stdlib_ArraySerializableInterface, exchangeArray, arginfo_zend_stdlib_arrayserializableinterface_exchangearray)
	PHP_ABSTRACT_ME(Zend_Stdlib_ArraySerializableInterface, getArrayCopy, NULL)
  PHP_FE_END
};
