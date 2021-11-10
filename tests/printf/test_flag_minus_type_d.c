#include "tester.h"

printftest flag_minus_type_d_tests[] = {
	{" %-1d ", 1, "si", {{.i=0}}},
	{" %-5d ", 1, "si", {{.i=0}}},
	{" %-10d ", 1, "si", {{.i=0}}},
	{" %-1d ", 1, "si", {{.i=INT_MAX}}},
	{" %-5d ", 1, "si", {{.i=INT_MAX}}},
	{" %-10d ", 1, "si", {{.i=INT_MAX}}},
	{" %-42d %-42d", 2, "sii", {{.i=42}, {.i=-42}}},
	{" %10-d ", 1, "si", {{.i=215600}}}
};

int tests_flag_minus_type_d()
{
	return (arraysize(flag_minus_type_d_tests));
}

void	test_flag_minus_type_d(int n, bool detail)
{
	printftestcore(flag_minus_type_d_tests[n], n, detail);
}
