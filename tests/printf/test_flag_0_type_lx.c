#include "tester.h"

printftest flag_0_type_x_tests[] = {
	{" %01x ", 1, "si", {{.i=0}}},
	{" %05x ", 1, "si", {{.i=0}}},
	{" %010x ", 1, "si", {{.i=0}}},
	{" %01x ", 1, "si", {{.i=INT_MAX}}},
	{" %010x ", 1, "si", {{.i=INT_MAX}}},
	{" %020x ", 1, "si", {{.i=INT_MAX}}},
	{" %01x ", 1, "si", {{.i=INT_MIN}}},
	{" %010x ", 1, "si", {{.i=INT_MIN}}},
	{" %020x ", 1, "si", {{.i=INT_MIN}}},
	{" %042x %042x", 2, "sii", {{.i=42}, {.i=-42}}} 
};

int tests_flag_0_type_x()
{
	return (arraysize(flag_0_type_x_tests));
}

void	test_flag_0_type_x(int n, bool detail)
{
	printftestcore(flag_0_type_x_tests[n], n, detail);
}
