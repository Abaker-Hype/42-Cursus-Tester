#include "tester.h"

typedef struct s_case{
	char *str;
	int expected;
} t_case;

t_case atoi_tests[] = {
	{"42", 42},
	{"-42", -42},
	{"+42", 42},
	{"0", 0},
	{"-0", 0},
	{"2147483647", 2147483647},
	{"-2147483648", -2147483648},
	{"+++++69", 0},
	{"-+-+-69", 0},
	{"+6-9", 6},
	{"-6+9", -6},
	{"00000177013", 177013},
	{"0a6", 0},
	{"     97 8\n5", 97},
	{"\e177013", 0},
	{"\t\n\r\v\f  177013abc", 177013}
};

int tests_atoi()
{
	return (arraysize(atoi_tests));
}

bool exists_atoi()
{
	return (ft_atoi != NULL);
}

void	test_atoi(int n)
{
	int result = ft_atoi(atoi_tests[n].str);
	if (result != atoi_tests[n].expected)return;
	setgrade(PASS);
}
