#include "tester.h"

printftest flag_0_type_c_tests[] = {
	{" %01c ", 1, "sc", {{.c='A'}}},
	{" %05c ", 1, "sc", {{.c='b'}}},
	{" %010c ", 1, "sc", {{.c='C'}}},
	{"%04c", 1, "sc", {{.c='\0'}}},
	{" %042c %042c", 2, "scc", {{.c=42}, {.c=-42}}} 
};

int tests_flag_0_type_c()
{
	return (arraysize(flag_0_type_c_tests));
}

void	test_flag_0_type_c(int n, bool detail)
{
	printftestcore(flag_0_type_c_tests[n], n, detail);
}
