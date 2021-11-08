#include "tester.h"

printftest type_c_tests[] = {
	{" %c ", 1, "sc", {'a'}},
	{" %c %c ", 2, "scc", {'a','A'}},
	{"%c%c", 2, "scc", {'0'-256, '0'+256}},
	{" %c ", 1, "sc", {'\0'}},
	{" %c %c %c ", 3, "sccc", {' ', ' ', ' '}},
	{" %c %c %c ", 3, "sccc", {'0', 0, '1'}},
	{" %c %c %c %c %c %c ", 6, "scccccc", {'1','7','7','0','1','3'}}
};

int tests_type_c()
{
	return (arraysize(type_c_tests));
}

void	test_type_c(int n, bool detail)
{
	printftestcore(type_c_tests[n], n, detail);
}
