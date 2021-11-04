#include "tester.h"

typedef struct s_case{
		char *str;
} t_case;

t_case basic_tests[] = {
	{""},
	{"Simple Print"},
	{"HELP ME PLEASE I AM GOING INSANE!"},
	{"Line 1\nLine 2"},
	{"\r\v\t\n\f"}
};

int tests_basic()
{
	return (arraysize(basic_tests));
}

void	test_basic(int n, bool detail)
{
	t_case test = basic_tests[n];
	if (detail) testinfo("s", n + 1, test.str);
	printfcore(test.str, NULL);
}
