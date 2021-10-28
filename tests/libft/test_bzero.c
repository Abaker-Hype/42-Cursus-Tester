#include "tester.h"

typedef struct s_case{
	int len;
	char *input;
} t_case;

t_case bzero_tests[] = {
	{10, "void[aaaaaaaaaa] int[10]"},
	{5, "void[aaaaaaaaaa] int[5]"},
	{0, "void[aaaaaaaaaa] int[0]"}
};

int tests_bzero()
{
	return (arraysize(bzero_tests));
}

bool exists_bzero()
{
	return (ft_bzero != NULL);
}

void	test_bzero(int n, bool detail)
{
	bool pass = true;
	t_case test = bzero_tests[n];
	char *mem1 = strdup("aaaaaaaaaa");
	char *mem2 = strdup("aaaaaaaaaa");
	if (detail) cprintf(TESTINFO, LBLUE, DEFAULT, YELLOW, n + 1, LBLUE, RED, test.input);
	ft_bzero(mem1,test.len);
	bzero(mem2, test.len);
	if (memcmp(mem1, mem2, 10) != 0)pass = false;
	if (detail) cprintf(TESTSTRRSLT, LBLUE, DEFAULT, YELLOW, mem1, LBLUE, YELLOW, mem2);
	free(mem1);
	free(mem2);
	if (pass) setgrade(PASS);
}
