#include "macros.h"
#include "tester.h"

typedef struct s_case{
	char *str;
	int len;
} t_case;

t_case strdup_tests[] = {
	{"This is probably a test",24}
};

int tests_strdup()
{
	return (arraysize(strdup_tests));
}

bool exists_strdup()
{
	return (ft_strdup != NULL);
}

void	test_strdup(int n)
{
	bool pass = true;
	t_case test = strdup_tests[n];
	char *result = ft_strdup(test.str);
	char *expected = strdup(test.str);
	if (!result || result == test.str || memcmp(result, expected, test.len) != 0)pass = false; 
	if (result && result != test.str)free(result);
	free(expected);
	if (pass)setgrade(PASS);
}
