#include <errno.h>
#include <syslog.h>
#include <string.h>
#include <sys/stat.h>

#include <sysrepo.h>
// #include <sysrepo/plugins.h>
#include <sysrepo/values.h>
#include <sysrepo/xpath.h>
#include <libyang/libyang.h>

/* session of our plugin, can be used until cleanup is called */
    sr_session_ctx_t *sess;

/*******************************************************************************/

// int modvers_dataprovider_cb(const char *xpath, sr_val_t **values, size_t *values_cnt,
//                                    uint64_t request_id, const char *original_xpath, void *private_ctx) {

int modvers_dataprovider_cb(sr_session_ctx_t *session, const char *module_name, const char *path, const char *request_xpath,
                                   uint32_t request_id, struct lyd_node **parent, void *private_data) {
    // sr_val_t *v = NULL;
    // int rc = SR_ERR_OK;
    int rc;

    (void)session;
    (void)module_name;
    (void)path;
    (void)request_xpath;
    (void)request_id;
    (void)private_data;

if ( 0 > 1 ) {
    printf("module_name:   \"%s\"\n", module_name);
    printf("path:          \"%s\"\n", path);
    printf("request_xpath: \"%s\"\n", request_xpath);

    rc = sr_xpath_node_name_eq(request_xpath, "module");
    printf("rc: %d, \"%s\"\n", rc, "module");

    rc = sr_xpath_node_name_eq(request_xpath, "module-versions");
    printf("rc: %d, \"%s\"\n", rc, "module-versions");
    
    rc = sr_xpath_node_name_eq(request_xpath, "/module-versions");
    printf("rc: %d, \"%s\"\n", rc, "/module-versions");
    
    rc = sr_xpath_node_name_eq(request_xpath, "module-versions:module-versions");
    printf("rc: %d, \"%s\"\n", rc, "module-versions:module-versions");
    
    rc = sr_xpath_node_name_eq(request_xpath, "/module-versions:module-versions");
    printf("rc: %d, \"%s\"\n", rc, "/module-versions:module-versions");
    
    rc = sr_xpath_node_name_eq(request_xpath, "*");
    printf("rc: %d, \"%s\"\n", rc, "*");
    
    // if (sr_xpath_node_name_eq(path, "module")) {
}

    if (sr_xpath_node_name_eq(request_xpath, "*") ||
        (strcmp(path, "/module-versions:module-versions") == 0)) {
        // int fields = 0;
        // int fields_max = 200;

if ( 0 > 1 ) {
// Templates:
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='MODNAME']/revision", "", 0, 0);
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='MODNAME']/source", "github", 0, 0);
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='MODNAME']/commit_id", "", 0, 0);
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='MODNAME']/internal_version", "1.6.0", 0, 0);
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='MODNAME']/developer_change", "", 0, 0);
}

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

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/revision", "ietf-interfaces");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "2018-02-20");

        *parent = lyd_new_path(NULL, sr_get_context(sr_session_get_connection(sess)), "/module-versions:module-versions/module[name='ietf-interfaces']/revision", "2018-02-20", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/source", "ietf-interfaces");
        // sr_val_set_str_data(&v[fields++], SR_ENUM_T, "github");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ietf-interfaces']/source", "github", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/commit_id", "ietf-interfaces");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "6a93b0d09590c5631a776104a96929033cbb81e7");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ietf-interfaces']/commit_id", "6a93b0d09590c5631a776104a96929033cbb81e7", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/internal_version", "ietf-interfaces");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "1.6.0");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ietf-interfaces']/internal_version", "1.6.0", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ietf-interfaces");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"yang-version 1.1\" commented.");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ietf-interfaces']/developer_change", "Statement \"yang-version 1.1\" commented.", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ietf-interfaces");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"if-feature\" commented.");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ietf-interfaces']/developer_change", "Statement \"if-feature\" commented.", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ietf-interfaces");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"default\" commented for all leafs with default value.");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ietf-interfaces']/developer_change", "Statement \"default\" commented for all leafs with default value.", 0, 0);

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

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/revision", "ieee802-dot1q-bridge");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "2018-03-07");

        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1q-bridge']/revision", "2018-03-07", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/source", "ieee802-dot1q-bridge");
        // sr_val_set_str_data(&v[fields++], SR_ENUM_T, "github");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1q-bridge']/source", "github", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/commit_id", "ieee802-dot1q-bridge");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "64004240ab0410f4b23201d7e722ac552763c709");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1q-bridge']/commit_id", "64004240ab0410f4b23201d7e722ac552763c709", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/internal_version", "ieee802-dot1q-bridge");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "1.6.0");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1q-bridge']/internal_version", "1.6.0", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1q-bridge");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "The prefix of iana-if-type.yang module is modified to \"ianaift\". The old prefix was \"ianaif\".");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1q-bridge']/developer_change", "The prefix of iana-if-type.yang module is modified to \"ianaift\". The old prefix was \"ianaif\".", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1q-bridge");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "The prefix of ieee802-dot1q-types.yang module is modified to \"dot1q-types\". The old prefix was \"dot1qtypes\".");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1q-bridge']/developer_change", "The prefix of ieee802-dot1q-types.yang module is modified to \"dot1q-types\". The old prefix was \"dot1qtypes\".", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1q-bridge");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"if-feature\" commented from leaf 'mac-address-registration-entries'.");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1q-bridge']/developer_change", "Statement \"if-feature\" commented from leaf 'mac-address-registration-entries'.", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1q-bridge");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "\"config false\" added to the list /bridge-vlan/vlan.");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1q-bridge']/developer_change", "\"config false\" added to the list /bridge-vlan/vlan.", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1q-bridge");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "The grouping \"traffic-class-table-grouping\" modified.");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1q-bridge']/developer_change", "The grouping \"traffic-class-table-grouping\" modified.", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1q-bridge");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"default\" commented for all leafs with default value.");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1q-bridge']/developer_change", "Statement \"default\" commented for all leafs with default value.", 0, 0);

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

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/revision", "ieee802-dot1q-preemption");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "2018-09-10");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1q-preemption']/revision", "2018-09-10", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/source", "ieee802-dot1q-preemption");
        // sr_val_set_str_data(&v[fields++], SR_ENUM_T, "github");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1q-preemption']/source", "github", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/commit_id", "ieee802-dot1q-preemption");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "b8678ee9472189361b56899d4debd703102f7564");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1q-preemption']/commit_id", "b8678ee9472189361b56899d4debd703102f7564", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/internal_version", "ieee802-dot1q-preemption");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "1.6.0");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1q-preemption']/internal_version", "1.6.0", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1q-preemption");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"if-feature\" commented.");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1q-preemption']/developer_change", "Statement \"if-feature\" commented.", 0, 0);

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

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/revision", "ieee802-dot1q-preempt");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "2018-03-29");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1q-preempt']/revision", "2018-03-29", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/source", "ieee802-dot1q-preempt");
        // sr_val_set_str_data(&v[fields++], SR_ENUM_T, "proprietary");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1q-preempt']/source", "proprietary", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/internal_version", "ieee802-dot1q-preempt");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "1.6.0");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1q-preempt']/internal_version", "1.6.0", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1q-preempt");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"if-feature\" commented.");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1q-preempt']/developer_change", "Statement \"if-feature\" commented.", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1q-preempt");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"default\" commented for all leafs with default value.");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1q-preempt']/developer_change", "Statement \"default\" commented for all leafs with default value.", 0, 0);

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

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/revision", "ieee802-dot1q-sched");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "2018-09-10");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1q-sched']/revision", "2018-09-10", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/source", "ieee802-dot1q-sched");
        // sr_val_set_str_data(&v[fields++], SR_ENUM_T, "github");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1q-sched']/source", "github", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/commit_id", "ieee802-dot1q-sched");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "b8678ee9472189361b56899d4debd703102f7564");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1q-sched']/commit_id", "b8678ee9472189361b56899d4debd703102f7564", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/internal_version", "ieee802-dot1q-sched");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "1.6.0");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1q-sched']/internal_version", "1.6.0", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1q-sched");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"if-feature\" commented.");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1q-sched']/developer_change", "Statement \"if-feature\" commented.", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1q-sched");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "Import ieee802-dot1q-preemption commented because the preemption is not used in sched module when \"if-feature\" is commented.");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1q-sched']/developer_change", "Import ieee802-dot1q-preemption commented because the preemption is not used in sched module when \"if-feature\" is commented.", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1q-sched");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"default\" commented for all leafs with default value.");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1q-sched']/developer_change", "Statement \"default\" commented for all leafs with default value.", 0, 0);

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

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/source", "ieee802-ethernet-interface");
        // sr_val_set_str_data(&v[fields++], SR_ENUM_T, "github");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-ethernet-interface']/source", "github", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/commit_id", "ieee802-ethernet-interface");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "64004240ab0410f4b23201d7e722ac552763c709");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-ethernet-interface']/commit_id", "64004240ab0410f4b23201d7e722ac552763c709", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/internal_version", "ieee802-ethernet-interface");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "1.6.0");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-ethernet-interface']/internal_version", "1.6.0", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-ethernet-interface");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"yang-version 1.1\" commented.");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-ethernet-interface']/developer_change", "Statement \"yang-version 1.1\" commented.", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-ethernet-interface");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"if-feature\" commented.");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-ethernet-interface']/developer_change", "Statement \"if-feature\" commented.", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-ethernet-interface");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"derived-from-or-self\" in 'when' commented and replace with regular 'when'.");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-ethernet-interface']/developer_change", "Statement \"derived-from-or-self\" in 'when' commented and replace with regular 'when'.", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-ethernet-interface");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"reference\" commented at modules imports.");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-ethernet-interface']/developer_change", "Statement \"reference\" commented at modules imports.", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-ethernet-interface");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"default\" commented for all leafs with default value.");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-ethernet-interface']/developer_change", "Statement \"default\" commented for all leafs with default value.", 0, 0);

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

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/revision", "ieee802-dot1ab-lldp");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "2018-11-11");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1ab-lldp']/revision", "2018-11-11", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/source", "ieee802-dot1ab-lldp");
        // sr_val_set_str_data(&v[fields++], SR_ENUM_T, "github");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1ab-lldp']/source", "github", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/commit_id", "ieee802-dot1ab-lldp");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "64004240ab0410f4b23201d7e722ac552763c709");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1ab-lldp']/commit_id", "64004240ab0410f4b23201d7e722ac552763c709", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/internal_version", "ieee802-dot1ab-lldp");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "1.6.0");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1ab-lldp']/internal_version", "1.6.0", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1ab-lldp");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"yang-version 1.1\" commented.");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1ab-lldp']/developer_change", "Statement \"yang-version 1.1\" commented.", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1ab-lldp");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "Type of the leaf port/name changed to string.");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1ab-lldp']/developer_change", "Type of the leaf port/name changed to string.", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1ab-lldp");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "Statement \"default\" commented for all leafs with default value.");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1ab-lldp']/developer_change", "Statement \"default\" commented for all leafs with default value.", 0, 0);

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

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/revision", "ieee802-dot1q-fqtss");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "2011-02-27");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1q-fqtss']/revision", "2011-02-27", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/source", "ieee802-dot1q-fqtss");
        // sr_val_set_str_data(&v[fields++], SR_ENUM_T, "fromMIB");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1q-fqtss']/source", "fromMIB", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/internal_version", "ieee802-dot1q-fqtss");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "1.6.0");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1q-fqtss']/internal_version", "1.6.0", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1q-fqtss");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "YANG generated from MIB.");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1q-fqtss']/developer_change", "YANG generated from MIB.", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee802-dot1q-fqtss");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "ieee8021BridgeBaseComponentId and ieee8021BridgeBasePort objects are manualy added to yang module.");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee802-dot1q-fqtss']/developer_change", "ieee8021BridgeBaseComponentId and ieee8021BridgeBasePort objects are manualy added to yang module.", 0, 0);

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

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/revision", "ieee8021-mstp");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "2012-08-10");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee8021-mstp']/revision", "2012-08-10", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/source", "ieee8021-mstp");
        // sr_val_set_str_data(&v[fields++], SR_ENUM_T, "fromMIB");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee8021-mstp']/source", "fromMIB", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/internal_version", "ieee8021-mstp");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "1.6.0");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee8021-mstp']/internal_version", "1.6.0", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee8021-mstp");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "YANG generated from MIB.");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee8021-mstp']/developer_change", "YANG generated from MIB.", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee8021-mstp");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "Leafs ieee8021MstpBridgePriority and ieee8021MstpPortPriority are modified and they have limmited values in range 0-15.");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee8021-mstp']/developer_change", "Leafs ieee8021MstpBridgePriority and ieee8021MstpPortPriority are modified and they have limmited values in range 0-15.", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee8021-mstp");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "Import of SNMPv2-TC commented.");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee8021-mstp']/developer_change", "Import of SNMPv2-TC commented.", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee8021-mstp");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "Unimplemented objects commented.");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee8021-mstp']/developer_change", "Unimplemented objects commented.", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee8021-mstp");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "ieee8021MstpCistPortRole type modified: enum \"disabled\" added.");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee8021-mstp']/developer_change", "ieee8021MstpCistPortRole type modified: enum \"disabled\" added.", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee8021-mstp");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "ieee8021MstpPortState type modified: enum \"discarding\" added.");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee8021-mstp']/developer_change", "ieee8021MstpPortState type modified: enum \"discarding\" added.", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee8021-mstp");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "ieee8021MstpPortRole type modified: enum \"disabled\" added.");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee8021-mstp']/developer_change", "ieee8021MstpPortRole type modified: enum \"disabled\" added.", 0, 0);

/* 
    <module>
      <name>ieee8021-spanning-tree</name>
      <revision>2011-03-24</revision>
      <source>fromMIB</source>
      <internal_version>1.6.0</internal_version>
      <developer_change>YANG generated from MIB.</developer_change>
    </module>
 */

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/revision", "ieee8021-spanning-tree");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "2011-03-24");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee8021-spanning-tree']/revision", "2011-03-24", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/source", "ieee8021-spanning-tree");
        // sr_val_set_str_data(&v[fields++], SR_ENUM_T, "fromMIB");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee8021-spanning-tree']/source", "fromMIB", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/internal_version", "ieee8021-spanning-tree");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "1.6.0");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee8021-spanning-tree']/internal_version", "1.6.0", 0, 0);

        // sr_val_build_xpath(&v[fields], "/module-versions:module-versions/module[name='%s']/developer_change", "ieee8021-spanning-tree");
        // sr_val_set_str_data(&v[fields++], SR_STRING_T, "YANG generated from MIB.");
        lyd_new_path(*parent, NULL, "/module-versions:module-versions/module[name='ieee8021-spanning-tree']/developer_change", "YANG generated from MIB.", 0, 0);


        // *values = v;
        // *values_cnt = fields;

    } else {
        printf("GENERAL XP: %s\n", request_xpath);

        // *values = NULL;
        // values_cnt = 0;
    }

    return SR_ERR_OK;
}

/* Registers for providing of operational data under given xpath. */
int sr_plugin_init_cb(sr_session_ctx_t *session, void **private_data) {
    /* remember the session of our plugin */
    sess = session;

    sr_subscription_ctx_t *subscription = NULL;
    sr_subscription_ctx_t *subscription_oper = NULL;
    int rc = SR_ERR_OK;

    // operational data
    rc = sr_oper_get_items_subscribe(session, "module-versions", "/module-versions:module-versions", modvers_dataprovider_cb, NULL, SR_SUBSCR_DEFAULT, &subscription_oper);
    if (SR_ERR_OK != rc) goto error;

    syslog(LOG_DEBUG, "plugin initialized successfully.");

    /* set subscription as our private context */
    // how to preserve both of them?
    *private_data = subscription;

    return SR_ERR_OK;

error:
    syslog(LOG_ERR, "plugin initialization failed: %s", sr_strerror(rc));
    if (subscription != NULL) sr_unsubscribe(subscription);
    if (subscription_oper != NULL) sr_unsubscribe(subscription_oper);
    return rc;
}

void sr_plugin_cleanup_cb(sr_session_ctx_t *session, void *private_data) {
    (void)session;
    (void)private_data;
    /* subscription was set as our private context */
    sr_unsubscribe((sr_subscription_ctx_t *)private_data);
    syslog(LOG_DEBUG, "plugin cleanup finished");
}
