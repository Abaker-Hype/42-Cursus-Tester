#include "tester.h"

char *s = "tacos";
int i = 215600;

printftest type_p_tests[] = {
	{" %p ",1, "su",{{.p=&test_type_p}}},
	{" %p ",1,"su",{}},
	{" %p %p ",2,"suu",{{.p=&type_p_tests}, {.p=&printf}}},
	{" %p%p",2,"suu",{{.p=&s}, {.p=&i}}},
	{" %p %p %p %p %p ",5,"suuuuu",{{.p=type_p_tests},{.p=&"tacos"}, {.p=&printf},{.p=&i},{}}}
};

int tests_type_p()
{
	return (arraysize(type_p_tests));
}

void	test_type_p(int n, bool detail)
{
	printftestcore(type_p_tests[n], n, detail);
}
