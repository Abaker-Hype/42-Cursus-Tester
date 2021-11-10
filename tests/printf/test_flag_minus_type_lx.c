#include "tester.h"

printftest flag_minus_type_x_tests[] = {
	{" %-1x ", 1, "si", {{.i=0}}},
	{" %-5x ", 1, "si", {{.i=0}}},
	{" %-10x ", 1, "si", {{.i=0}}},
	{" %-1x ", 1, "si", {{.i=INT_MAX}}},
	{" %-5x ", 1, "si", {{.i=INT_MAX}}},
	{" %-10x ", 1, "si", {{.i=INT_MAX}}},
	{" %-42x %-42x", 2, "sii", {{.i=42}, {.i=-42}}},
	{" %10-x ", 1, "si", {{.i=215600}}}
};

int tests_flag_minus_type_x()
{
	return (arraysize(flag_minus_type_x_tests));
}

void	test_flag_minus_type_x(int n, bool detail)
{
	printftestcore(flag_minus_type_x_tests[n], n, detail);
}
