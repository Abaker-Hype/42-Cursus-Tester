#include "tester.h"

printftest flag_dot_no_effect_tests[] = {
	{"%.%",1, "s",{}},
	{"%.5%",1, "s",{}},
	{"%.10%",1, "s",{}},
	{"%.c",1,"sc",{{.c='a'}}},
	{"%.5c",1,"sc",{{.c='b'}}},
	{"%.10c",1,"sc",{{.c='c'}}}
};

int tests_flag_dot_no_effect()
{
	return (arraysize(flag_dot_no_effect_tests));
}

void	test_flag_dot_no_effect(int n, bool detail)
{
	printftestcore(flag_dot_no_effect_tests[n], n, detail);
}
