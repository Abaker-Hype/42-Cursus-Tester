#include "tester.h"

printftest flag_0_type_percent_tests[] = {
	{" %01% ", 1, "s", {}},
	{" %05% ", 1, "s", {}},
	{" %010% ", 1, "s", {}},
	{" %042% %042%", 2, "s", {}},
	{"%042", 1, "s", {}},
	{"%0000%", 1, "s", {}}
};

int tests_flag_0_type_percent()
{
	return (arraysize(flag_0_type_percent_tests));
}

void	test_flag_0_type_percent(int n, bool detail)
{
	printftestcore(flag_0_type_percent_tests[n], n, detail);
}
