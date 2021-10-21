#include "libft.h"
#include "tester.h"

typedef struct s_case{
	int start;
	int end;
	int expected;
} t_case;

t_case isascii_tests[] = {
	{-1, -1, 0},
	{0, 127, 1},
	{128, 128, 0}
};

int tests_isascii()
{
	return (arraysize(isascii_tests));
}

bool exists_isascii()
{
	return (ft_isascii != NULL);
}

void	test_isascii(int n)
{
	for(int start = isascii_tests[n].start; start <= isascii_tests[n].end; start++){
		int result = ft_isascii(start);
		if (result != isascii_tests[n].expected) return;
	}
	setgrade(PASS);
}
