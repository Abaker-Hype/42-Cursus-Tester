#include "tester.h"

typedef struct s_case{
	char *str;
} t_case;

t_case striteri_tests[] = {
	{"abcde12345"},
	{""},
	{NULL}
};

int tests_striteri()
{
	return (arraysize(striteri_tests));
}

bool exists_striteri()
{
	return (ft_striteri != NULL);
}

static void apply(unsigned int n, char c[])
{
	c[0] = n + '0';
}

void	test_striteri(int n, bool detail)
{
	bool pass = true;
	t_case test = striteri_tests[n];
	char *result = NULL, *expected = NULL;
	if (test.str){
		result = strdup(test.str);
		expected = strdup(test.str);
	}
	if (detail) testinfo("s", n + 1, test.str);
	ft_striteri(result, &apply);
	striteri(expected, &apply);
	if ((!result && expected) || (result && (!expected || strcmp(result, expected) != 0))) pass = false;
	if (detail) resultinfo("s", result, expected);
	if (result) free(result);
	if (expected) free(expected);
	if (pass) setgrade(PASS);
}
