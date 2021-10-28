#include "tester.h"

typedef struct s_case{
	int start;
	int end;
	char *input;
} t_case;

t_case isalnum_tests[] = {
	{-1, 47, "loop range int[-1 - 47]"},
	{'0', '9', "loop range char['0' - '9']"},
	{58, 64, "loop range int[58 - 65]"},
	{'A', 'Z', "loop range int['A' - 'Z']"},
	{91, 96, "loop range int[91 - 96]"},
	{'a', 'z', "loop range int['a' - 'z']"},
	{123, 128, "loop range int[123 - 128]"}
};

int tests_isalnum()
{
	return (arraysize(isalnum_tests));
}

bool exists_isalnum()
{
	return (ft_isalnum != NULL);
}

void	test_isalnum(int n, bool detail)
{
	bool pass = true;
	t_case test = isalnum_tests[n];
	int result, expected;
	if (detail) cprintf(TESTINFO, LBLUE, DEFAULT, YELLOW, n + 1, LBLUE, RED, test.input);
	for (int start = test.start; start <= test.end; start++){
		result = ft_isalnum(start);
		expected = isalnum(start);
		if (expected > 0) expected = 1;
		if (result != expected){
			pass = false;
			break;
		}
	}
	if (detail) cprintf(TESTINTRSLT, LBLUE, DEFAULT, YELLOW, result, LBLUE, YELLOW, expected);
	if (pass) setgrade(PASS);
}
