#include "tester.h"

printftest flag_mix_type_i_tests[] = {
	{"%+ i", 1, "si", {{.i=12345}}},
	{"% +i", 1, "si", {{.i=12345}}},
	{"%-010i", 1, "si", {{.i=12345}}},
	{"%0-10i", 1, "si", {{.i=12345}}},
	{"%0+10i", 1, "si", {{.i=12345}}},
	{"%+010i", 1, "si", {{.i=12345}}},
	{"%15 10i", 1, "si", {{.i=12345}}},
	{"%10 15i", 1, "si", {{.i=12345}}},
	{"%.10-020i", 1, "si", {{.i=12345}}},
	{"%.10 020i", 1, "si", {{.i=12345}}},
	{"%.10+020i", 1, "si", {{.i=12345}}},
	{"%.20-010i", 1, "si", {{.i=12345}}},
	{"%#0- +27.13i", 1, "si", {{.i=12345}}},
};

int tests_flag_mix_type_i()
{
	return (arraysize(flag_mix_type_i_tests));
}

void	test_flag_mix_type_i(int n, bool detail)
{
	printftestcore(flag_mix_type_i_tests[n], n, detail);
}
