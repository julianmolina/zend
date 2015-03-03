
extern zend_class_entry *zend_loader_pluginclasslocator_ce;

ZEPHIR_INIT_CLASS(Zend_Loader_PluginClassLocator);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_loader_pluginclasslocator_registerplugin, 0, 0, 2)
	ZEND_ARG_INFO(0, shortName)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_loader_pluginclasslocator_unregisterplugin, 0, 0, 1)
	ZEND_ARG_INFO(0, shortName)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zend_loader_pluginclasslocator_method_entry) {
	PHP_ABSTRACT_ME(Zend_Loader_PluginClassLocator, registerPlugin, arginfo_zend_loader_pluginclasslocator_registerplugin)
	PHP_ABSTRACT_ME(Zend_Loader_PluginClassLocator, unregisterPlugin, arginfo_zend_loader_pluginclasslocator_unregisterplugin)
	PHP_ABSTRACT_ME(Zend_Loader_PluginClassLocator, getRegisteredPlugins, NULL)
  PHP_FE_END
};
