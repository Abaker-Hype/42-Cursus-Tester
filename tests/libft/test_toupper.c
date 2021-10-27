#include "tester.h"

typedef struct s_case{
	int start;
	int end;
} t_case;

t_case toupper_tests[] = {
	{0, 96},
	{97, 122},
	{123, 127}
};

int tests_toupper()
{
	return (arraysize(toupper_tests));
}

bool exists_toupper()
{
	return (ft_toupper != NULL);
}

void	test_toupper(int n, bool detail)
{
	for (int start = toupper_tests[n].start; start <= toupper_tests[n].end; start++){
		int result = ft_toupper(start);
		int expected = toupper(start);
		if (result != expected) return ;
	}
	setgrade(PASS);
}
