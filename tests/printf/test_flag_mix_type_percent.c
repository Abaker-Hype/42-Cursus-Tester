#include "tester.h"

printftest flag_mix_type_percent_tests[] = {
	{"%10.20%", 1, "s", {}},
	{"%010%", 1, "s", {}},
	{"%0-10%", 1, "s", {}},
	{"%-010%", 1, "s", {}},
	{"%15-10%", 1, "s", {}},
	{"%10-15%", 1, "s", {}},
	{"%#0- +27.13%", 1, "s", {}},
	{"%#0- +27.13", 1, "s", {}}
};

int tests_flag_mix_type_percent()
{
	return (arraysize(flag_mix_type_percent_tests));
}

void	test_flag_mix_type_percent(int n, bool detail)
{
	printftestcore(flag_mix_type_percent_tests[n], n, detail);
}
