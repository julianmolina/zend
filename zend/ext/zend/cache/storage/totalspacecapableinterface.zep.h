
extern zend_class_entry *zend_cache_storage_totalspacecapableinterface_ce;

ZEPHIR_INIT_CLASS(Zend_Cache_Storage_TotalSpaceCapableInterface);

ZEPHIR_INIT_FUNCS(zend_cache_storage_totalspacecapableinterface_method_entry) {
	PHP_ABSTRACT_ME(Zend_Cache_Storage_TotalSpaceCapableInterface, getTotalSpace, NULL)
  PHP_FE_END
};
