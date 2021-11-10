#include "tester.h"

printftest flag_minus_type_u_tests[] = {
	{" %-1u ", 1, "si", {{.i=0}}},
	{" %-5u ", 1, "si", {{.i=0}}},
	{" %-10u ", 1, "si", {{.i=0}}},
	{" %-1u ", 1, "si", {{.i=INT_MAX}}},
	{" %-5u ", 1, "si", {{.i=INT_MAX}}},
	{" %-10u ", 1, "si", {{.i=INT_MAX}}},
	{" %-15u ", 1, "su", {{.u=UINT_MAX}}},
	{" %-15u ", 1, "si", {{.i=-177013}}},
	{" %-42u %-42u", 2, "sii", {{.i=42}, {.i=-42}}},
	{" %10-u ", 1, "si", {{.i=215600}}}
};

int tests_flag_minus_type_u()
{
	return (arraysize(flag_minus_type_u_tests));
}

void	test_flag_minus_type_u(int n, bool detail)
{
	printftestcore(flag_minus_type_u_tests[n], n, detail);
}
