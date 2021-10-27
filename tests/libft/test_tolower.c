#include "tester.h"

typedef struct s_case{
	int start;
	int end;
} t_case;

t_case tolower_tests[] = {
	{0, 64},
	{65, 90},
	{91, 127}
};

int tests_tolower()
{
	return (arraysize(tolower_tests));
}

bool exists_tolower()
{
	return (ft_tolower != NULL);
}

void	test_tolower(int n, bool detail)
{
	for (int start = tolower_tests[n].start; start <= tolower_tests[n].end; start++){
		int result = ft_tolower(start);
		int expected = tolower(start);
		if (result != expected) return ;
	}
	setgrade(PASS);
}
