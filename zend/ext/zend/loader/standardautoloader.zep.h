
extern zend_class_entry *zend_loader_standardautoloader_ce;

ZEPHIR_INIT_CLASS(Zend_Loader_StandardAutoloader);

PHP_METHOD(Zend_Loader_StandardAutoloader, __construct);
PHP_METHOD(Zend_Loader_StandardAutoloader, setOptions);
PHP_METHOD(Zend_Loader_StandardAutoloader, setFallbackAutoloader);
PHP_METHOD(Zend_Loader_StandardAutoloader, isFallbackAutoloader);
PHP_METHOD(Zend_Loader_StandardAutoloader, registerNamespace);
PHP_METHOD(Zend_Loader_StandardAutoloader, registerNamespaces);
PHP_METHOD(Zend_Loader_StandardAutoloader, registerPrefix);
PHP_METHOD(Zend_Loader_StandardAutoloader, registerPrefixes);
PHP_METHOD(Zend_Loader_StandardAutoloader, autoload);
PHP_METHOD(Zend_Loader_StandardAutoloader, register);
PHP_METHOD(Zend_Loader_StandardAutoloader, transformClassNameToFilename);
PHP_METHOD(Zend_Loader_StandardAutoloader, loadClass);
PHP_METHOD(Zend_Loader_StandardAutoloader, normalizeDirectory);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_loader_standardautoloader___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_loader_standardautoloader_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_loader_standardautoloader_setfallbackautoloader, 0, 0, 1)
	ZEND_ARG_INFO(0, flag)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_loader_standardautoloader_registernamespace, 0, 0, 2)
	ZEND_ARG_INFO(0, namespace)
	ZEND_ARG_INFO(0, directory)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_loader_standardautoloader_registernamespaces, 0, 0, 1)
	ZEND_ARG_INFO(0, namespaces)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_loader_standardautoloader_registerprefix, 0, 0, 2)
	ZEND_ARG_INFO(0, prefix)
	ZEND_ARG_INFO(0, directory)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_loader_standardautoloader_registerprefixes, 0, 0, 1)
	ZEND_ARG_INFO(0, prefixes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_loader_standardautoloader_autoload, 0, 0, 1)
	ZEND_ARG_INFO(0, class)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_loader_standardautoloader_transformclassnametofilename, 0, 0, 2)
	ZEND_ARG_INFO(0, class)
	ZEND_ARG_INFO(0, directory)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_loader_standardautoloader_loadclass, 0, 0, 2)
	ZEND_ARG_INFO(0, class)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_loader_standardautoloader_normalizedirectory, 0, 0, 1)
	ZEND_ARG_INFO(0, directory)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zend_loader_standardautoloader_method_entry) {
	PHP_ME(Zend_Loader_StandardAutoloader, __construct, arginfo_zend_loader_standardautoloader___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zend_Loader_StandardAutoloader, setOptions, arginfo_zend_loader_standardautoloader_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_Loader_StandardAutoloader, setFallbackAutoloader, arginfo_zend_loader_standardautoloader_setfallbackautoloader, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_Loader_StandardAutoloader, isFallbackAutoloader, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_Loader_StandardAutoloader, registerNamespace, arginfo_zend_loader_standardautoloader_registernamespace, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_Loader_StandardAutoloader, registerNamespaces, arginfo_zend_loader_standardautoloader_registernamespaces, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_Loader_StandardAutoloader, registerPrefix, arginfo_zend_loader_standardautoloader_registerprefix, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_Loader_StandardAutoloader, registerPrefixes, arginfo_zend_loader_standardautoloader_registerprefixes, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_Loader_StandardAutoloader, autoload, arginfo_zend_loader_standardautoloader_autoload, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_Loader_StandardAutoloader, register, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_Loader_StandardAutoloader, transformClassNameToFilename, arginfo_zend_loader_standardautoloader_transformclassnametofilename, ZEND_ACC_PROTECTED)
	PHP_ME(Zend_Loader_StandardAutoloader, loadClass, arginfo_zend_loader_standardautoloader_loadclass, ZEND_ACC_PROTECTED)
	PHP_ME(Zend_Loader_StandardAutoloader, normalizeDirectory, arginfo_zend_loader_standardautoloader_normalizedirectory, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
