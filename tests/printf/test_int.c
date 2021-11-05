#include "tester.h"

printftest int_tests[] = {
	{" %i ", 1, "si", {{.i=0}}},
	{" %i ", 1, "si", {{.i=2147483647}}},
	{" %i ", 1, "si", {{.i=-2147483648}}},
	{" %i %i %i ", 3, "siii", {{.i=42},{.i=-42},{.i=249857}}},
	{" %i%i%i ", 4, "siii", {{.i=1234567},{.i=987654},{.i=177013}}},
	{" %i %i %i %i %i %i ", 6, "siiiiii", {{.i=-13475},{.i=2375644},{.i=-32432},{.i=2147483647},{.i=-2147483648},{.i=216500}}}
};

int tests_int()
{
	return (arraysize(int_tests));
}

void	test_int(int n, bool detail)
{
	printftestcore(int_tests[n], n, detail);
}
