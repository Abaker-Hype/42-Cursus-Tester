#include "tester.h"

typedef struct s_case{
	char *cpy;
	int len;
} t_case;

t_case memcpy_tests[] = {
	{"abcdefghijklmnop", 10},
	{"abcdefghijklmnop", 0},
	{"ab\0cd\0ef\0gh",11}
};

int tests_memcpy()
{
	return (arraysize(memcpy_tests));
}

bool exists_memcpy()
{
	return (ft_memcpy != NULL);
}

void	test_memcpy(int n)
{
	bool pass = true;
	t_case test = memcpy_tests[n];
	void *mem1 = malloc(sizeof(char) * 20);
	void *mem2 = malloc(sizeof(char) * 20);
	memset(mem1, 'a', 20);
	memset(mem2, 'a', 20);
	mem1 = ft_memcpy(mem1, test.cpy, test.len);
	mem2 = memcpy(mem2, test.cpy, test.len);
	if (memcmp(mem1,mem2, 20) != 0)pass = false;
	free(mem1);
	free(mem2);
	if (pass)setgrade(PASS);
}
