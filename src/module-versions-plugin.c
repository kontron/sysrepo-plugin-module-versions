#include <errno.h>
#include <syslog.h>
#include <string.h>
#include <sys/stat.h>

#include <sysrepo.h>
#include <sysrepo/plugins.h>
#include <sysrepo/values.h>
#include <sysrepo/xpath.h>

/*******************************************************************************/
int modvers_dataprovider_cb(const char *xpath, sr_val_t **values, size_t *values_cnt,
                                   uint64_t request_id, const char *original_xpath, void *private_ctx) {
    sr_val_t *v = NULL;
    int rc = SR_ERR_OK;

    if (sr_xpath_node_name_eq(xpath, "module")) {
        int fields = 0;
        int fields_max = 200;
        rc = sr_new_values(fields_max, &v);
        if (SR_ERR_OK != rc) return rc;

/* 
    <module>
      <name>ietf-interfaces</name>
      <revision>2018-02-20</revision>
      <source>github</source>
      <commit_id>6a93b0d09590c5631a776104a96929033cbb81e7</commit_id>
      <internal_version>1.6.0</internal_version>
      <developer_change>Statement "yang-version 1.1" commented.</developer_change>
      <developer_change>Statement "if-feature" commented.</developer_change>
      <developer_change>Statement "default" commented for all leafs with default value.</developer_change>
    </module>
 */

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/revision", "ietf-interfaces");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "2018-02-20");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/source", "ietf-interfaces");
        sr_val_set_str_data(&v[fields++], SR_ENUM_T, "github");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/commit_id", "ietf-interfaces");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "6a93b0d09590c5631a776104a96929033cbb81e7");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/internal_version", "ietf-interfaces");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "1.6.0");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ietf-interfaces");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"yang-version 1.1\" commented.");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ietf-interfaces");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"if-feature\" commented.");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ietf-interfaces");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"default\" commented for all leafs with default value.");

/* 
    <module>
      <name>ieee802-dot1q-bridge</name>
      <revision>2018-03-07</revision>
      <source>github</source>
      <commit_id>64004240ab0410f4b23201d7e722ac552763c709</commit_id>
      <internal_version>1.6.0</internal_version>
      <developer_change>The prefix of iana-if-type.yang module is modified to "ianaift". The old prefix was "ianaif".</developer_change>
      <developer_change>The prefix of ieee802-dot1q-types.yang module is modified to "dot1q-types". The old prefix was "dot1qtypes".</developer_change>
      <developer_change>Statement "if-feature" commented from leaf 'mac-address-registration-entries'.</developer_change>
      <developer_change>"config false" added to the list /bridge-vlan/vlan.</developer_change>
      <developer_change>The grouping "traffic-class-table-grouping" modified.</developer_change>
      <developer_change>Statement "default" commented for all leafs with default value.</developer_change>
    </module>
 */

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/revision", "ieee802-dot1q-bridge");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "2018-03-07");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/source", "ieee802-dot1q-bridge");
        sr_val_set_str_data(&v[fields++], SR_ENUM_T, "github");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/commit_id", "ieee802-dot1q-bridge");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "64004240ab0410f4b23201d7e722ac552763c709");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/internal_version", "ieee802-dot1q-bridge");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "1.6.0");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1q-bridge");
//        sr_val_set_str_data(&v[fields++], SR_STRING_T, "The prefix of iana-if-type.yang module is modified to \"ianaift\".");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "The prefix of iana-if-type.yang module is modified to \"ianaift\". The old prefix was \"ianaif\".");

// if ( 0 > 1 ) {
        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1q-bridge");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "The prefix of ieee802-dot1q-types.yang module is modified to \"dot1q-types\". The old prefix was \"dot1qtypes\".");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1q-bridge");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"if-feature\" commented from leaf 'mac-address-registration-entries'.");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1q-bridge");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "\"config false\" added to the list /bridge-vlan/vlan.");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1q-bridge");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "The grouping \"traffic-class-table-grouping\" modified.");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1q-bridge");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"default\" commented for all leafs with default value.");

/* 
    <module>
      <name>ieee802-dot1q-preemption</name>
      <revision>2018-09-10</revision>
      <source>github</source>
      <commit_id>b8678ee9472189361b56899d4debd703102f7564</commit_id>
      <internal_version>1.6.0</internal_version>
      <developer_change>Statement "if-feature" commented.</developer_change>
    </module>
 */

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/revision", "ieee802-dot1q-preemption");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "2018-09-10");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/source", "ieee802-dot1q-preemption");
        sr_val_set_str_data(&v[fields++], SR_ENUM_T, "github");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/commit_id", "ieee802-dot1q-preemption");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "b8678ee9472189361b56899d4debd703102f7564");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/internal_version", "ieee802-dot1q-preemption");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "1.6.0");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1q-preemption");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"if-feature\" commented.");

/* 
    <module>
      <name>ieee802-dot1q-preempt</name>
      <revision>2018-03-29</revision>
      <source>proprietary</source>
      <internal_version>1.6.0</internal_version>
      <developer_change>Statement "if-feature" commented.</developer_change>
      <developer_change>Statement "default" commented for all leafs with default value.</developer_change>
    </module>
 */

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/revision", "ieee802-dot1q-preempt");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "2018-03-29");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/source", "ieee802-dot1q-preempt");
        sr_val_set_str_data(&v[fields++], SR_ENUM_T, "proprietary");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/internal_version", "ieee802-dot1q-preempt");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "1.6.0");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1q-preempt");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"if-feature\" commented.");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1q-preempt");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"default\" commented for all leafs with default value.");

/* 
    <module>
      <name>ieee802-dot1q-sched</name>
      <revision>2018-09-10</revision>
      <source>github</source>
      <commit_id>b8678ee9472189361b56899d4debd703102f7564</commit_id>
      <internal_version>1.6.0</internal_version>
      <developer_change>Statement "if-feature" commented.</developer_change>
      <developer_change>Import ieee802-dot1q-preemption commented because the preemption is not used in sched module when "if-feature" is commented.</developer_change>
      <developer_change>Statement "default" commented for all leafs with default value.</developer_change>
    </module>
 */

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/revision", "ieee802-dot1q-sched");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "2018-09-10");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/source", "ieee802-dot1q-sched");
        sr_val_set_str_data(&v[fields++], SR_ENUM_T, "github");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/commit_id", "ieee802-dot1q-sched");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "b8678ee9472189361b56899d4debd703102f7564");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/internal_version", "ieee802-dot1q-sched");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "1.6.0");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1q-sched");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"if-feature\" commented.");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1q-sched");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "Import ieee802-dot1q-preemption commented because the preemption is not used in sched module when \"if-feature\" is commented.");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1q-sched");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"default\" commented for all leafs with default value.");

/* 
    <module>
      <name>ieee802-ethernet-interface</name>
      <source>github</source>
      <commit_id>64004240ab0410f4b23201d7e722ac552763c709</commit_id>
      <internal_version>1.6.0</internal_version>
      <developer_change>Statement "yang-version 1.1" commented.</developer_change>
      <developer_change>Statement "if-feature" commented.</developer_change>
      <developer_change>Statement "derived-from-or-self" in 'when' commented and replace with regular 'when'.</developer_change>
      <developer_change>Statement "reference" commented at modules imports.</developer_change>
      <developer_change>Statement "default" commented for all leafs with default value.</developer_change>
    </module>
 */

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/source", "ieee802-ethernet-interface");
        sr_val_set_str_data(&v[fields++], SR_ENUM_T, "github");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/commit_id", "ieee802-ethernet-interface");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "64004240ab0410f4b23201d7e722ac552763c709");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/internal_version", "ieee802-ethernet-interface");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "1.6.0");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-ethernet-interface");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"yang-version 1.1\" commented.");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-ethernet-interface");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"if-feature\" commented.");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-ethernet-interface");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"derived-from-or-self\" in 'when' commented and replace with regular 'when'.");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-ethernet-interface");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"reference\" commented at modules imports.");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-ethernet-interface");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"default\" commented for all leafs with default value.");

/* 
    <module>
      <name>ieee802-dot1ab-lldp</name>
      <revision>2018-11-11</revision>
      <source>github</source>
      <commit_id>64004240ab0410f4b23201d7e722ac552763c709</commit_id>
      <internal_version>1.6.0</internal_version>
      <developer_change>Statement "yang-version 1.1" commented.</developer_change>
      <developer_change>Type of the leaf port/name changed to string.</developer_change>
      <developer_change>Statement "default" commented for all leafs with default value.</developer_change>
    </module>
 */

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/revision", "ieee802-dot1ab-lldp");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "2018-11-11");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/source", "ieee802-dot1ab-lldp");
        sr_val_set_str_data(&v[fields++], SR_ENUM_T, "github");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/commit_id", "ieee802-dot1ab-lldp");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "64004240ab0410f4b23201d7e722ac552763c709");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/internal_version", "ieee802-dot1ab-lldp");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "1.6.0");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1ab-lldp");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"yang-version 1.1\" commented.");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1ab-lldp");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "Type of the leaf port/name changed to string.");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1ab-lldp");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"default\" commented for all leafs with default value.");

/* 
    <module>
      <name>ieee802-dot1q-fqtss</name>
      <revision>2011-02-27</revision>
      <source>fromMIB</source>
      <internal_version>1.6.0</internal_version>
      <developer_change>YANG generated from MIB.</developer_change>
      <developer_change>ieee8021BridgeBaseComponentId and ieee8021BridgeBasePort objects are manualy added to yang module.</developer_change>
    </module>
 */

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/revision", "ieee802-dot1q-fqtss");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "2011-02-27");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/source", "ieee802-dot1q-fqtss");
        sr_val_set_str_data(&v[fields++], SR_ENUM_T, "fromMIB");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/internal_version", "ieee802-dot1q-fqtss");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "1.6.0");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1q-fqtss");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "YANG generated from MIB.");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1q-fqtss");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "ieee8021BridgeBaseComponentId and ieee8021BridgeBasePort objects are manualy added to yang module.");

/* 
    <module>
      <name>ieee8021-mstp</name>
      <revision>2012-08-10</revision>
      <source>fromMIB</source>
      <internal_version>1.6.0</internal_version>
      <developer_change>YANG generated from MIB.</developer_change>
      <developer_change>Leafs ieee8021MstpBridgePriority and ieee8021MstpPortPriority are modified and they have limmited values in range 0-15.</developer_change>
      <developer_change>Import of SNMPv2-TC commented.</developer_change>
      <developer_change>Unimplemented objects commented.</developer_change>
      <developer_change>ieee8021MstpCistPortRole type modified: enum "disabled" added.</developer_change>
      <developer_change>ieee8021MstpPortState type modified: enum "discarding" added.</developer_change>
      <developer_change>ieee8021MstpPortRole type modified: enum "disabled" added.</developer_change>
    </module>
 */

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/revision", "ieee8021-mstp");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "2012-08-10");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/source", "ieee8021-mstp");
        sr_val_set_str_data(&v[fields++], SR_ENUM_T, "fromMIB");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/internal_version", "ieee8021-mstp");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "1.6.0");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee8021-mstp");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "YANG generated from MIB.");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee8021-mstp");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "Leafs ieee8021MstpBridgePriority and ieee8021MstpPortPriority are modified and they have limmited values in range 0-15.");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee8021-mstp");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "Import of SNMPv2-TC commented.");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee8021-mstp");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "Unimplemented objects commented.");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee8021-mstp");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "ieee8021MstpCistPortRole type modified: enum \"disabled\" added.");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee8021-mstp");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "ieee8021MstpPortState type modified: enum \"discarding\" added.");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee8021-mstp");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "ieee8021MstpPortRole type modified: enum \"disabled\" added.");

/* 
    <module>
      <name>ieee8021-spanning-tree</name>
      <revision>2011-03-24</revision>
      <source>fromMIB</source>
      <internal_version>1.6.0</internal_version>
      <developer_change>YANG generated from MIB.</developer_change>
    </module>
 */

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/revision", "ieee8021-spanning-tree");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "2011-03-24");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/source", "ieee8021-spanning-tree");
        sr_val_set_str_data(&v[fields++], SR_ENUM_T, "fromMIB");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/internal_version", "ieee8021-spanning-tree");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "1.6.0");

        sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee8021-spanning-tree");
        sr_val_set_str_data(&v[fields++], SR_STRING_T, "YANG generated from MIB.");

// }

        *values = v;
        *values_cnt = fields;


    } else {
        printf("GENERAL XP: %s\n", xpath);

        *values = NULL;
        values_cnt = 0;
    }

    return SR_ERR_OK;
}

/* Registers for providing of operational data under given xpath. */
int sr_plugin_init_cb(sr_session_ctx_t *session, void **private_ctx) {
    sr_subscription_ctx_t *subscription = NULL;
    sr_subscription_ctx_t *subscription_oper = NULL;
    int rc = SR_ERR_OK;

    // operational data
    rc = sr_dp_get_items_subscribe(session, "/module-versions:module-versions", modvers_dataprovider_cb, NULL, SR_SUBSCR_DEFAULT, &subscription_oper);
    if (SR_ERR_OK != rc) goto error;

    syslog(LOG_DEBUG, "plugin initialized successfully.");

    /* set subscription as our private context */
    // how to preserve both of them?
    *private_ctx = subscription;

    return SR_ERR_OK;

error:
    syslog(LOG_ERR, "plugin initialization failed: %s", sr_strerror(rc));
    if (subscription != NULL) sr_unsubscribe(session, subscription);
    if (subscription_oper != NULL) sr_unsubscribe(session, subscription_oper);
    return rc;
}

void sr_plugin_cleanup_cb(sr_session_ctx_t *session, void *private_ctx) {
    /* subscription was set as our private context */
    sr_unsubscribe(session, (sr_subscription_ctx_t *)private_ctx);
    syslog(LOG_DEBUG, "plugin cleanup finished");
}
