#include "tester.h"

printftest flag_minus_type_percent_tests[] = {
	{" %-1% ", 1, "s", {}},
	{" %-5% ", 1, "s", {}},
	{" %-10% ", 1, "s", {}},
	{" %-42% %42%", 2, "s", {}},
	{"%-42", 1, "s", {}},
	{"%42-%", 1, "s", {}}
};

int tests_flag_minus_type_percent()
{
	return (arraysize(flag_minus_type_percent_tests));
}

void	test_flag_minus_type_percent(int n, bool detail)
{
	printftestcore(flag_minus_type_percent_tests[n], n, detail);
}
