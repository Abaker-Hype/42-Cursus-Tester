#include "tester.h"

typedef struct s_case {
	int start;
	int end;
	char *input;
} t_case;

t_case isalpha_tests[] = {
	{-1, 47, "loop range int[0 - 47]"},
	{'0', '9', "loop range char['0' - '9']"},
	{58, 64, "loop range int[58 - 64]"},
	{'A', 'Z', "loop range char['A' - 'Z']"},
	{91, 96, "loop range int[91 - 96]"},
	{'a', 'z', "loop range char['a' - 'z']"},
	{123, 530, "loop range int[123 - 530]"}
};

int	tests_isalpha()
{
	return (arraysize(isalpha_tests));
}

bool	exists_isalpha()
{
	return (ft_isalpha != NULL);
}

void	test_isalpha(int n, bool detail)
{
	bool pass = true;
	t_case test = isalpha_tests[n];
	int result, expected;
	if (detail) cprintf(TESTINFO, LBLUE, DEFAULT, YELLOW, n + 1, LBLUE, RED, test.input);
	for (int start = test.start; start <= test.end; start++){
		result = ft_isalpha(start);
		expected = isalpha(start);
		if (expected > 0) expected = 1;
		if (result != expected){
			pass = false;
			break;
		}
	}
	if (detail) cprintf(TESTINTRSLT, LBLUE, DEFAULT, YELLOW, result, LBLUE, YELLOW, expected);
	if (pass)setgrade(PASS);
}
