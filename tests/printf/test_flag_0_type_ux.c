#include "tester.h"

printftest flag_0_type_X_tests[] = {
	{" %01X ", 1, "si", {{.i=0}}},
	{" %05X ", 1, "si", {{.i=0}}},
	{" %010X ", 1, "si", {{.i=0}}},
	{" %01X ", 1, "si", {{.i=INT_MAX}}},
	{" %010X ", 1, "si", {{.i=INT_MAX}}},
	{" %020X ", 1, "si", {{.i=INT_MAX}}},
	{" %01X ", 1, "si", {{.i=INT_MIN}}},
	{" %010X ", 1, "si", {{.i=INT_MIN}}},
	{" %020X ", 1, "si", {{.i=INT_MIN}}},
	{" %042X %042X", 2, "sii", {{.i=42}, {.i=-42}}} 
};

int tests_flag_0_type_X()
{
	return (arraysize(flag_0_type_X_tests));
}

void	test_flag_0_type_X(int n, bool detail)
{
	printftestcore(flag_0_type_X_tests[n], n, detail);
}
