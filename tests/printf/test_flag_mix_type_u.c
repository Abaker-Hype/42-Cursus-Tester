#include "tester.h"

printftest flag_mix_type_u_tests[] = {
	{"%-010u", 1, "si", {{.i=12345}}},
	{"%0-10u", 1, "si", {{.i=12345}}},
	{"%0+10u", 1, "si", {{.i=12345}}},
	{"%+010u", 1, "si", {{.i=12345}}},
	{"%15 10u", 1, "si", {{.i=12345}}},
	{"%10 15u", 1, "si", {{.i=12345}}},
	{"%.10-020u", 1, "si", {{.i=12345}}},
	{"%.10 020u", 1, "si", {{.i=12345}}},
	{"%.10+020u", 1, "si", {{.i=12345}}},
	{"%.20-010u", 1, "si", {{.i=12345}}},
	{"%#0- +27.13u", 1, "si", {{.i=12345}}},
};

int tests_flag_mix_type_u()
{
	return (arraysize(flag_mix_type_u_tests));
}

void	test_flag_mix_type_u(int n, bool detail)
{
	printftestcore(flag_mix_type_u_tests[n], n, detail);
}
