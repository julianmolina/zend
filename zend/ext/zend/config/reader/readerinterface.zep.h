
extern zend_class_entry *zend_config_reader_readerinterface_ce;

ZEPHIR_INIT_CLASS(Zend_Config_Reader_ReaderInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_config_reader_readerinterface_fromfile, 0, 0, 1)
	ZEND_ARG_INFO(0, filename)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_config_reader_readerinterface_fromstring, 0, 0, 1)
	ZEND_ARG_INFO(0, string)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zend_config_reader_readerinterface_method_entry) {
	PHP_ABSTRACT_ME(Zend_Config_Reader_ReaderInterface, fromFile, arginfo_zend_config_reader_readerinterface_fromfile)
	PHP_ABSTRACT_ME(Zend_Config_Reader_ReaderInterface, fromString, arginfo_zend_config_reader_readerinterface_fromstring)
  PHP_FE_END
};
