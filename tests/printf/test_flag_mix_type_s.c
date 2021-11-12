#include "tester.h"

printftest flag_mix_type_s_tests[] = {
	{"%10.20s", 1, "ss", {{.s="Test"}}},
	{"%010s", 1, "ss", {{.s="Test"}}},
	{"%010.10s", 1, "ss", {{.s="Test"}}},
	{"%0-10s", 1, "ss", {{.s="Test"}}},
	{"%-010s", 1, "ss", {{.s="Test"}}},
	{"%0-0-15-0-10s", 1, "ss", {{.s="Test"}}},
	{"%0-0-10-0-15s", 1, "ss", {{.s="Test"}}},
	{"%#0- +27.13s", 1, "ss", {{.s="Test"}}},
};

int tests_flag_mix_type_s()
{
	return (arraysize(flag_mix_type_s_tests));
}

void	test_flag_mix_type_s(int n, bool detail)
{
	printftestcore(flag_mix_type_s_tests[n], n, detail);
}
