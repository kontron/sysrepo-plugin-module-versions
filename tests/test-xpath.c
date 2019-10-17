#include <stdio.h>

#include <glib.h>

#include <sysrepo/xpath.h>

void test_sr_xpath_key_value(void)
{
    char *module_name = NULL;
    char xpath_a[128] = "/module-versions:module-versions/module[name='ietf-interfaces']/"
    char xpath_b[128] = "/module-versions:module-versions/module[name='ietf-interfaces']/revision"


    sr_xpath_ctx_t xpath_ctx = { 0, };

    module_name = sr_xpath_key_value(xpath_a, "module", "name", &xpath_ctx);
    g_assert_cmpstr(module_name, ==, "ietf-interfaces");
    sr_xpath_recover(&xpath_ctx);

    module_name = sr_xpath_key_value(xpath_b, "module", "name", &xpath_ctx);
    g_assert_cmpstr(module_name, ==, "ietf-interfaces");
    sr_xpath_recover(&xpath_ctx);
}

void test_sr_xpath_node_name(void)
{
    char *name = NULL;
    char xpath_a[128] = "/module-versions:module-versions/module/"
    char xpath_b[128] = "/module-versions:module-versions/module[name='ietf-interfaces']/revision"
    
    g_assert_cmpstr(sr_xpath_node_name(xpath_a), ==, "module");
    g_assert_cmpstr(sr_xpath_node_name(xpath_b), ==, "module");
}

void test_sr_xpath_node_name_eq(void)
{
    char xpath_a[128] = "/module-versions:module-versions/module/"
    char xpath_b[128] = "/module-versions:module-versions/module[name='ietf-interfaces']/revision"

    g_assert(sr_xpath_node_name_eq(xpath_a, "module"));
    g_assert(sr_xpath_node_name_eq(xpath_b, "module"));
}

int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;

	g_test_init(&argc, &argv, NULL);

	g_test_add_func("/xpath/sr_xpath_key_value/valid",
		test_sr_xpath_key_value);

	g_test_add_func("/xpath/sr_xpath_node_name/valid",
        test_sr_xpath_node_name);

	g_test_add_func("/xpath/sr_xpath_node_name_eq/valid",
        test_sr_xpath_node_name_eq);

	return g_test_run();
}
