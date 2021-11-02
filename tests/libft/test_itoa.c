#include "tester.h"

typedef struct s_case{
	int n;	
} t_case;

t_case itoa_tests[] = {
	{0},
	{-0},
	{42},
	{-42},
	{215600},
	{-215600},
	{2147483647},
	{-2147483648},
};

int tests_itoa()
{
	return (arraysize(itoa_tests));
}

bool exists_itoa()
{
	return (ft_itoa != NULL);
}

void	test_itoa(int n, bool detail)
{
	bool pass = true;
	t_case test = itoa_tests[n];
	char *result, *expected;
	if (detail) testinfo("i", n + 1, test.n);
	result = ft_itoa(test.n);
	expected = itoa(test.n);
	if (!result || strcmp(result, expected) != 0) pass = false;
	if (detail) resultinfo("s", result, expected);
	if (result) free_track(result);
	free(expected);
	if (pass) setgrade(PASS);
}
