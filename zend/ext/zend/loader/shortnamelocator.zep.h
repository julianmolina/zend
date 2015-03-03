
extern zend_class_entry *zend_loader_shortnamelocator_ce;

ZEPHIR_INIT_CLASS(Zend_Loader_ShortNameLocator);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_loader_shortnamelocator_isloaded, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_loader_shortnamelocator_getclassname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_loader_shortnamelocator_load, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zend_loader_shortnamelocator_method_entry) {
	PHP_ABSTRACT_ME(Zend_Loader_ShortNameLocator, isLoaded, arginfo_zend_loader_shortnamelocator_isloaded)
	PHP_ABSTRACT_ME(Zend_Loader_ShortNameLocator, getClassName, arginfo_zend_loader_shortnamelocator_getclassname)
	PHP_ABSTRACT_ME(Zend_Loader_ShortNameLocator, load, arginfo_zend_loader_shortnamelocator_load)
  PHP_FE_END
};
