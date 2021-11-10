#include "tester.h"

printftest flag_0_type_s_tests[] = {
	{" %01s ", 1, "ss", {{.s="Tacos"}}},
	{" %05s ", 1, "ss", {{.s="Tacos"}}},
	{" %010s ", 1, "ss", {{.s="Tacos"}}},
	{"%010s%010s%010s", 3, "ssss", {{.s="(NULL)"},{.s=NULL},{.s="(NULL)"}}}
};

int tests_flag_0_type_s()
{
	return (arraysize(flag_0_type_s_tests));
}

void	test_flag_0_type_s(int n, bool detail)
{
	printftestcore(flag_0_type_s_tests[n], n, detail);
}
