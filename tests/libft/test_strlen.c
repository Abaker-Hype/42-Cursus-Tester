#include "libft.h"
#include "tester.h"

typedef struct s_case{
	char *str;
} t_case;

t_case strlen_tests[] = {
	{""},
	{"         "},
	{"abc def ghi"},
	{"177013"},
	{"\n\f\r\\\t"},
	{"test\0test"}
};

int tests_strlen()
{
	return (arraysize(strlen_tests));
}

bool exists_strlen()
{
	return (ft_strlen != NULL);
}

void	test_strlen(int n)
{
	int result = ft_strlen(strlen_tests[n].str);
	int expected = strlen(strlen_tests[n].str);
	if (result != expected) return;
	setgrade(PASS);
}
