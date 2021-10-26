#include "tester.h"

typedef struct s_case{
	char *find;
	int len;
} t_case;

t_case strnstr_tests[] = {
	{"Gonna", 15},
	{"To", 15},
	{"Never", 40},
	{"", 20},
	{"give", 30},
	{"Givee", 30},
	{"tacos", 50},
	{"Down", 20},
	{"Give", 17},
	{"Give", 0}
};

int tests_strnstr()
{
	return (arraysize(strnstr_tests));
}

bool exists_strnstr()
{
	return (ft_strnstr != NULL);
}

void	test_strnstr(int n)
{
	t_case test = strnstr_tests[n];
	char *search = "Never Gonna To Give You Up! Never Gonna Let You Down! ";
	char *result = ft_strnstr(search, test.find, test.len);
	char *expected = strnstr(search, test.find, test.len);
	if (result != expected) return;
	setgrade(PASS);
}
