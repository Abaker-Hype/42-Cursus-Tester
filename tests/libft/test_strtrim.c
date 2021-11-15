#include "tester.h"

typedef struct s_case{
	char *str;
	char *set;	
} t_case;

t_case strtrim_tests[] = {
	{"basic test", " "},
	{"  basic test  ", " "},
	{"\n\r\t\v\f TACOS\t\v \n\f\r", " \r\v\n\f\t"},
	{"123abcdef","321"},
	{"abcdef123", "321"},
	{"No Set", ""},
	{"No Set", NULL},
	{"abcde177013vwxyz", "0123456789"},
	{NULL, "rip"}
};

int tests_strtrim()
{
	return (arraysize(strtrim_tests));
}

bool exists_strtrim()
{
	return (ft_strtrim != NULL);
}

void	test_strtrim(int n, bool detail)
{
	bool pass = true;
	t_case test = strtrim_tests[n];
	char *result, *expected;
	if (detail) testinfo("ss", n + 1, test.str, test.set);
	result = ft_strtrim(test.str, test.set);
	expected = strtrim(test.str, test.set);
	if ((!result && expected) || (result && (!expected || result == test.str || strcmp(result, expected) != 0))) pass = false;
	if (detail) resultinfo("s", result, expected);
	if (result) free_track(result, true);
	if (expected) free(expected);
	if (pass) setgrade(PASS);
}
