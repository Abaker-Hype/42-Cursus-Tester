#include "tester.h"

typedef struct s_case{
		char *str;
} t_case;

t_case percent_tests[] = {
	{" %% "},
	{" %% %% "},
	{"w%w%w%w"},
	{"%%%%%%%%"}
};

int tests_percent()
{
	return (arraysize(percent_tests));
}

void	test_percent(int n, bool detail)
{
	t_case test = percent_tests[n];
	if (detail) testinfo("s", n + 1, test.str);
	printfcore(test.str, NULL);
}
