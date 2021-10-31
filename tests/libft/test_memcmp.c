#include "tester.h"

typedef struct s_case{
	char *s1;
	char *s2;
	int len;
	bool segv;
} t_case;

t_case memcmp_tests[] = {
	{"test","test",4},
	{"tests","test",5},
	{"testt","tests",5},
	{"","a",1},
	{NULL, "test", 4, true},
	{"test", NULL, 4, true},
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
	int result, expected;
	if (test.segv)passsegv();
	if (detail) testinfo("ssi", n + 1, test.s1, test.s2, test.len);
	result = ft_memcmp(test.s1, test.s2, test.len);
	if (!test.segv)expected = memcmp(test.s1, test.s2, test.len);
	if (result == 0 && expected != 0) pass = false;
	else if((result & 0x80) != (expected & 0x80)) pass = false;
	if (detail){
		resultinfo("i", result, expected);
		cprintf("Note on Linux memcmp returns different numbers sometimes so only base off the sign\n", YELLOW, DEFAULT);
	}
	if (pass) setgrade(PASS);
}
