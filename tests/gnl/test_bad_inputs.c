#include "tester.h"

gnltest bad_inputs_tests[] = {
	{NULL, 10},
	{"tests/gnl/files/empty",-1},
	{"tests/gnl/files/empty",0}
};

int tests_bad_inputs()
{
	return (arraysize(bad_inputs_tests));
}

void	test_bad_inputs(int n, bool detail)
{
	gnlcore(bad_inputs_tests[n], n, detail);
}
