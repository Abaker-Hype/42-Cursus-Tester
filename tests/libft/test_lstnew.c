#include "tester.h"

typedef struct s_case{
	void *data;	
} t_case;

t_case lstnew_tests[] = {
	{"String"},
	{NULL}
};

int tests_lstnew()
{
	return (arraysize(lstnew_tests));
}

bool exists_lstnew()
{
	return (ft_lstnew != NULL);
}

void	test_lstnew(int n, bool detail)
{
	bool pass = true;
	t_case test = lstnew_tests[n];
	if (detail) testinfo("s", n + 1, test.data);
	t_list *result, *expected;
	result = ft_lstnew(test.data);
	expected = lstnew(test.data);
	if (!result || result->content != expected->content) pass = false;
	if (detail) resultinfo("s", result->content, expected->content);
	if (result) free_track(result, true);
	free(expected);
	if (pass) setgrade(PASS);
}
