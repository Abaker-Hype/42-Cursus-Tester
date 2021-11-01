#include "tester.h"

typedef struct s_case{
	int start;
	int len;
	bool segv;
} t_case;

t_case substr_tests[] = {
	{0, 15},
	{15, 15},
	{0, 0},
	{15, 0},
	{50, 5},
	{35, 10},
	{0, 5, true}
};

int tests_substr()
{
	return (arraysize(substr_tests));
}

bool exists_substr()
{
	return (ft_substr != NULL);
}

void	test_substr(int n, bool detail)
{
	bool pass = true;
	char *str = "Some random string to get a substr from";
	char *result, *expected;
	t_case test = substr_tests[n];
	if (test.segv) str = NULL;
	if (detail) testinfo("sii", n + 1, str, test.start, test.len);
	result = ft_substr(str, test.start, test.len);
	expected = substr(str, test.start, test.len);
	if (result && (!expected || result == str || strcmp(result, expected) != 0)) pass = false;
	else if (!result && result != expected) pass = false;
	if (detail) resultinfo("s", result, expected);
	if (result && result != str) free_track(result);
	if (expected) free(expected);
	if (pass) setgrade(PASS);
}
