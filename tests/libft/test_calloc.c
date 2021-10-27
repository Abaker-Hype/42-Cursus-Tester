#include "macros.h"
#include "tester.h"

typedef struct s_case{
	int count;
} t_case;

t_case calloc_tests[] = {
	{20},
	{0}
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
	void *result = ft_calloc(calloc_tests[n].count, sizeof(char));
	void *expected = calloc(calloc_tests[n].count, sizeof(char));
	if (!result || memcmp(result, expected, calloc_tests[n].count) != 0)pass = false;
	if (result) free(result);
	free(expected);
	if (pass)setgrade(PASS);
}
