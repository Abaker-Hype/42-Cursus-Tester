#include "tester.h"

static char *s = "tacos";
static int i = 215600;

printftest flag_0_type_p_tests[] = {
	{" %01p ",1, "su",{{.p=&test_flag_0_type_p}}},
	{" %015p ",1, "su",{{.p=&test_flag_0_type_p}}},
	{" %025p ",1, "su",{{.p=&test_flag_0_type_p}}},
	{" %01p %05p %010p ",3,"suuu",{}}
};

int tests_flag_0_type_p()
{
	return (arraysize(flag_0_type_p_tests));
}

void	test_flag_0_type_p(int n, bool detail)
{
	printftestcore(flag_0_type_p_tests[n], n, detail);
}
