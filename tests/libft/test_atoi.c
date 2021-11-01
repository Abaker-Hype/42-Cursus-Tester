#include "tester.h"

typedef struct s_case{
	char *str;
} t_case;

t_case atoi_tests[] = {
	{"42"},
	{"-42"},
	{"+42"},
	{"0"},
	{"-0"},
	{"2147483647"},
	{"-2147483648"},
	{"+++++69"},
	{"-+-+-69"},
	{"+6-9"},
	{"-6+9"},
	{"\n-216500"},
	{"-\n216500"},
	{"00000177013"},
	{"7a6"},
	{"     97 8\n5"},
	{"\e177013"},
	{"\t\n\r\v\f  177013abc"}
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
	if (detail)  testinfo("s", n + 1, test.str);
	int result = ft_atoi(test.str);
	int	expected = atoi(test.str);
	if (result != expected)pass = false;
	if (detail) resultinfo("i", result, expected);
	if (pass)setgrade(PASS);
}
