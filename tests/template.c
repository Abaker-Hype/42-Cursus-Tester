#include "tester.h"

typedef struct s_case{
		
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
	if (detail) testinfo("", n + 1,...);
	//Tests here
	if (result != expected) pass = false;
	if (detail) resultinfo("", result, expected);
	if (pass) setgrade(PASS);
}
