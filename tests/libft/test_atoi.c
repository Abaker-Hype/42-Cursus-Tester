#include "tester.h"

typedef struct s_case{
	char *str;
	char *input;
} t_case;

t_case atoi_tests[] = {
	{"42","str[42]"},
	{"-42","str[-42]"},
	{"+42","str[+42]"},
	{"0","str[0]"},
	{"-0","str[-0]"},
	{"2147483647","str[2147483647]"},
	{"-2147483648","str[-2147483648]"},
	{"+++++69","str[+++++69]"},
	{"-+-+-69","str[-+-+-69]"},
	{"+6-9","str[+6-9]"},
	{"-6+9","str[-6+9]"},
	{"00000177013","str[00000177013]"},
	{"7a6","str[7a6]"},
	{"     97 8\n5","str[     97 8\\n5]"},
	{"\e177013","str[\\e177013]"},
	{"\t\n\r\v\f  177013abc","str[\\t\\n\\r\\v\\f  177013abc]"}
};

int tests_atoi()
{
	return (arraysize(atoi_tests));
}

bool exists_atoi()
{
	return (ft_atoi != NULL);
}

void	test_atoi(int n, bool detail)
{
	bool pass = true;
	t_case test = atoi_tests[n];
	if (detail) cprintf(TESTINFO, LBLUE, DEFAULT, YELLOW, n + 1, LBLUE, RED, test.input);
	int result = ft_atoi(test.str);
	int	expected = atoi(test.str);
	if (result != expected)pass = false;
	if (detail) cprintf(TESTINTRSLT, LBLUE, DEFAULT, YELLOW, result, LBLUE, YELLOW, expected);
	if (pass)setgrade(PASS);
}
