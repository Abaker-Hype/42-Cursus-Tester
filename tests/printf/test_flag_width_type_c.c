#include "tester.h"

printftest flag_width_type_c_tests[] = {
	{" %1c ", 1, "sc", {{.c='A'}}},
	{" %5c ", 1, "sc", {{.c='b'}}},
	{" %10c ", 1, "sc", {{.c='C'}}},
	{"%4c", 1, "sc", {{.c='\0'}}},
	{" %42c %42c", 2, "scc", {{.c=42}, {.c=-42}}} 
};

int tests_flag_width_type_c()
{
	return (arraysize(flag_width_type_c_tests));
}

void	test_flag_width_type_c(int n, bool detail)
{
	printftestcore(flag_width_type_c_tests[n], n, detail);
}
