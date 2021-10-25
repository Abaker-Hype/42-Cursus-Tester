#include "libft.h"
#include "tester.h"

typedef struct s_case{
	char *str1;
	char *str2;
	int len;
	int expected;
} t_case;

t_case strncmp_tests[] = {

};

int tests_strncmp()
{
	return (arraysize(strncmp_tests));
}

bool exists_strncmp()
{
	return (ft_strncmp != NULL);
}

void	test_strncmp(int n)
{
	setgrade(PASS);
}
