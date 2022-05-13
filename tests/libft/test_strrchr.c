#include "tester.h"

typedef struct s_case{
	char *str;
	int slen;
	int c;
	bool segv;
} t_case;

t_case strrchr_tests[] = {
	{NULL, 0, ' ', true},
	{"NULL", 4, '\0'},
	{"abc", 3, 'b'},
	{"abbbbbbbbc", 10, 'b'},
	{"abc", 3, 'd'},
	{"abc\0zyx", 7, 'z'},
	{"abc", 3, 'a' + 256}
};

int tests_strrchr()
{
	return (arraysize(strrchr_tests));
}

bool exists_strrchr()
{
	return (ft_strrchr != NULL);
}

void	test_strrchr(int n, bool detail)
{
	bool pass = true;
	t_case test = strrchr_tests[n];
	char *result, *expected = NULL;
	if (test.segv) passsegv();
	if (detail) testinfo("vc", n + 1, test.str, test.slen, test.c);
	result= ft_strrchr(test.str, test.c);
	if (!test.segv) expected = strrchr(test.str, test.c);
	if (result != expected) pass = false ;
	if (detail) resultinfo("s", result, expected);
	if (pass) setgrade(PASS);
}
