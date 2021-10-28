#include "tester.h"

typedef struct s_case {
	int start;
	int end;
	char *input;
} t_case;

t_case isdigit_tests[] = {
	{-1, 47, "loop range int[-1 - 47]"},
	{'0', '9', "loop range char['0' - '9']"},
	{58, 128, "loop range int[58 - 128]"}
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
	if (detail) cprintf(TESTINFO, LBLUE, DEFAULT, YELLOW, n + 1, LBLUE, RED, test.input); 
	for (int start = test.start; start <= test.end; start++){
		result = ft_isdigit(start);
		expected = isdigit(start);
		if (expected > 0) expected = 1;
		if (result != expected){
			pass = false;
			break;
		}
	}
	if (detail) cprintf(TESTINTRSLT, LBLUE, DEFAULT, YELLOW, result, LBLUE, YELLOW, expected);
	if (pass)setgrade(PASS);
}
