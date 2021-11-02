#include "tester.h"

typedef struct s_case{
	char c;	
} t_case;

t_case putchar_fd_tests[] = {
	{'a'},
	{'\0'}
};

int tests_putchar_fd()
{
	return (arraysize(putchar_fd_tests));
}

bool exists_putchar_fd()
{
	return (ft_putchar_fd != NULL);
}

void	test_putchar_fd(int n, bool detail)
{
	bool pass = true;
	t_case test = putchar_fd_tests[n];
	char *expected;
	if (detail) testinfo("ci", n + 1, test.c, 1);
	ft_putchar_fd(test.c, 1);
	asprintf(&expected, "%c", test.c);
	if (!checkoutput(expected, 1)) pass = false;
	if (detail) resultinfo("s", useroutput(), expected);
	if (expected) free(expected);
	if (pass) setgrade(PASS);
}
