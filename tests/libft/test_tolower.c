#include "tester.h"

typedef struct s_case{
	int start;
	int end;
} t_case;

t_case tolower_tests[] = {
	{0, 64},
	{65, 90},
	{91, 127}
};

int tests_tolower()
{
	return (arraysize(tolower_tests));
}

bool exists_tolower()
{
	return (ft_tolower != NULL);
}

void	test_tolower(int n, bool detail)
{
	bool pass = true;
	t_case test = tolower_tests[n];
	int result, expected;
	if (detail) testinfo("*i*i", n + 1, "loop range", test.start, "to", test.end);
	for (int start = test.start; start <= test.end; start++){
		result = ft_tolower(start);
		expected = tolower(start);
		if (result != expected){
			pass = false;
			break;
		}
	}
	if (detail) resultinfo("i", result, expected);
	if (pass) setgrade(PASS);
}
