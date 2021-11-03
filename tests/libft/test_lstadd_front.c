#include "tester.h"

typedef struct s_case{
	t_list lst;
	bool null;
} t_case;

t_case lstadd_front_tests[] = {
	{{"string", NULL}},
	{NULL},
	{{}, true}
};

int tests_lstadd_front()
{
	return (arraysize(lstadd_front_tests));
}

bool exists_lstadd_front()
{
	return (ft_lstadd_front != NULL);
}

void	test_lstadd_front(int n, bool detail)
{
	bool pass = true;
	t_case test = lstadd_front_tests[n];
	t_list node = {"Something", NULL};
	t_list *result = NULL, *expected = NULL, *add = NULL;
	if (test.lst.content) add = &test.lst;
	if (!test.null){
		result = &node;
		expected = &node;
	}
	if (detail){
		if (!test.null) testinfo("*s*s", n + 1, "1st in list", node.content, "To be added", test.lst.content);
	   	else testinfo("*s*s", n + 1, "1st in list", NULL, "To be added", test.lst.content);	
	}
	ft_lstadd_front(&result, add);
	lstadd_front(&expected, add);
	if (result != expected) pass = false;
	if (detail){
		char *r = NULL, *e = NULL;
		if (result) r = result->content;
		if (expected) e = expected->content;
		resultinfo("*s","1st in list", r, "1st in list", e);
	}
	if (pass) setgrade(PASS);
}
