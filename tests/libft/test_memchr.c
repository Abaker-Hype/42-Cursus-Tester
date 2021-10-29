#include "tester.h"

typedef struct s_case{
	void *mem;
	int memlen;
	int c;
	int len;
} t_case;

t_case memchr_tests[] = {
	{"test", 4, 't', 4},
	{"test", 4,'s', 4},
	{"test", 4,'s', 2},
	{"test", 4,'a', 5},
	{"abcde\0zyxw", 10, 'z', 10},
	{"potatoes", 8, '\0', 9},
	{NULL, 0, '\0', 3}
};

int tests_memchr()
{
	return (arraysize(memchr_tests));
}

bool exists_memchr()
{
	return (ft_memchr != NULL);
}

void	test_memchr(int n, bool detail)
{
	bool pass = true;
	t_case test = memchr_tests[n];
	char *result, *expected = NULL;
	if (!test.mem)passsegv();
	if (detail) testinfo("vci", n + 1, test.mem, test.memlen, test.c, test.len);
	result = ft_memchr(test.mem, test.c, test.len);
	if (test.mem)expected = memchr(test.mem, test.c, test.len);
	if (result != expected) pass = false;
	if (detail) resultinfo("s", result, expected);
	if (pass) setgrade(PASS);
}
