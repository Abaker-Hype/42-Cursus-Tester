#include "tester.h"
#define LOC(x) "tests/gnl/files/" "" x

gnltest buffer_1_tests[] = {
	{LOC("41_no_nl"), 1},
	{LOC("41_with_nl"),1},
	{LOC("42_no_nl"),1},
	{LOC("42_with_nl"),1},
	{LOC("43_no_nl"),1},
	{LOC("43_with_nl"),1},
	{LOC("alternate_line_nl_no_nl"),1},
	{LOC("alternate_line_nl_with_nl"),1},
	{LOC("big_line_no_nl"),1},
	{LOC("big_line_with_nl"),1},
	{LOC("empty"),1},
	{LOC("multiple_line_no_nl"),1},
	{LOC("multiple_line_with_nl"),1},
	{LOC("multiple_nlx5"),1},
	{LOC("nl"),1}
};

int tests_buffer_1()
{
	return (arraysize(buffer_1_tests));
}

void	test_buffer_1(int n, bool detail)
{
	gnlcore(buffer_1_tests[n], n, detail);
}
