#include "tester.h"

typedef struct s_case {
	int start;
	int end;
	int expected;
} t_case;

t_case isdigit_tests[] = {
	{0, 47, 0},
	{'0', '9', 1},
	{58, 127, 0}
};

int	tests_isdigit()
{
	return (arraysize(isdigit_tests));
}

bool	exists_isdigit()
{
	return (ft_isdigit != NULL);
}

void	test_isdigit(int n)
{
	for (int start = isdigit_tests[n].start; start <= isdigit_tests[n].end; start++){
		int resault = ft_isdigit(start);
		if (resault != isdigit_tests[n].expected)return;
	}
	setgrade(PASS);
}
