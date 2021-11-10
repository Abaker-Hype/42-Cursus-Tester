#include "tester.h"

printftest flag_space_no_effect_tests[] = {
	{"% %",0, "s",{}},
	{"% c",1,"sc",{{.c='a'}}},
	{"% s",1,"ss",{{.s="Emergence"}}},
	{"% u",1, "su", {{.u=UINT_MAX}}},
	{"% x",1,"si",{{.i=INT_MAX}}},
	{"% X",1,"si",{{.i=INT_MIN}}},
	{"% p",1,"su",{{.p="TEST"}}},
};

int tests_flag_space_no_effect()
{
	return (arraysize(flag_space_no_effect_tests));
}

void	test_flag_space_no_effect(int n, bool detail)
{
	printftestcore(flag_space_no_effect_tests[n], n, detail);
}
