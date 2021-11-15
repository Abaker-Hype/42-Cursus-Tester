#include "tester.h"

typedef struct s_case{
	char *s1;
	char *s2;
} t_case;

t_case strjoin_tests[] = {
	{"test", "test"},
	{"test",""},
	{"","test"},
	{"",""},
	{NULL, "test"},
	{"test", NULL}
};

int tests_strjoin()
{
	return (arraysize(strjoin_tests));
}

bool exists_strjoin()
{
	return (ft_strjoin != NULL);
}

void	test_strjoin(int n, bool detail)
{
	bool pass = true;
	t_case test = strjoin_tests[n];
	char *result, *expected;
	if (detail) testinfo("ss", n + 1, test.s1, test.s2);
	result = ft_strjoin(test.s1, test.s2);
	expected = strjoin(test.s1, test.s2);
	if ((!result && expected) || (result && (!expected || strcmp(result, expected) != 0))) pass = false;
	if (detail) resultinfo("s", result, expected);
	if (result) free_track(result, true);
	if (expected) free(expected);
	if (pass) setgrade(PASS);
}
