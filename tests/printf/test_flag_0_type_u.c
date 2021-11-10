#include "tester.h"

printftest flag_0_type_u_tests[] = {
	{" %01u ", 1, "si", {{.i=0}}},
	{" %05u ", 1, "si", {{.i=0}}},
	{" %010u ", 1, "si", {{.i=0}}},
	{" %01u ", 1, "si", {{.i=INT_MAX}}},
	{" %05u ", 1, "si", {{.i=INT_MAX}}},
	{" %010u ", 1, "si", {{.i=INT_MAX}}},
	{" %015u ", 1, "su", {{.u=UINT_MAX}}},
	{" %015u ", 1, "si", {{.i=-177013}}},
	{" %042u %042u", 2, "sii", {{.i=42}, {.i=-42}}}
};

int tests_flag_0_type_u()
{
	return (arraysize(flag_0_type_u_tests));
}

void	test_flag_0_type_u(int n, bool detail)
{
	printftestcore(flag_0_type_u_tests[n], n, detail);
}
