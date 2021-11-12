#include "tester.h"

printftest flag_dot_type_X_tests[] = {
	{" %.X ", 1, "si", {{.i=0}}},
	{" %.10X ", 1, "si", {{.i=0}}},
	{" %.20X ", 1, "si", {{.i=0}}},
	{" %.X ", 1, "si", {{.i=INT_MAX}}},
	{" %.10X ", 1, "si", {{.i=INT_MAX}}},
	{" %.20X ", 1, "si", {{.i=INT_MAX}}},
	{" %.020X ", 1, "si", {{.i=INT_MAX}}},
	{" %.X ", 1, "si", {{.i=INT_MIN}}},
    {" %.10X ", 1, "si", {{.i=INT_MIN}}},
    {" %.20X ", 1, "si", {{.i=INT_MIN}}},
    {" %.020X ", 1, "si", {{.i=INT_MIN}}},
	{" %.5X %.10X", 2, "sii", {{.i=-177013}, {.i=-215600}}} 
};

int tests_flag_dot_type_X()
{
	return (arraysize(flag_dot_type_X_tests));
}

void	test_flag_dot_type_X(int n, bool detail)
{
	printftestcore(flag_dot_type_X_tests[n], n, detail);
}
