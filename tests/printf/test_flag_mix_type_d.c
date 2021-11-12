#include "tester.h"

printftest flag_mix_type_d_tests[] = {
	{"%+ d", 1, "si", {{.i=12345}}},
	{"% +d", 1, "si", {{.i=12345}}},
	{"%-010d", 1, "si", {{.i=12345}}},
	{"%0-10d", 1, "si", {{.i=12345}}},
	{"%0+10d", 1, "si", {{.i=12345}}},
	{"%+010d", 1, "si", {{.i=12345}}},
	{"%15 10d", 1, "si", {{.i=12345}}},
	{"%10 15d", 1, "si", {{.i=12345}}},
	{"%.10-020d", 1, "si", {{.i=12345}}},
	{"%.10 020d", 1, "si", {{.i=12345}}},
	{"%.10+020d", 1, "si", {{.i=12345}}},
	{"%.20-010d", 1, "si", {{.i=12345}}},
	{"%#0- +27.13d", 1, "si", {{.i=12345}}},
};

int tests_flag_mix_type_d()
{
	return (arraysize(flag_mix_type_d_tests));
}

void	test_flag_mix_type_d(int n, bool detail)
{
	printftestcore(flag_mix_type_d_tests[n], n, detail);
}
