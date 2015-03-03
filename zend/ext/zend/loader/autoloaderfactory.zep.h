
extern zend_class_entry *zend_loader_autoloaderfactory_ce;

ZEPHIR_INIT_CLASS(Zend_Loader_AutoloaderFactory);

PHP_METHOD(Zend_Loader_AutoloaderFactory, factory);
PHP_METHOD(Zend_Loader_AutoloaderFactory, getRegisteredAutoloaders);
PHP_METHOD(Zend_Loader_AutoloaderFactory, getRegisteredAutoloader);
PHP_METHOD(Zend_Loader_AutoloaderFactory, unregisterAutoloaders);
PHP_METHOD(Zend_Loader_AutoloaderFactory, unregisterAutoloader);
PHP_METHOD(Zend_Loader_AutoloaderFactory, getStandardAutoloader);
PHP_METHOD(Zend_Loader_AutoloaderFactory, isSubclassOf);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_loader_autoloaderfactory_factory, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_loader_autoloaderfactory_getregisteredautoloader, 0, 0, 1)
	ZEND_ARG_INFO(0, class)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_loader_autoloaderfactory_unregisterautoloader, 0, 0, 1)
	ZEND_ARG_INFO(0, autoloaderClass)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_loader_autoloaderfactory_issubclassof, 0, 0, 2)
	ZEND_ARG_INFO(0, className)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zend_loader_autoloaderfactory_method_entry) {
	PHP_ME(Zend_Loader_AutoloaderFactory, factory, arginfo_zend_loader_autoloaderfactory_factory, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zend_Loader_AutoloaderFactory, getRegisteredAutoloaders, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zend_Loader_AutoloaderFactory, getRegisteredAutoloader, arginfo_zend_loader_autoloaderfactory_getregisteredautoloader, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zend_Loader_AutoloaderFactory, unregisterAutoloaders, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zend_Loader_AutoloaderFactory, unregisterAutoloader, arginfo_zend_loader_autoloaderfactory_unregisterautoloader, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zend_Loader_AutoloaderFactory, getStandardAutoloader, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Zend_Loader_AutoloaderFactory, isSubclassOf, arginfo_zend_loader_autoloaderfactory_issubclassof, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
  PHP_FE_END
};
