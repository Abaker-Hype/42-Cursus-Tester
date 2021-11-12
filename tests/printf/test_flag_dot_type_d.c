#include "tester.h"

printftest flag_dot_type_d_tests[] = {
	{" %.d ", 1, "si", {{.i=0}}},
	{" %.10d ", 1, "si", {{.i=0}}},
	{" %.20d ", 1, "si", {{.i=0}}},
	{" %.d ", 1, "si", {{.i=INT_MAX}}},
	{" %.10d ", 1, "si", {{.i=INT_MAX}}},
	{" %.20d ", 1, "si", {{.i=INT_MAX}}},
	{" %.020d ", 1, "si", {{.i=INT_MAX}}},
	{" %.d ", 1, "si", {{.i=INT_MIN}}},
    {" %.10d ", 1, "si", {{.i=INT_MIN}}},
    {" %.20d ", 1, "si", {{.i=INT_MIN}}},
    {" %.020d ", 1, "si", {{.i=INT_MIN}}},
	{" %.5d %.10d", 2, "sii", {{.i=-177013}, {.i=-215600}}} 
};

int tests_flag_dot_type_d()
{
	return (arraysize(flag_dot_type_d_tests));
}

void	test_flag_dot_type_d(int n, bool detail)
{
	printftestcore(flag_dot_type_d_tests[n], n, detail);
}
