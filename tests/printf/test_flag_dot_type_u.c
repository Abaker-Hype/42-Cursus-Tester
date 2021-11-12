#include "tester.h"

printftest flag_dot_type_u_tests[] = {
	{" %.u ", 1, "si", {{.i=0}}},
	{" %.10u ", 1, "si", {{.i=0}}},
	{" %.20u ", 1, "si", {{.i=0}}},
	{" %.u ", 1, "si", {{.i=INT_MAX}}},
	{" %.10u ", 1, "si", {{.i=INT_MAX}}},
	{" %.20u ", 1, "si", {{.i=INT_MAX}}},
	{" %.020u ", 1, "si", {{.i=INT_MAX}}},
	{" %.u ", 1, "si", {{.i=INT_MIN}}},
    {" %.10u ", 1, "si", {{.i=INT_MIN}}},
    {" %.20u ", 1, "si", {{.i=INT_MIN}}},
    {" %.020u ", 1, "si", {{.i=INT_MIN}}},
	{" %.5u %.10i", 2, "sii", {{.i=-177013}, {.i=-215600}}} 
};

int tests_flag_dot_type_u()
{
	return (arraysize(flag_dot_type_u_tests));
}

void	test_flag_dot_type_u(int n, bool detail)
{
	printftestcore(flag_dot_type_u_tests[n], n, detail);
}
