#include "tester.h"

typedef struct s_case{
	char *str;
	bool segv;
} t_case;

t_case putendl_fd_tests[] = {
	{"LOOK OUT JOHNNY!"},
	{"012345679"},
	{"／人 ◕ ‿‿ ◕ 人＼"},
	{"\n\n\n\n\n\n\n\n\n"},
	{NULL, true}
};

int tests_putendl_fd()
{
	return (arraysize(putendl_fd_tests));
}

bool exists_putendl_fd()
{
	return (ft_putendl_fd != NULL);
}

void	test_putendl_fd(int n, bool detail)
{
	bool pass = true;
	t_case test = putendl_fd_tests[n];
	char *expected = NULL;
	if (test.segv) passsegv();
	int len = 0;
	if (detail) testinfo("si", n + 1, test.str, 1);
	ft_putendl_fd(test.str, 1);
	if (test.str){
		len = strlen(test.str) + 1;
		asprintf(&expected, "%s\n", test.str);
	}
	if (!checkoutput(expected, len)) pass = false;
	if (detail) resultinfo("s", useroutput(), expected);
	if (expected) free(expected);
	if (pass) setgrade(PASS);
}
