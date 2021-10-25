#include "libft.h"
#include "tester.h"

typedef struct s_case{
	int start;
	int end;
	int expected;
} t_case;

t_case toupper_tests[] = {
	{0, 96, 0},
	{97, 122, -32},
	{123, 127, 0}
};

int tests_toupper()
{
	return (arraysize(toupper_tests));
}

bool exists_toupper()
{
	return (ft_toupper != NULL);
}

void	test_toupper(int n)
{
	for (int start = toupper_tests[n].start; start <= toupper_tests[n].end; start++){
		int result = ft_toupper(start);
		if (result != toupper_tests[n].expected + start) return ;
	}
	setgrade(PASS);
}
