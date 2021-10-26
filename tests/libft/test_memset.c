#include "tester.h"

typedef struct s_case{
	char c;
	int len;
} t_case;

t_case memset_tests[] = {
	{'b', 10},
	{'b', 5},
	{'b', 0}
};

int tests_memset()
{
	return (arraysize(memset_tests));
}

bool exists_memset()
{
	return (ft_memset != NULL);
}

void	test_memset(int n)
{
	bool pass = true;
	void *s1 = malloc(sizeof(char) * 15);
	void *s2 = malloc(sizeof(char) * 15);
	memset(s1, 'a', 15);
	memset(s2, 'a', 15);
	ft_memset(s1, memset_tests[n].c, memset_tests[n].len);
	memset(s2, memset_tests[n].c, memset_tests[n].len);
	if (memcmp(s1, s2, 15) != 0) pass = false;
	free(s1);
	free(s2);
	if (pass) setgrade(PASS);
}
