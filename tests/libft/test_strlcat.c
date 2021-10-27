#include "tester.h"

typedef struct s_case{
	char *str;
	int len;
	int fill;
} t_case;

t_case strlcat_tests[] = {
	{"test", 20, 5},
	{"", 20, 5},
	{"test12345", 20, 15},
	{"test12345", 0, 15},
	{"test12345", 1, 15},
	{"test12345", 5, 15},
	{"test12345", 6, 15},
	{"test12345", 20, 19}
};

int tests_strlcat()
{
	return (arraysize(strlcat_tests));
}

bool exists_strlcat()
{
	return (ft_strlcat != NULL);
}

void	test_strlcat(int n, bool detail)
{
	bool pass = true;
	t_case test = strlcat_tests[n];
	char *dst1 = malloc(sizeof(char) * 20);
	char *dst2 = malloc(sizeof(char) * 20);
	memset(dst1, '\0', 20);
	memset(dst2, '\0', 20);
	memset(dst1, 'a', test.fill);
	memset(dst2, 'a', test.fill);
	int result = ft_strlcat(dst1, test.str, test.len);
	int expected = strlcat(dst2, test.str, test.len);
	if (result != expected || memcmp(dst1, dst2, 20) != 0)pass = false;
	free(dst1);
	free(dst2);
	if (pass)setgrade(PASS);
}
