#include "libft.h"
#include "tester.h"

typedef struct s_case{
	int start;
	int end;
	int expected;
} t_case;

t_case tolower_tests[] = {
	{0, 64, 0},
	{65, 90, 32},
	{91, 127, 0}
};

int tests_tolower()
{
	return (arraysize(tolower_tests));
}

bool exists_tolower()
{
	return (ft_tolower != NULL);
}

void	test_tolower(int n)
{
	for (int start = tolower_tests[n].start; start <= tolower_tests[n].end; start++){
		int result = ft_tolower(start);
		if (result != tolower_tests[n].expected + start) return ;
	}
	setgrade(PASS);
}
