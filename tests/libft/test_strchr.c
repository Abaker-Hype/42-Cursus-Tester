#include "libft.h"
#include "tester.h"
#include <strings.h>

typedef struct s_case{
	char *str;
	char c;
} t_case;

t_case strchr_tests[] = {
	{NULL, ' '},
	{"NULL", '\0'},
	{"abc", 'b'},
	{"abbc", 'b'},
	{"abc", 'd'}
};

int tests_strchr()
{
	return (arraysize(strchr_tests));
}

bool exists_strchr()
{
	return (ft_strchr != NULL);
}

void	test_strchr(int n)
{
	t_case test = strchr_tests[n];
	char *result = ft_strchr(test.str, test.c);
	char *expected = NULL;
	if (test.str) expected = strchr(test.str, test.c);
	if (result != expected) return;
	setgrade(PASS);
}
