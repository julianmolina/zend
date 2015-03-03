
extern zend_class_entry *zend_ldap_exception_ldapexception_ce;

ZEPHIR_INIT_CLASS(Zend_Ldap_Exception_LdapException);

PHP_METHOD(Zend_Ldap_Exception_LdapException, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_ldap_exception_ldapexception___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, ldap)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, code)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zend_ldap_exception_ldapexception_method_entry) {
	PHP_ME(Zend_Ldap_Exception_LdapException, __construct, arginfo_zend_ldap_exception_ldapexception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
