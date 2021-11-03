#include "tester.h"

typedef struct s_case{
	int size;	
} t_case;

t_case lstsize_tests[] = {
	{1},
	{10},
	{0}
};

int tests_lstsize()
{
	return (arraysize(lstsize_tests));
}

bool exists_lstsize()
{
	return (ft_lstsize != NULL);
}

void	test_lstsize(int n, bool detail)
{
	bool pass = true;
	t_case test = lstsize_tests[n];
	t_list *start = genlist(test.size);
	if (detail) testinfo("*i", n + 1, "List with elements", test.size);
	int result = ft_lstsize(start);
	if (result != test.size) pass = false;
	if (detail) resultinfo("i", result, test.size);
	freelst(start);
	if (pass) setgrade(PASS);
}
