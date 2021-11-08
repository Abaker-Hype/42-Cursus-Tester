#include "tester.h"

printftest flag_hash_no_effect_tests[] = {
	{"%#%",0, "s",{}},
	{"%#c",1,"sc",{{.c='a'}}},
	{"%#s",1,"ss",{{.s="Emergence"}}},
	{"%#i",1,"si",{{.i=INT_MAX}}},
	{"%#d",1,"si",{{.i=INT_MIN}}},
	{"%#u",1,"su",{{.u=UINT_MAX}}},
	{"%#p",1,"su",{{.p="TEST"}}},
};

int tests_flag_hash_no_effect()
{
	return (arraysize(flag_hash_no_effect_tests));
}

void	test_flag_hash_no_effect(int n, bool detail)
{
	printftestcore(flag_hash_no_effect_tests[n], n, detail);
}
