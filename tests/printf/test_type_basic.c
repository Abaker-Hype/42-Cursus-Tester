#include "tester.h"

printftest type_basic_tests[] = {
	{"",0, "s",{}},
	{"Simple Print",0,"s",{}},
	{"HELP ME PLEASE I AM GOING INSANE!",0,"s",{}},
	{"Line 1\nLine 2",0,"s",{}},
	{"\r\v\t\n\f",0,"s",{}}
};

int tests_type_basic()
{
	return (arraysize(type_basic_tests));
}

void	test_type_basic(int n, bool detail)
{
	printftestcore(type_basic_tests[n], n, detail);
}
