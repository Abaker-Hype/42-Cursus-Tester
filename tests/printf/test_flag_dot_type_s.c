#include "tester.h"

printftest flag_dot_type_s_tests[] = {
	{" %.s ", 1, "ss", {{.s="Tacos"}}},
	{" %.1s ", 1, "ss", {{.s="Tacos"}}},
	{" %.5s ", 1, "ss", {{.s="Tacos"}}},
	{" %.10s ", 1, "ss", {{.s="Tacos"}}},
	{" %.10s ", 1, "ss", {{.s="⛵⛱⛄❎⚡"}}},
	{"%.s%.5s%.10s", 3, "ssss", {{.s=NULL},{.s=NULL},{.s=NULL}}}
};

int tests_flag_dot_type_s()
{
	return (arraysize(flag_dot_type_s_tests));
}

void	test_flag_dot_type_s(int n, bool detail)
{
	printftestcore(flag_dot_type_s_tests[n], n, detail);
}
