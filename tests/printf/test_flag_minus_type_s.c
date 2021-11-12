#include "tester.h"

printftest flag_minus_type_s_tests[] = {
	{" %-1s ", 1, "ss", {{.s="Tacos"}}},
	{" %-5s ", 1, "ss", {{.s="Tacos"}}},
	{" %-10s ", 1, "ss", {{.s="Tacos"}}},
	{" %.20s ", 1, "ss", {{.s="⛵⛱⛄❎⚡"}}},
	{"%-10s%-10s%-10s", 3, "ssss", {{.s="(NULL)"},{.s=NULL},{.s="(NULL)"}}},
	{" %10-s ", 1, "ss", {{.s="Tacos"}}}
};

int tests_flag_minus_type_s()
{
	return (arraysize(flag_minus_type_s_tests));
}

void	test_flag_minus_type_s(int n, bool detail)
{
	printftestcore(flag_minus_type_s_tests[n], n, detail);
}
