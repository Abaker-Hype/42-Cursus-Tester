#include "tester.h"

printftest flag_width_type_x_tests[] = {
	{" %1x ", 1, "si", {{.i=0}}},
	{" %5x ", 1, "si", {{.i=0}}},
	{" %10x ", 1, "si", {{.i=0}}},
	{" %1x ", 1, "si", {{.i=INT_MAX}}},
	{" %5x ", 1, "si", {{.i=INT_MAX}}},
	{" %10x ", 1, "si", {{.i=INT_MAX}}},
	{" %42x %42x", 2, "sii", {{.i=42}, {.i=-42}}} 
};

int tests_flag_width_type_x()
{
	return (arraysize(flag_width_type_x_tests));
}

void	test_flag_width_type_x(int n, bool detail)
{
	printftestcore(flag_width_type_x_tests[n], n, detail);
}
