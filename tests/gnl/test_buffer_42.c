#include "tester.h"
#define LOC(x) "tests/gnl/files/" "" x

gnltest buffer_42_tests[] = {
	{LOC("41_no_nl"), 42},
	{LOC("41_with_nl"),42},
	{LOC("42_no_nl"),42},
	{LOC("42_with_nl"),42},
	{LOC("43_no_nl"),42},
	{LOC("43_with_nl"),42},
	{LOC("alternate_line_nl_no_nl"),42},
	{LOC("alternate_line_nl_with_nl"),42},
	{LOC("big_line_no_nl"),42},
	{LOC("big_line_with_nl"),42},
	{LOC("empty"),42},
	{LOC("multiple_line_no_nl"),42},
	{LOC("multiple_line_with_nl"),42},
	{LOC("multiple_nlx5"),42},
	{LOC("nl"),42}
};

int tests_buffer_42()
{
	return (arraysize(buffer_42_tests));
}

void	test_buffer_42(int n, bool detail)
{
	gnlcore(buffer_42_tests[n], n, detail);
}
