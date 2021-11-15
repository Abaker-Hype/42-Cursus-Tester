#include "tester.h"

typedef struct s_case{
	int count;
	int size;
} t_case;

t_case calloc_tests[] = {
	{20, sizeof(char)},
	{0,sizeof(char)}
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
	if (detail) testinfo("ii", n + 1, test.count, test.size);
	void *result = ft_calloc(test.count, test.size);
	void *expected = calloc(test.count, test.size);
	if (!result || memcmp(result, expected, calloc_tests[n].count) != 0)pass = false;
	if (detail) resultinfo("v", result, test.count * test.size, expected, test.count * test.size);
	if (result) free_track(result, true);
	if (expected) free(expected);
	if (pass)setgrade(PASS);
}
