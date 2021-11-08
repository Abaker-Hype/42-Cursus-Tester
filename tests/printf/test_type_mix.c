#include "tester.h"

printftest type_mix_tests[] = {
	{"%%%c%%%s%%%i%%%d%%%u%%%x%%%X%%\n", 7, "scsiiiii", {{.c='A'},{.s="42"},{.i=42},{.i=42},{.i=42},{.i=42},{.i=42}}},
	{"%%%c%%%s%%%i%%%d%%%u%%%x%%%X%%\n", 7, "scsiiiii", {{.c='A'},{.s="-42"},{.i=-42},{.i=-42},{.i=-42},{.i=-42},{.i=-42}}},
	{"%%%c%%%s%%%i%%%d%%%u%%%x%%%X%%\n", 7, "scsiiiii", {{.c='\0'},{.s=NULL},{.i=0},{.i=0},{.i=0},{.i=0},{.i=0}}}
};

int tests_type_mix()
{
	return (arraysize(type_mix_tests));
}

void	test_type_mix(int n, bool detail)
{
	printftestcore(type_mix_tests[n], n, detail);
}
