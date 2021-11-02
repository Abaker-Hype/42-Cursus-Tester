#include "tester.h"

typedef struct s_case{
	char *str;
} t_case;

t_case strmapi_tests[] = {
	{"abcde12345"},
	{""},
	{NULL}
};

int tests_strmapi()
{
	return (arraysize(strmapi_tests));
}

bool exists_strmapi()
{
	return (ft_strmapi != NULL);
}

static char apply(unsigned int n, char c){
	return (c + n);
}

void	test_strmapi(int n, bool detail)
{
	bool pass = true;
	t_case test = strmapi_tests[n];
	char *result, *expected;
	if (detail) testinfo("s", n + 1, test.str);
	result = ft_strmapi(test.str, &apply);
	expected = strmapi(test.str, &apply);
	if ((!result && expected) || (result && (!expected || strcmp(result, expected) != 0))) pass = false;
	if (detail) resultinfo("s", result, expected);
	if (result) free_track(result);
	if (expected) free(expected);
	if (pass) setgrade(PASS);
}
