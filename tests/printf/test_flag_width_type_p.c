#include "tester.h"

static char *s = "tacos";
static int i = 215600;

printftest flag_width_type_p_tests[] = {
	{" %1p ",1, "su",{{.p=&test_flag_width_type_p}}},
	{" %15p ",1, "su",{{.p=&test_flag_width_type_p}}},
	{" %25p ",1, "su",{{.p=&test_flag_width_type_p}}},
	{" %1p %5p %10p ",3,"suuu",{}}
};

int tests_flag_width_type_p()
{
	return (arraysize(flag_width_type_p_tests));
}

void	test_flag_width_type_p(int n, bool detail)
{
	printftestcore(flag_width_type_p_tests[n], n, detail);
}
