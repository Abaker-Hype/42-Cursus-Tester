#include "tester.h"

printftest flag_mix_type_x_tests[] = {
	{"%#010x", 1, "si", {{.i=12345}}},
	{"%0#10x", 1, "si", {{.i=12345}}},
	{"%#-10x", 1, "si", {{.i=12345}}},
	{"%-#10x", 1, "si", {{.i=12345}}},
	{"%-#.15x", 1, "si", {{.i=12345}}},
	{"%10#x", 1, "si", {{.i=12345}}},
	{"%10#-x", 1, "si", {{.i=12345}}},
	{"%15#10x", 1, "si", {{.i=12345}}},
	{"%10#15x", 1, "si", {{.i=12345}}},
	{"%.10-020x", 1, "si", {{.i=12345}}},
	{"%.10#020x", 1, "si", {{.i=12345}}},
	{"%.20-010x", 1, "si", {{.i=12345}}},
	{"%#0- +27.13x", 1, "si", {{.i=12345}}},
};

int tests_flag_mix_type_x()
{
	return (arraysize(flag_mix_type_x_tests));
}

void	test_flag_mix_type_x(int n, bool detail)
{
	printftestcore(flag_mix_type_x_tests[n], n, detail);
}
