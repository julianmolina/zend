
extern zend_class_entry *zend_loader_pluginclassloader_ce;

ZEPHIR_INIT_CLASS(Zend_Loader_PluginClassLoader);

PHP_METHOD(Zend_Loader_PluginClassLoader, __construct);
PHP_METHOD(Zend_Loader_PluginClassLoader, addStaticMap);
PHP_METHOD(Zend_Loader_PluginClassLoader, registerPlugin);
PHP_METHOD(Zend_Loader_PluginClassLoader, registerPlugins);
PHP_METHOD(Zend_Loader_PluginClassLoader, unregisterPlugin);
PHP_METHOD(Zend_Loader_PluginClassLoader, getRegisteredPlugins);
PHP_METHOD(Zend_Loader_PluginClassLoader, isLoaded);
PHP_METHOD(Zend_Loader_PluginClassLoader, getClassName);
PHP_METHOD(Zend_Loader_PluginClassLoader, load);
PHP_METHOD(Zend_Loader_PluginClassLoader, getIterator);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_loader_pluginclassloader___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, map)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_loader_pluginclassloader_addstaticmap, 0, 0, 1)
	ZEND_ARG_INFO(0, map)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_loader_pluginclassloader_registerplugin, 0, 0, 2)
	ZEND_ARG_INFO(0, shortName)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_loader_pluginclassloader_registerplugins, 0, 0, 1)
	ZEND_ARG_INFO(0, map)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_loader_pluginclassloader_unregisterplugin, 0, 0, 1)
	ZEND_ARG_INFO(0, shortName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_loader_pluginclassloader_isloaded, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_loader_pluginclassloader_getclassname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_loader_pluginclassloader_load, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zend_loader_pluginclassloader_method_entry) {
	PHP_ME(Zend_Loader_PluginClassLoader, __construct, arginfo_zend_loader_pluginclassloader___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zend_Loader_PluginClassLoader, addStaticMap, arginfo_zend_loader_pluginclassloader_addstaticmap, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zend_Loader_PluginClassLoader, registerPlugin, arginfo_zend_loader_pluginclassloader_registerplugin, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_Loader_PluginClassLoader, registerPlugins, arginfo_zend_loader_pluginclassloader_registerplugins, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_Loader_PluginClassLoader, unregisterPlugin, arginfo_zend_loader_pluginclassloader_unregisterplugin, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_Loader_PluginClassLoader, getRegisteredPlugins, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_Loader_PluginClassLoader, isLoaded, arginfo_zend_loader_pluginclassloader_isloaded, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_Loader_PluginClassLoader, getClassName, arginfo_zend_loader_pluginclassloader_getclassname, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_Loader_PluginClassLoader, load, arginfo_zend_loader_pluginclassloader_load, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_Loader_PluginClassLoader, getIterator, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
