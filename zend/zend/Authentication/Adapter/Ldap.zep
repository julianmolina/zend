
/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Zend\Authentication\Adapter;

use stdClass;
use Zend\Authentication\Result as AuthenticationResult;
use Zend\Ldap as ZendLdap;
use Zend\Ldap\Exception\LdapException;

class Ldap extends AbstractAdapter
{

    /**
     * The Zend\Ldap\Ldap context.
     *
     * @var ZendLdap\Ldap
     */
    protected ldap = null;

    /**
     * The array of arrays of Zend\Ldap\Ldap options passed to the constructor.
     *
     * @var array
     */
    protected options = null;

    /**
     * The DN of the authenticated account. Used to retrieve the account entry on request.
     *
     * @var string
     */
    protected authenticatedDn = null;

    /**
     * Constructor
     *
     * @param  array  options    An array of arrays of Zend\Ldap\Ldap options
     * @param  string identity   The username of the account being authenticated
     * @param  string credential The password of the account being authenticated
     */
    public function __construct(array options = array(), identity = null, credential = null)
    {
        this->setOptions(options);
        if identity !== null {
            this->setIdentity(identity);
        }
        if credential !== null {
            this->setCredential(credential);
        }
    }

    /**
     * Returns the array of arrays of Zend\Ldap\Ldap options of this adapter.
     *
     * @return array|null
     */
    public function getOptions()
    {
        return this->options;
    }

    /**
     * Sets the array of arrays of Zend\Ldap\Ldap options to be used by
     * this adapter.
     *
     * @param  array options The array of arrays of Zend\Ldap\Ldap options
     * @return Ldap Provides a fluent interface
     */
    public function setOptions(options)
    {
        let this->options = is_array(options) ? options : [];
        if array_key_exists('identity', this->options) {
            let this->options['username'] = this->options['identity'];
        }
        if (array_key_exists('credential', this->options)) {
            let this->options['password'] = this->options['credential'];
        }
        return this;
    }

    /**
     * Returns the username of the account being authenticated, or
     * NULL if none is set.
     *
     * @return string|null
     */
    public function getUsername()
    {
        return this->getIdentity();
    }

    /**
     * Sets the username for binding
     *
     * @param  string username The username for binding
     * @return Ldap Provides a fluent interface
     */
    public function setUsername(username)
    {
        return this->setIdentity(username);
    }

    /**
     * Returns the password of the account being authenticated, or
     * NULL if none is set.
     *
     * @return string|null
     */
    public function getPassword()
    {
        return this->getCredential();
    }

    /**
     * Sets the password for the account
     *
     * @param  string password The password of the account being authenticated
     * @return Ldap Provides a fluent interface
     */
    public function setPassword(password)
    {
        return this->setCredential(password);
    }

    /**
     * Returns the LDAP Object
     *
     * @return ZendLdap\Ldap The Zend\Ldap\Ldap object used to authenticate the credentials
     */
    public function getLdap()
    {
        if this->ldap === null {
            let this->ldap = new ZendLdap\Ldap();
        }

        return this->ldap;
    }

    /**
     * Set an Ldap connection
     *
     * @param  ZendLdap\Ldap ldap An existing Ldap object
     * @return Ldap Provides a fluent interface
     */
    public function setLdap(ZendLdap\Ldap ldap)
    {
        let this->ldap = ldap;

        this->setOptions([ldap->getOptions()]);

        return this;
    }

    /**
     * Returns a domain name for the current LDAP options. This is used
     * for skipping redundant operations (e.g. authentications).
     *
     * @return string
     */
    protected function getAuthorityName()
    {
        let options = this->getLdap()->getOptions();
        let name = options['accountDomainName'];
        if !name {
            let name = options['accountDomainNameShort'];
        }
        return name ? name : '';
    }

    /**
     * Authenticate the user
     *
     * @return AuthenticationResult
     * @throws Exception\ExceptionInterface
     */
    public function authenticate()
    {
        let messages = [];
        let messages[0] = ''; // reserved
        let messages[1] = ''; // reserved

        let username = this->identity;
        let password = this->credential;

        if !username {
            let code = AuthenticationResult::FAILURE_IDENTITY_NOT_FOUND;
            let messages[0] = 'A username is required';
            return new AuthenticationResult(code, '', messages);
        }
        if !password {
            /* A password is required because some servers will
             * treat an empty password as an anonymous bind.
             */
            let code = AuthenticationResult::FAILURE_CREDENTIAL_INVALID;
            let messages[0] = 'A password is required';
            return new AuthenticationResult(code, '', messages);
        }

        let ldap = this->getLdap();

        let code = AuthenticationResult::FAILURE;
        let messages[0] = "Authority not found: username";
        let failedAuthorities = [];

        /* Iterate through each server and try to authenticate the supplied
         * credentials against it.
         */
        for options in this->options {

            if !is_array(options) {
                throw new Exception\InvalidArgumentException('Adapter options array not an array');
            }
            let adapterOptions = this->prepareOptions(ldap, options);
            let dname = '';

            try {

                if messages[1]
                    messages[] = messages[1];
                let messages[1] = '';
                let messages[] = this->optionsToString(options);

                let dname = this->getAuthorityName();
                if isset(failedAuthorities[dname]) {
                    /* If multiple sets of server options for the same domain
                     * are supplied, we want to skip redundant authentications
                     * where the identity or credentials where found to be
                     * invalid with another server for the same domain. The
                     * failedAuthorities array tracks this condition (and also
                     * serves to supply the original error message).
                     * This fixes issue ZF-4093.
                     */
                    let messages[1] = failedAuthorities[dname];
                    let messages[] = "Skipping previously failed authority: dname";
                    continue;
                }

                let canonicalName = ldap->getCanonicalAccountName(username);
                let ldap->bind(canonicalName, password);
                /*
                 * Fixes problem when authenticated user is not allowed to retrieve
                 * group-membership information or own account.
                 * This requires that the user specified with "username" and optionally
                 * "password" in the Zend\Ldap\Ldap options is able to retrieve the required
                 * information.
                 */
                let requireRebind = false;
                if isset(options['username']) {
                    ldap->bind();
                    let requireRebind = true;
                }
                let dn = ldap->getCanonicalAccountName(canonicalName, ZendLdap\Ldap::ACCTNAME_FORM_DN);

                let groupResult = this->checkGroupMembership(ldap, canonicalName, dn, adapterOptions);
                if groupResult === true {
                    let this->authenticatedDn = dn;
                    let messages[0] = '';
                    let messages[1] = '';
                    let messages[] = "canonicalName authentication successful";
                    if requireRebind === true {
                        // rebinding with authenticated user
                        ldap->bind(dn, password);
                    }
                    return new AuthenticationResult(AuthenticationResult::SUCCESS, canonicalName, messages);
                } else {
                    let messages[0] = 'Account is not a member of the specified group';
                    let messages[1] = groupResult;
                    let failedAuthorities[dname] = groupResult;
                }
            } catch (LdapException zle) {

                /* LDAP based authentication is notoriously difficult to diagnose. Therefore
                 * we bend over backwards to capture and record every possible bit of
                 * information when something goes wrong.
                 */

                let err = zle->getCode();

                if err == LdapException::LDAP_X_DOMAIN_MISMATCH {
                    /* This error indicates that the domain supplied in the
                     * username did not match the domains in the server options
                     * and therefore we should just skip to the next set of
                     * server options.
                     */
                    continue;
                } elseif err == LdapException::LDAP_NO_SUCH_OBJECT {
                    let code = AuthenticationResult::FAILURE_IDENTITY_NOT_FOUND;
                    let messages[0] = "Account not found: username";
                    let failedAuthorities[dname] = zle->getMessage();
                } elseif err == LdapException::LDAP_INVALID_CREDENTIALS {
                    let code = AuthenticationResult::FAILURE_CREDENTIAL_INVALID;
                    let messages[0] = 'Invalid credentials';
                    let failedAuthorities[dname] = zle->getMessage();
                } else {
                    let line = zle->getLine();
                    let messages[] = zle->getFile() . "(line): " . zle->getMessage();
                    let messages[] = preg_replace(
                        '/\b'.preg_quote(substr(password, 0, 15), '/').'\b/',
                        '*****',
                        zle->getTraceAsString()
                    );
                    let messages[0] = 'An unexpected failure occurred';
                }
                let messages[1] = zle->getMessage();
            }
        }

        let msg = isset(messages[1]) ? messages[1] : messages[0];
        let messages[] = "username authentication failed: msg";

        return new AuthenticationResult(code, username, messages);
    }

    /**
     * Sets the LDAP specific options on the Zend\Ldap\Ldap instance
     *
     * @param  ZendLdap\Ldap ldap
     * @param  array         options
     * @return array of auth-adapter specific options
     */
    protected function prepareOptions(ZendLdap\Ldap ldap, array options)
    {
        let adapterOptions = [
            'group'       : null,
            'groupDn'     : ldap->getBaseDn(),
            'groupScope'  : ZendLdap\Ldap::SEARCH_SCOPE_SUB,
            'groupAttr'   : 'cn',
            'groupFilter' : 'objectClass=groupOfUniqueNames',
            'memberAttr'  : 'uniqueMember',
            'memberIsDn'  : true
        ];
        for key, value in adapterOptions {
            if array_key_exists(key, options) {
                let value = options[key];
                unset(options[key]);
                switch key {
                    case 'groupScope':
                        let value = (int) value;
                        if in_array(value, array(ZendLdap\Ldap::SEARCH_SCOPE_BASE,
                                ZendLdap\Ldap::SEARCH_SCOPE_ONE, ZendLdap\Ldap::SEARCH_SCOPE_SUB), true) {
                           let adapterOptions[key] = value;
                        }
                        break;
                    case 'memberIsDn':
                        let adapterOptions[key] = (value === true ||
                                value === '1' || strcasecmp(value, 'true') == 0);
                        break;
                    default:
                        let adapterOptions[key] = trim(value);
                        break;
                }
            }
        }
        ldap->setOptions(options);
        return adapterOptions;
    }

    /**
     * Checks the group membership of the bound user
     *
     * @param  ZendLdap\Ldap ldap
     * @param  string        canonicalName
     * @param  string        dn
     * @param  array         adapterOptions
     * @return string|true
     */
    protected function checkGroupMembership(ZendLdap\Ldap ldap, canonicalName, dn, array adapterOptions)
    {
        if adapterOptions['group'] === null {
            return true;
        }

        if adapterOptions['memberIsDn'] === false {
            let user = canonicalName;
        } else {
            let user = dn;
        }

        let groupName   = ZendLdap\Filter::equals(adapterOptions['groupAttr'], adapterOptions['group']);
        let membership  = ZendLdap\Filter::equals(adapterOptions['memberAttr'], user);
        let group       = ZendLdap\Filter::andFilter(groupName, membership);
        let groupFilter = adapterOptions['groupFilter'];
        if !empty groupFilter {
            let group = group->addAnd(groupFilter);
        }

        let result = ldap->count(group, adapterOptions['groupDn'], adapterOptions['groupScope']);

        if result === 1 {
            return true;
        }

        return 'Failed to verify group membership with ' . group->toString();
    }

    /**
     * getAccountObject() - Returns the result entry as a stdClass object
     *
     * This resembles the feature {@see Zend\Authentication\Adapter\DbTable::getResultRowObject()}.
     * Closes ZF-6813
     *
     * @param  array returnAttribs
     * @param  array omitAttribs
     * @return stdClass|bool
     */
    public function getAccountObject(array returnAttribs = [], array omitAttribs = []])
    {
        if !this->authenticatedDn {
            return false;
        }

        let returnObject = new stdClass();

        let returnAttribs = array_map('strtolower', returnAttribs);
        let omitAttribs   = array_map('strtolower', omitAttribs);
        let returnAttribs = array_diff(returnAttribs, omitAttribs);

        let entry = this->getLdap()->getEntry(this->authenticatedDn, returnAttribs, true);
        for attr, value in entry {
            if in_array(attr, omitAttribs) {
                // skip attributes marked to be omitted
                continue;
            }
            if is_array(value) {
                let returnObject->attr = (count(value) > 1) ? value : value[0];
            } else {
                let returnObject->attr = value;
            }
        }
        return returnObject;
    }

    /**
     * Converts options to string
     *
     * @param  array options
     * @return string
     */
    private function optionsToString(array options)
    {
        let str = '';
        for key, val in options {
            if key === 'password' || key === 'credential' {
                val = '*****';
            }
            if str {
                str .= ',';
            }
            let str .= key . '=' . val;
        }
        return str;
    }
}
