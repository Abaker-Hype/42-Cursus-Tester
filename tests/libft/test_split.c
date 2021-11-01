#include "tester.h"

typedef struct s_case{
	char *str;
	char c;
} t_case;

t_case split_tests[] = {
	{"test split", ' '},
	{"test split", 'a'},
	{"         ", ' '},
	{NULL, '\0'}
};

int tests_split()
{
	return (arraysize(split_tests));
}

bool exists_split()
{
	return (ft_split != NULL);
}

static void freearry(char **arry, bool track)
{
	int i = 0;
	while (arry[i]){
		if (track) free_track(arry[i]);
		else free(arry[i]);
		i++;
	}
	if (arry){
		if (track) free_track(arry);
		else free(arry);
	}	
}

static bool chksplits(char **result, char **expected)
{
	int i = 0;
	if (!expected) return (result == expected);
	while (expected[i]){
		if (strcmp(result[i], expected[i]) != 0) return (false);
		i++;
	}
	if (result[i]) return (false);
	return (true);
}

void	test_split(int n, bool detail)
{
	bool pass = true;
	t_case test = split_tests[n];
	char **result, **expected;
	if (detail) testinfo("sc", n + 1, test.str, test.c);
	result = ft_split(test.str, test.c);
	expected = split(test.str, test.c);
	if (!chksplits(result, expected)) pass = false;
	if (detail) resultinfo("a", result, expected);
	if (result) freearry(result, true);
	if (expected) freearry(expected, false);
	if (pass) setgrade(PASS);
}
