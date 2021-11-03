#include "tester.h"

typedef struct s_case{
	int size;	
} t_case;

t_case lstlast_tests[] = {
	{1},
	{20},
	{0}
};

int tests_lstlast()
{
	return (arraysize(lstlast_tests));
}

bool exists_lstlast()
{
	return (ft_lstlast != NULL);
}

void	test_lstlast(int n, bool detail)
{
	bool pass = true;
	t_case test = lstlast_tests[n];
	t_list *start = genlist(test.size);
	t_list *result, *expected;
	if (detail) testinfo("*i", n + 1, "list with elements", test.size);
	result = ft_lstlast(start);
	expected = lstlast(start);
	if (result != expected) pass = false;
	if (detail){
		char *r = NULL, *e = NULL;
		if (result) r = result->content;
		if (expected) e = expected->content;
		resultinfo("*s","Last contains data", r,"Last contains data", e);
	}
	freelst(start);
	if (pass) setgrade(PASS);
}
