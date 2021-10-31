#include "tester.h"

typedef struct s_case{
	char c;
	int len;
} t_case;

t_case memset_tests[] = {
	{'b', 10},
	{'b', 5},
	{'b', 0},
	{'\0', 15}
};

int tests_memset()
{
	return (arraysize(memset_tests));
}

bool exists_memset()
{
	return (ft_memset != NULL);
}

void	test_memset(int n, bool detail)
{
	bool pass = true;
	t_case test = memset_tests[n];
	void *s1 = malloc(sizeof(char) * 15);
	void *s2 = malloc(sizeof(char) * 15);
	memset(s1, 'a', 15);
	memset(s2, 'a', 15);
	if (detail) testinfo("vci", n + 1, s1, 15, test.c, test.len);
	ft_memset(s1, test.c, test.len);
	memset(s2, test.c, test.len);
	if (memcmp(s1, s2, 15) != 0) pass = false;
	if (detail) resultinfo("v", s1, 15, s2, 15);
	free(s1);
	free(s2);
	if (pass) setgrade(PASS);
}
