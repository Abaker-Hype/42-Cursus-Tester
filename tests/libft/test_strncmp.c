#include "tester.h"

typedef struct s_case{
	char *str1;
	char *str2;
	int len;
} t_case;

t_case strncmp_tests[] = {
	{"test", "test", 4},
	{"test", "tests", 6},
	{"tests", "test", 6},
	{"test", "teSt", 4},
	{"test", "", 4},
	{"", "test",4},
	{"123456789", "123456789", 5},
	{"12345", "12389", 4},
	{"zyx", "abc", 0},
	{"", "abc", 0},
	{"zyx", "", 0},
	{"test\200", "test\0", 6}	
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
	t_case test = strncmp_tests[n];
	int result = ft_strncmp(test.str1, test.str2, test.len);
	int expected = strncmp(test.str1, test.str2, test.len);
	if (result != expected) return;
	setgrade(PASS);
}
