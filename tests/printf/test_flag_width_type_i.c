#include "tester.h"

printftest flag_width_type_i_tests[] = {
	{" %1i ", 1, "si", {{.i=0}}},
	{" %5i ", 1, "si", {{.i=0}}},
	{" %10i ", 1, "si", {{.i=0}}},
	{" %1i ", 1, "si", {{.i=INT_MAX}}},
	{" %10i ", 1, "si", {{.i=INT_MAX}}},
	{" %20i ", 1, "si", {{.i=INT_MAX}}},
	{" %1i ", 1, "si", {{.i=INT_MIN}}},
	{" %10i ", 1, "si", {{.i=INT_MIN}}},
	{" %20i ", 1, "si", {{.i=INT_MIN}}},
	{" %42i %42i", 2, "sii", {{.i=42}, {.i=-42}}} 
};

int tests_flag_width_type_i()
{
	return (arraysize(flag_width_type_i_tests));
}

void	test_flag_width_type_i(int n, bool detail)
{
	printftestcore(flag_width_type_i_tests[n], n, detail);
}
