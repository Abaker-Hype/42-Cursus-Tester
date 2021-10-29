#include "tester.h"

typedef struct s_case{
	char *str;
} t_case;

t_case strlen_tests[] = {
	{""},
	{"        "},
	{"abc def ghi"},
	{"177013"},
	{"\n\f\r\\\t"},
	{"test\0test"},
	{NULL}
};

int tests_strlen()
{
	return (arraysize(strlen_tests));
}

bool exists_strlen()
{
	return (ft_strlen != NULL);
}

void	test_strlen(int n, bool detail)
{
	bool pass = true;
	t_case test = strlen_tests[n];
	int result, expected = 0;
	if (!test.str)passsegv();
	if (detail && n != 5) testinfo("s", n + 1, test.str);
	else if (detail && n == 5) testinfo("v", 6, test.str, 9);
	result = ft_strlen(test.str);
	if (test.str)expected = strlen(test.str);
	if (result != expected) pass = false;
	if (detail) resultinfo("i", result, expected);
	if (pass) setgrade(PASS);
}
