#include "tester.h"

printftest flag_mix_type_X_tests[] = {
	{"%#010X", 1, "si", {{.i=12345}}},
	{"%0#10X", 1, "si", {{.i=12345}}},
	{"%#-10X", 1, "si", {{.i=12345}}},
	{"%-#10X", 1, "si", {{.i=12345}}},
	{"%-#.15X", 1, "si", {{.i=12345}}},
	{"%10#X", 1, "si", {{.i=12345}}},
	{"%10#-X", 1, "si", {{.i=12345}}},
	{"%15#10X", 1, "si", {{.i=12345}}},
	{"%10#15X", 1, "si", {{.i=12345}}},
	{"%.10-020X", 1, "si", {{.i=12345}}},
	{"%.10#020X", 1, "si", {{.i=12345}}},
	{"%.20-010X", 1, "si", {{.i=12345}}},
	{"%#0- +27.13X", 1, "si", {{.i=12345}}},
};

int tests_flag_mix_type_X()
{
	return (arraysize(flag_mix_type_X_tests));
}

void	test_flag_mix_type_X(int n, bool detail)
{
	printftestcore(flag_mix_type_X_tests[n], n, detail);
}
