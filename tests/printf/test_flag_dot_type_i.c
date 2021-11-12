#include "tester.h"

printftest flag_dot_type_i_tests[] = {
	{" %.i ", 1, "si", {{.i=0}}},
	{" %.10i ", 1, "si", {{.i=0}}},
	{" %.20i ", 1, "si", {{.i=0}}},
	{" %.i ", 1, "si", {{.i=INT_MAX}}},
	{" %.10i ", 1, "si", {{.i=INT_MAX}}},
	{" %.20i ", 1, "si", {{.i=INT_MAX}}},
	{" %.020i ", 1, "si", {{.i=INT_MAX}}},
	{" %.5i %.10i", 2, "sii", {{.i=-177013}, {.i=-215600}}} 
};

int tests_flag_dot_type_i()
{
	return (arraysize(flag_dot_type_i_tests));
}

void	test_flag_dot_type_i(int n, bool detail)
{
	printftestcore(flag_dot_type_i_tests[n], n, detail);
}
