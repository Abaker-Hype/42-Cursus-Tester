#include "tester.h"
#define LOC(x) "tests/gnl/files/" "" x

gnltest buffer_215600_tests[] = {
	{LOC("41_no_nl"), 215600},
	{LOC("41_with_nl"),215600},
	{LOC("42_no_nl"),215600},
	{LOC("42_with_nl"),215600},
	{LOC("43_no_nl"),215600},
	{LOC("43_with_nl"),215600},
	{LOC("alternate_line_nl_no_nl"),215600},
	{LOC("alternate_line_nl_with_nl"),215600},
	{LOC("big_line_no_nl"),215600},
	{LOC("big_line_with_nl"),215600},
	{LOC("empty"),215600},
	{LOC("multiple_line_no_nl"),215600},
	{LOC("multiple_line_with_nl"),215600},
	{LOC("multiple_nlx5"),215600},
	{LOC("nl"),215600}
};

int tests_buffer_215600()
{
	return (arraysize(buffer_215600_tests));
}

void	test_buffer_215600(int n, bool detail)
{
	gnlcore(buffer_215600_tests[n], n, detail);
}
