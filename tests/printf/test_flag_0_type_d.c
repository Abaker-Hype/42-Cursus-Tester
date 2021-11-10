#include "tester.h"

printftest flag_0_type_d_tests[] = {
	{" %01d ", 1, "si", {{.i=0}}},
	{" %05d ", 1, "si", {{.i=0}}},
	{" %010d ", 1, "si", {{.i=0}}},
	{" %01d ", 1, "si", {{.i=INT_MAX}}},
	{" %05d ", 1, "si", {{.i=INT_MAX}}},
	{" %010d ", 1, "si", {{.i=INT_MAX}}},
	{" %042d %042d", 2, "sii", {{.i=42}, {.i=-42}}} 
};

int tests_flag_0_type_d()
{
	return (arraysize(flag_0_type_d_tests));
}

void	test_flag_0_type_d(int n, bool detail)
{
	printftestcore(flag_0_type_d_tests[n], n, detail);
}
