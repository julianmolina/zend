
extern zend_class_entry *zend_stdlib_parameterobjectinterface_ce;

ZEPHIR_INIT_CLASS(Zend_Stdlib_ParameterObjectInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_stdlib_parameterobjectinterface___set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_stdlib_parameterobjectinterface___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_stdlib_parameterobjectinterface___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_stdlib_parameterobjectinterface___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zend_stdlib_parameterobjectinterface_method_entry) {
	PHP_ABSTRACT_ME(Zend_Stdlib_ParameterObjectInterface, __set, arginfo_zend_stdlib_parameterobjectinterface___set)
	PHP_ABSTRACT_ME(Zend_Stdlib_ParameterObjectInterface, __get, arginfo_zend_stdlib_parameterobjectinterface___get)
	PHP_ABSTRACT_ME(Zend_Stdlib_ParameterObjectInterface, __isset, arginfo_zend_stdlib_parameterobjectinterface___isset)
	PHP_ABSTRACT_ME(Zend_Stdlib_ParameterObjectInterface, __unset, arginfo_zend_stdlib_parameterobjectinterface___unset)
  PHP_FE_END
};
