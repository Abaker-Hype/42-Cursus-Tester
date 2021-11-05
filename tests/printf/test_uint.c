#include "tester.h"

printftest uint_tests[] = {
	{" %u ", 1, "si", {{.i=0}}},
	{" %u ", 1, "si", {{.i=2147483647}}},
	{" %u ", 1, "si", {{.i=-2147483648}}},
	{" %u %u %u ", 3, "siii", {{.i=42},{.i=-42},{.i=249857}}},
	{" %u%u%u ", 4, "siii", {{.i=1234567},{.i=987654},{.i=177013}}},
	{" %u %u %u %u %u %u ", 6, "siiiiii", {{.i=-13475},{.i=2375644},{.i=-32432},{.i=2147483647},{.i=-2147483648},{.i=216500}}}
};

int tests_uint()
{
	return (arraysize(uint_tests));
}

void	test_uint(int n, bool detail)
{
	printftestcore(uint_tests[n], n, detail);
}
