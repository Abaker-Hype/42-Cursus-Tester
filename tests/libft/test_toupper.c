#include "tester.h"

typedef struct s_case{
	int start;
	int end;
} t_case;

t_case toupper_tests[] = {
	{0, 96},
	{97, 122},
	{123, 127}
};

int tests_toupper()
{
	return (arraysize(toupper_tests));
}

bool exists_toupper()
{
	return (ft_toupper != NULL);
}

void	test_toupper(int n, bool detail)
{
	bool pass = true;
	t_case test = toupper_tests[n];
	int result, expected;
	if (detail) testinfo("*i*i", n + 1, "loop range", test.start, "to", test.end);
	for (int start = test.start; start <= test.end; start++){
		result = ft_toupper(start);
		expected = toupper(start);
		if (result != expected){
			pass = false;
		   	break ;
		}
	}
	if (detail) resultinfo("i", result, expected);
	if (pass) setgrade(PASS);
}
