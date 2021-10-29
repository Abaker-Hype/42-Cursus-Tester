#include "tester.h"

typedef struct s_case{
	int	start;
	int end;
} t_case;

t_case isprint_tests[] = {
	{0, 31},
	{32, 126},
	{127, 127}
};

int tests_isprint()
{
	return (arraysize(isprint_tests));
}

bool exists_isprint()
{
	return (ft_isprint != NULL);
}

void	test_isprint(int n, bool detail)
{
	bool pass = true;
	t_case test = isprint_tests[n];
	int result, expected;
	if (detail) testinfo("*i*i", n + 1, "loop range", test.start, "to", test.end);
	for (int start = test.start; start <= test.end; start++){
		result = ft_isprint(start);
		expected = isprint(start);
		if (expected > 0) expected = 1;
		if (result != expected){
			pass = false;
			break;
		}
	}
	if (detail) resultinfo("i", result, expected);
	if (pass) setgrade(PASS);
}
