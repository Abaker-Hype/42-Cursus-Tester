#include "tester.h"

typedef struct s_case{
	char *str;
	bool segv;
} t_case;

t_case strdup_tests[] = {
	{"This is probably a test"},
	{""},
	{NULL, true}
};

int tests_strdup()
{
	return (arraysize(strdup_tests));
}

bool exists_strdup()
{
	return (ft_strdup != NULL);
}

void	test_strdup(int n, bool detail)
{
	bool pass = true;
	t_case test = strdup_tests[n];
	char *result, *expected= NULL;
	if (test.segv) passsegv();
	if (detail) testinfo("s", n + 1, test.str);
	result = ft_strdup(test.str);
	if (!test.segv)expected = strdup(test.str);
	if (!result && result != expected) pass = false;
	else if (result && (result == test.str || memcmp(result, expected, strlen(test.str)) != 0))pass = false; 
	if (detail) resultinfo("s", result, expected);
	if (result && result != test.str) free_track(result);
	free(expected);
	if (pass)setgrade(PASS);
}
