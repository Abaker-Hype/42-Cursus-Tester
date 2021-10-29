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

void	test_memcmp(int n, bool detail)
{
	bool pass = true;
	t_case test = memcmp_tests[n];
	if (detail) testinfo("ssi", n + 1, test.s1, test.s2, test.len);
	int result = ft_memcmp(test.s1, test.s2, test.len);
	int expected = memcmp(test.s1, test.s2, test.len);
	if ((result & 0x80) != (expected & 0x80))pass = false;
	if (detail){
		resultinfo("i", result, expected);
		cprintf("Note on Linux memcmp returns only -1, 0, or 1. So only base off the sign\n", YELLOW, DEFAULT);
	}
	if (pass) setgrade(PASS);
}
