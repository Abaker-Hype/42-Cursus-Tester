#include "tester.h"

typedef struct s_case{
	char *str;
	int c;
	bool segv;
} t_case;

t_case strchr_tests[] = {
	{NULL, ' ', true},
	{"NULL", '\0'},
	{"abc", 'b'},
	{"abbc", 'b'},
	{"abc", 'd'},
	{"abc", 'a' + 256}
};

int tests_strchr()
{
	return (arraysize(strchr_tests));
}

bool exists_strchr()
{
	return (ft_strchr != NULL);
}

void	test_strchr(int n, bool detail)
{
	bool pass = true;
	t_case test = strchr_tests[n];
	char *result, *expected = NULL;
	if (test.segv) passsegv();
	if (detail) testinfo("sc", n + 1, test.str, test.c);
	result = ft_strchr(test.str, test.c);
	if (!test.segv)expected = strchr(test.str, test.c);
	if (result != expected) pass = false;
	if(detail) resultinfo("s", result, expected);
	if (pass) setgrade(PASS);
}
