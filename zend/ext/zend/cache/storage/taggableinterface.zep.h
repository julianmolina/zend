
extern zend_class_entry *zend_cache_storage_taggableinterface_ce;

ZEPHIR_INIT_CLASS(Zend_Cache_Storage_TaggableInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_cache_storage_taggableinterface_settags, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_ARRAY_INFO(0, tags, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_cache_storage_taggableinterface_gettags, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_cache_storage_taggableinterface_clearbytags, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, tags, 0)
	ZEND_ARG_INFO(0, disjunction)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zend_cache_storage_taggableinterface_method_entry) {
	PHP_ABSTRACT_ME(Zend_Cache_Storage_TaggableInterface, setTags, arginfo_zend_cache_storage_taggableinterface_settags)
	PHP_ABSTRACT_ME(Zend_Cache_Storage_TaggableInterface, getTags, arginfo_zend_cache_storage_taggableinterface_gettags)
	PHP_ABSTRACT_ME(Zend_Cache_Storage_TaggableInterface, clearByTags, arginfo_zend_cache_storage_taggableinterface_clearbytags)
  PHP_FE_END
};
