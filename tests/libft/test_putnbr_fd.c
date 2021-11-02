#include "tester.h"

typedef struct s_case{
	int n;	
} t_case;

t_case putnbr_fd_tests[] = {
	{0},
	{12345679},
	{-42},
	{42},
	{177013},
	{-215600},
	{2147483647},
	{-2147483648}
};

int tests_putnbr_fd()
{
	return (arraysize(putnbr_fd_tests));
}

bool exists_putnbr_fd()
{
	return (ft_putnbr_fd != NULL);
}

void	test_putnbr_fd(int n, bool detail)
{
	bool pass = true;
	t_case test = putnbr_fd_tests[n];
	char *expected = NULL;
	if (detail) testinfo("ii", n + 1, test.n, 1);
	ft_putnbr_fd(test.n, 1);
	asprintf(&expected, "%i", test.n);
	int len = strlen(expected);
	if (!checkoutput(expected, len)) pass = false;
	if (detail) resultinfo("s", useroutput(), expected);
	if (expected) free(expected);
	if (pass) setgrade(PASS);
}
