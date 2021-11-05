#include "tester.h"

printftest percent_tests[] = {
	{" %% ",0,"s",{}},	
	{" %% %% ",0,"s",{}},
	{"w%w%w%w",0,"s",{}},
	{"%%%%%%%%",0,"s",{}}
};

int tests_percent()
{
	return (arraysize(percent_tests));
}

void	test_percent(int n, bool detail)
{
	printftestcore(percent_tests[n], n, detail);
}
