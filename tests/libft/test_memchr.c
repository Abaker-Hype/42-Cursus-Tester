#include "tester.h"

typedef struct s_case{
	void *mem;
	int c;
	int len;
	int arry[6];
} t_case;

t_case memchr_tests[] = {
	{"test",'t', 4, {}},
	{"test",'s', 4, {}},
	{"test",'s', 2, {}},
	{"test",'a', 5, {}},
	{NULL, 1, 6, {42,-42, 0,1,-1,177013}}
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
	t_case test = memchr_tests[n];
	char *result, *expected;
	if (test.mem){	
		result = ft_memchr(test.mem, test.c, test.len);
		expected = memchr(test.mem, test.c, test.len);
	} else {
		result = ft_memchr(test.arry, test.c, test.len);
		expected = memchr(test.arry, test.c, test.len);
	}
	if (result != expected)return;
	setgrade(PASS);
}
