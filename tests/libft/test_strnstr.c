#include "tester.h"

typedef struct s_case{
	char *find;
	int len;
	bool segv;
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
	{"Give", 0},
	{"", 0},
	{NULL, 0, true},
	{"", 5, true}
};

int tests_strnstr()
{
	return (arraysize(strnstr_tests));
}

bool exists_strnstr()
{
	return (ft_strnstr != NULL);
}

void	test_strnstr(int n, bool detail)
{
	bool pass = true;
	t_case test = strnstr_tests[n];
	char *search = "Never Gonna Give You Up! Never Gonna Let You Down! ";
	char *result = NULL, *expected = NULL;
	if (test.segv) {
		passsegv();
		if (test.len > 0) search = NULL;
		else expected = search;
	}
	if (detail) testinfo("ssi", n + 1, search, test.find, test.len);
	result = ft_strnstr(search, test.find, test.len);
	if (!test.segv) expected = strnstr(search, test.find, test.len);
	if (result != expected) pass = false;
	if (detail) resultinfo("s", result, expected);
	if (pass)setgrade(PASS);
}
