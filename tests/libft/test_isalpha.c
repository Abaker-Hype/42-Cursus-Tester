#include "tester.h"

typedef struct s_case {
	int start;
	int end;
} t_case;

t_case isalpha_tests[] = {
	{-1, 47},
	{'0', '9'},
	{58, 64},
	{'A', 'Z'},
	{91, 96},
	{'a', 'z'},
	{123, 530}
};

int	tests_isalpha()
{
	return (arraysize(isalpha_tests));
}

bool	exists_isalpha()
{
	return (ft_isalpha != NULL);
}

void	test_isalpha(int n, bool detail)
{
	bool pass = true;
	t_case test = isalpha_tests[n];
	int result, expected;
	if (detail) testinfo("*i*i", n + 1, "loop range", test.start, "to", test.end);
	for (int start = test.start; start <= test.end; start++){
		result = ft_isalpha(start);
		expected = isalpha(start);
		if (expected > 0) expected = 1;
		if (result != expected){
			pass = false;
			break;
		}
	}
	if (detail) resultinfo("i", result, expected);
	if (pass)setgrade(PASS);
}
