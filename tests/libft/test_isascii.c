#include "tester.h"

typedef struct s_case{
	int start;
	int end;
	char *input;
} t_case;

t_case isascii_tests[] = {
	{-1, -1, "loop range int[-1 - -1]"},
	{0, 127, "loop range int[0 - 127]"},
	{128, 128, "loop range int[128 - 128]"}
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
	if (detail) cprintf(TESTINFO, LBLUE, DEFAULT, YELLOW, n + 1, LBLUE, RED, test.input);
	for(int start = test.start; start <= test.end; start++){
		result = ft_isascii(start);
		expected = isascii(start);
		if (expected > 0) expected = 1;
		if (result != expected){
			pass = false;
			break;
		}
	}
	if (detail) cprintf(TESTINTRSLT, LBLUE, DEFAULT, YELLOW, result, LBLUE, YELLOW, expected);
	if (pass) setgrade(PASS);
}
