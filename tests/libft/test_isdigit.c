#include "tester.h"

typedef struct s_case {
	int start;
	int end;
} t_case;

t_case isdigit_tests[] = {
	{-1, 47},
	{'0', '9'},
	{58, 128}
};

int	tests_isdigit()
{
	return (arraysize(isdigit_tests));
}

bool	exists_isdigit()
{
	return (ft_isdigit != NULL);
}

void	test_isdigit(int n, bool detail)
{
	bool pass = true;
	t_case test = isdigit_tests[n];
	int result, expected;
	if (detail) testinfo("*i*i", n + 1, "loop range", test.start, "to", test.end); 
	for (int start = test.start; start <= test.end; start++){
		result = ft_isdigit(start);
		expected = isdigit(start);
		if (expected > 0) expected = 1;
		if (result != expected){
			pass = false;
			break;
		}
	}
	if (detail) resultinfo("i", result, expected);
	if (pass)setgrade(PASS);
}
