#include "tester.h"

typedef struct s_case{
	char *input;	
} t_case;

t_case <name>_tests[] = {

};

int tests_<name>()
{
	return (arraysize(<name>_tests));
}

bool exists_<name>()
{
	return (ft_<name> != NULL);
}

void	test_<name>(int n, bool detail)
{
	bool pass = true;
	t_case test = <name>_tests[n];
	if (detail) cprintf(TESTINFO, LBLUE, DEFAULT, YELLOW, n + 1, LBLUE, RED, test.input);
	//Tests here
	if (detail) cprintf(TEST<type>RSLT, LBLUE, DEFAULT, YELLOW, result, LBLUE, YELLOW, expected);
	if (pass) setgrade(PASS);
}
