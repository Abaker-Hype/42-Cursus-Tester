#include "tester.h"

typedef struct s_case{
	char *str;	
} t_case;

t_case putstr_fd_tests[] = {
	{"LOOK OUT JOHNNY!"},
	{"012345679"},
	{"／人 ◕ ‿‿ ◕ 人＼"},
	{NULL}
};

int tests_putstr_fd()
{
	return (arraysize(putstr_fd_tests));
}

bool exists_putstr_fd()
{
	return (ft_putstr_fd != NULL);
}

void	test_putstr_fd(int n, bool detail)
{
	bool pass = true;
	t_case test = putstr_fd_tests[n];
	char *expected = NULL;
	int len = 0;
	if (detail) testinfo("si", n + 1, test.str, 1);
	ft_putstr_fd(test.str, 1);
	if (test.str){
		len = strlen(test.str);
		asprintf(&expected, "%s", test.str);
	}
	if (!checkoutput(expected, len)) pass = false;
	if (detail) resultinfo("s", useroutput(), expected);
	if (expected) free(expected);
	if (pass) setgrade(PASS);
}
