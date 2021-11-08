#include "tester.h"

printftest type_u_tests[] = {
	{" %u ", 1, "si", {{.u=0}}},
	{" %u ", 1, "si", {{.u=-1}}},
	{" %u ", 1, "si", {{.u=INT_MAX}}},
	{" %u ", 1, "si", {{.u=INT_MIN}}},
	{" %u ", 1, "su", {{.u=UINT_MAX}}},
	{" %u %u %u ", 3, "suuu", {{.u=245987249},{.u=-435846},{.u=-249857}}},
	{" %u%u%u ", 3, "siii", {{.u=1234567},{.u=987654},{.u=177013}}},
	{" %u%u%u ", 3, "siii", {{.u=-1234567},{.u=-987654},{.u=-177013}}},
	{" %u %u %u %u %u %u ", 6, "siiiiii", {{.u=-13475},{.u=2375644},{.u=-32432},{.u=INT_MAX},{.u=INT_MIN},{.u=216500}}}
};

int tests_type_u()
{
	return (arraysize(type_u_tests));
}

void	test_type_u(int n, bool detail)
{
	printftestcore(type_u_tests[n], n, detail);
}
