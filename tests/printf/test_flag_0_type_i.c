#include "tester.h"

printftest flag_0_type_i_tests[] = {
	{" %01i ", 1, "si", {{.i=0}}},
	{" %05i ", 1, "si", {{.i=0}}},
	{" %010i ", 1, "si", {{.i=0}}},
	{" %01i ", 1, "si", {{.i=INT_MAX}}},
	{" %05i ", 1, "si", {{.i=INT_MAX}}},
	{" %010i ", 1, "si", {{.i=INT_MAX}}},
	{" %042i %042i", 2, "sii", {{.i=42}, {.i=-42}}} 
};

int tests_flag_0_type_i()
{
	return (arraysize(flag_0_type_i_tests));
}

void	test_flag_0_type_i(int n, bool detail)
{
	printftestcore(flag_0_type_i_tests[n], n, detail);
}
