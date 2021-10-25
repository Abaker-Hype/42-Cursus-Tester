#include "libft.h"
#include "tester.h"
#include <strings.h>

typedef struct s_case{
	char *str;
	char c;
} t_case;

t_case strrchr_tests[] = {
	{NULL, ' '},
	{"NULL", '\0'},
	{"abc", 'b'},
	{"abbc", 'b'},
	{"abc", 'd'}
};

int tests_strrchr()
{
	return (arraysize(strrchr_tests));
}

bool exists_strrchr()
{
	return (ft_strrchr != NULL);
}

void	test_strrchr(int n)
{
	t_case test = strrchr_tests[n];
	char *result = ft_strrchr(test.str, test.c);
	char *expected = NULL;
	if (test.str) expected = strrchr(test.str, test.c);
	if (result != expected) return ;
	setgrade(PASS);
}
