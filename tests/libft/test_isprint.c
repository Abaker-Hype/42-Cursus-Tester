#include "libft.h"
#include "tester.h"

typedef struct s_case{
	int	start;
	int end;
	int expected;
} t_case;

t_case isprint_tests[] = {
	{0, 31, 0},
	{32, 126, 1},
	{127, 127, 0}
};

int tests_isprint()
{
	return (arraysize(isprint_tests));
}

bool exists_isprint()
{
	return (ft_isprint != NULL);
}

void	test_isprint(int n)
{
	for (int start = isprint_tests[n].start; start <= isprint_tests[n].end; start++){
		int result = ft_isprint(start);
		if (result != isprint_tests[n].expected) return;
	}
	setgrade(PASS);
}
