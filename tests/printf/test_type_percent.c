#include "tester.h"

printftest type_percent_tests[] = {
	{" %% ",0,"s",{}},	
	{" %% %% ",0,"s",{}},
	{" %% %% %% ", 0, "s", {}},
	{"%%  %%  %%", 0, "s", {}},
	{"%%", 0, "s", {}},
	{"%", 0, "s", {}},
	{"%%%", 0, "s", {}},
	{"w%w%w%w",0,"s",{}},
	{"%%%%%%%%",0,"s",{}}
};

int tests_type_percent()
{
	return (arraysize(type_percent_tests));
}

void	test_type_percent(int n, bool detail)
{
	printftestcore(type_percent_tests[n], n, detail);
}
