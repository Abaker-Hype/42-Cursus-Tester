#include "tester.h"

printftest flag_width_type_X_tests[] = {
	{" %1X ", 1, "si", {{.i=0}}},
	{" %5X ", 1, "si", {{.i=0}}},
	{" %10X ", 1, "si", {{.i=0}}},
	{" %1X ", 1, "si", {{.i=INT_MAX}}},
	{" %5X ", 1, "si", {{.i=INT_MAX}}},
	{" %10X ", 1, "si", {{.i=INT_MAX}}},
	{" %1X ", 1, "si", {{.i=INT_MIN}}},
	{" %5X ", 1, "si", {{.i=INT_MIN}}},
	{" %10X ", 1, "si", {{.i=INT_MIN}}},
	{" %42X %42X", 2, "sii", {{.i=42}, {.i=-42}}} 
};

int tests_flag_width_type_X()
{
	return (arraysize(flag_width_type_X_tests));
}

void	test_flag_width_type_X(int n, bool detail)
{
	printftestcore(flag_width_type_X_tests[n], n, detail);
}
