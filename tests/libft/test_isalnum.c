#include "tester.h"

typedef struct s_case{
	int start;
	int end;
	int expected;
} t_case;

t_case isalnum_tests[] = {
	{0, 47, 0},
	{'0', '9', 1},
	{58, 64, 0},
	{'A', 'Z', 1},
	{91, 96, 0},
	{'a', 'z', 1},
	{123, 127, 0}
};

int tests_isalnum()
{
	return (arraysize(isalnum_tests));
}

bool exists_isalnum()
{
	return (ft_isalnum != NULL);
}

void	test_isalnum(int n, bool detail)
{
	for (int start = isalnum_tests[n].start; start <= isalnum_tests[n].end; start++){
		int resault = ft_isalnum(start);
		if (resault != isalnum_tests[n].expected) return;
	}
	setgrade(PASS);
}
