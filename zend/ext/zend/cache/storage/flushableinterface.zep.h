
extern zend_class_entry *zend_cache_storage_flushableinterface_ce;

ZEPHIR_INIT_CLASS(Zend_Cache_Storage_FlushableInterface);

ZEPHIR_INIT_FUNCS(zend_cache_storage_flushableinterface_method_entry) {
	PHP_ABSTRACT_ME(Zend_Cache_Storage_FlushableInterface, flush, NULL)
  PHP_FE_END
};
