#include "tester.h"

typedef struct s_case{
	int start;
	int end;
} t_case;

t_case isascii_tests[] = {
	{-1, -1},
	{0, 127},
	{128, 128}
};

int tests_isascii()
{
	return (arraysize(isascii_tests));
}

bool exists_isascii()
{
	return (ft_isascii != NULL);
}

void	test_isascii(int n, bool detail)
{
	bool pass = true;
	t_case test = isascii_tests[n];
	int result, expected;
	if (detail) testinfo("*i*i", n + 1, "loop range", test.start, "to", test.end);
	for(int start = test.start; start <= test.end; start++){
		result = ft_isascii(start);
		expected = isascii(start);
		if (expected > 0) expected = 1;
		if (result != expected){
			pass = false;
			break;
		}
	}
	if (detail) resultinfo("i", result, expected);
	if (pass) setgrade(PASS);
}
