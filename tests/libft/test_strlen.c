#include "tester.h"

typedef struct s_case{
	char *str;
	char *input;
} t_case;

t_case strlen_tests[] = {
	{"","str[]"},
	{"        ","str[        ]"},
	{"abc def ghi","str[abc def ghi]"},
	{"177013","str[177013]"},
	{"\n\f\r\\\t","str[\\n\\f\\r\\\\\\t]"},
	{"test\0test","str[test\\0test]"}
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
	if (detail) cprintf(TESTINFO, LBLUE, DEFAULT, YELLOW, n + 1, LBLUE, RED, test.input);
	int result = ft_strlen(test.str);
	int expected = strlen(test.str);
	if (result != expected) pass = false;
	if (detail) cprintf(TESTINTRSLT, LBLUE, DEFAULT, YELLOW, result, LBLUE, YELLOW, expected);
	if (pass) setgrade(PASS);
}
