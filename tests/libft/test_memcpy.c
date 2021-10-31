#include "tester.h"

typedef struct s_case{
	char *cpy;
	int cpylen;
	int len;
	bool segv;
} t_case;

t_case memcpy_tests[] = {
	{"abcdefghijklmnop", 16, 20},
	{"abcdefghijklmnop", 16, 10},
	{"abcdefghijklmnop", 16, 0},
	{"ab\0cd\0ef\0gh", 11, 11},
	{NULL, 0, 20, true},
	{NULL, 0, 0}
};

int tests_memcpy()
{
	return (arraysize(memcpy_tests));
}

bool exists_memcpy()
{
	return (ft_memcpy != NULL);
}

void	test_memcpy(int n, bool detail)
{
	bool pass = true;
	t_case test = memcpy_tests[n];
	void *mem1 = malloc(sizeof(char) * 20);
	void *mem2 = malloc(sizeof(char) * 20);
	memset(mem1, 'a', 20);
	memset(mem2, 'a', 20);
	if (test.segv) passsegv();
	if (detail) testinfo("vvi", n + 1, mem1, 20, test.cpy, test.cpylen, test.len);
	mem1 = ft_memcpy(mem1, test.cpy, test.len);
	if (!test.segv) mem2 = memcpy(mem2, test.cpy, test.len);
	if (memcmp(mem1,mem2, 20) != 0)pass = false;
	if (detail) resultinfo("v", mem1, 20, mem2, 20);
	free(mem1);
	free(mem2);
	if (pass)setgrade(PASS);
}
