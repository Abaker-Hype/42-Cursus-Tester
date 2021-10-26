#include "tester.h"

typedef struct s_case{
	char *s1;
	char *s2;
	int len;
} t_case;

t_case memcmp_tests[] = {
	{"test","test",4},
	{"tests","test",5},
	{"","a",1},
	{"a","",1},
	{"a\0","a\200",2},
	{"123456789","123459876", 5},
	{"123456789","123459876", 9},
	{"987654321","123456789",0}
};

int tests_memcmp()
{
	return (arraysize(memcmp_tests));
}

bool exists_memcmp()
{
	return (ft_memcmp != NULL);
}

void	test_memcmp(int n)
{
	t_case test = memcmp_tests[n];
	int result = ft_memcmp(test.s1, test.s2, test.len);
	int expected = memcmp(test.s1, test.s2, test.len);
	if (result != expected)return;
	setgrade(PASS);
}
