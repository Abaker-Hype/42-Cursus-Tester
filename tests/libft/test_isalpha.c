#include "libft.h"
#include "tester.h"

typedef struct s_case {
	int start;
	int end;
	int expected;
} t_case;

t_case isalpha_test[] = {
	{0, 47, 0},
	{'0', '9', 0},
	{58, 64, 0},
	{'A', 'Z', 1},
	{91, 96, 0},
	{'a', 'z', 1},
	{123, 127, 0}
};

int	tests_isalpha()
{
	return (arraysize(isalpha_test));
}

bool	exists_isalpha()
{
	return (ft_isalpha != NULL);
}

void	test_isalpha(int n)
{
	for (int start = isalpha_test[n].start; start <= isalpha_test[n].end; start++){
		int resault = ft_isalpha(start);
		if (resault != isalpha_test[n].expected) return;
	}
	setgrade(PASS);
}
