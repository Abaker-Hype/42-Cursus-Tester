#include "tester.h"

printftest flag_mix_type_c_tests[] = {
	{"%10.20c", 1, "sc", {{.c='F'}}},
	{"%010c", 1, "sc", {{.c='F'}}},
	{"%010.10c", 1, "sc", {{.c='F'}}},
	{"%0-10c", 1, "sc", {{.c='F'}}},
	{"%-010c", 1, "sc", {{.c='F'}}},
	{"%0-0-15-0-10c", 1, "sc", {{.c='F'}}},
	{"%0-0-10-0-15c", 1, "sc", {{.c='F'}}},
	{"%#0- +27.13c", 1, "sc", {{.c='F'}}},
};

int tests_flag_mix_type_c()
{
	return (arraysize(flag_mix_type_c_tests));
}

void	test_flag_mix_type_c(int n, bool detail)
{
	printftestcore(flag_mix_type_c_tests[n], n, detail);
}
