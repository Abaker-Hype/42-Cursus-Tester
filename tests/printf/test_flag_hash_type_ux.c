#include "tester.h"

printftest flag_hash_type_X_tests[] = {
	{" %#X ", 1, "si", {{.i=0}}},
	{" %#X ", 1, "si", {{.i=INT_MAX}}},
	{" %#X ", 1, "si", {{.i=INT_MIN}}},
	{" %##X ", 1, "si", {{.i=8226}}},
	{" %##########X ", 1, "si", {{.i=8226}}},
	{" %#X %#X %#X ", 3, "siii", {{.i=42},{.i=-42},{.i=249857}}},
	{" %#X%#X%#X ", 3, "siii", {{.i=1234567},{.i=987654},{.i=177013}}},
	{" %#X%#X%#X ", 3, "siii", {{.i=-325972},{.i=-215600}, {.i=-43534534}}},
	{" %#X %#X %#X %#X %#X %#X ", 6, "siiiiii", {{.i=-13475},{.i=2375644},{.i=-32432},{.i=INT_MAX},{.i=INT_MIN},{.i=216500}}}
};

int tests_flag_hash_type_X()
{
	return (arraysize(flag_hash_type_X_tests));
}

void	test_flag_hash_type_X(int n, bool detail)
{
	printftestcore(flag_hash_type_X_tests[n], n, detail);
}
