#include "tester.h"

printftest char_tests[] = {
	{" %c ", 1, "sc", {'a'}},
	{" %c %c ", 2, "scc", {'a','A'}},
	{" %c ", 1, "sc", {'\0'}},
	{" %c %c %c %c %c %c ", 6, "scccccc", {'1','7','7','0','1','3'}}
};

int tests_char()
{
	return (arraysize(char_tests));
}

void	test_char(int n, bool detail)
{
	printftestcore(char_tests[n], n, detail);
}
