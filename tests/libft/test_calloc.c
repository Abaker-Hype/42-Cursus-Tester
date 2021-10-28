#include "macros.h"
#include "tester.h"

typedef struct s_case{
	int count;
	int size;
	char *input;
} t_case;

t_case calloc_tests[] = {
	{20, sizeof(char), "int[20] int[sizeof(char)]"},
	{0,sizeof(char), "int[0] int[sizeof(char)]"}
};

int tests_calloc()
{
	return (arraysize(calloc_tests));
}

bool exists_calloc()
{
	return (ft_calloc != NULL);
}

void	test_calloc(int n, bool detail)
{
	bool pass = true;
	t_case test = calloc_tests[n];
	if (detail) cprintf(TESTINFO, LBLUE, DEFAULT, YELLOW, n + 1, LBLUE, RED, test.input);
	void *result = ft_calloc(test.count, test.size);
	void *expected = calloc(test.count, test.size);
	if (!result || memcmp(result, expected, calloc_tests[n].count) != 0)pass = false;
	if (result) free(result);
	if (expected) free(expected);
	if (pass)setgrade(PASS);
}
