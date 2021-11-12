#include "tester.h"

printftest flag_dot_type_x_tests[] = {
	{" %.x ", 1, "si", {{.i=0}}},
	{" %.10x ", 1, "si", {{.i=0}}},
	{" %.20x ", 1, "si", {{.i=0}}},
	{" %.x ", 1, "si", {{.i=INT_MAX}}},
	{" %.10x ", 1, "si", {{.i=INT_MAX}}},
	{" %.20x ", 1, "si", {{.i=INT_MAX}}},
	{" %.020x ", 1, "si", {{.i=INT_MAX}}},
	{" %.x ", 1, "si", {{.i=INT_MIN}}},
    {" %.10x ", 1, "si", {{.i=INT_MIN}}},
    {" %.20x ", 1, "si", {{.i=INT_MIN}}},
    {" %.020x ", 1, "si", {{.i=INT_MIN}}},
	{" %.5x %.10x", 2, "sii", {{.i=-177013}, {.i=-215600}}} 
};

int tests_flag_dot_type_x()
{
	return (arraysize(flag_dot_type_x_tests));
}

void	test_flag_dot_type_x(int n, bool detail)
{
	printftestcore(flag_dot_type_x_tests[n], n, detail);
}
