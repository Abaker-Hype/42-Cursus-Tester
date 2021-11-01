#include "tester.h"

typedef struct s_case{
	char *str1;
	char *str2;
	int str1len;
	int str2len;
	int len;
	bool segv;
} t_case;

t_case strncmp_tests[] = {
	{"test", "test", 4, 4, 4},
	{"test", "tests", 4, 5, 6},
	{"tests", "test", 5, 4, 6},
	{"test", "teSt", 4, 4, 4},
	{"test", "", 4, 0, 4},
	{"", "test", 0, 4, 4},
	{"test\0abc", "test\0zyx", 8, 8, 8},
	{"123456789", "123457689", 9, 9, 5},
	{"12345", "12389", 5, 5, 4},
	{"zyx", "abc", 3, 3, 0},
	{"", "abc", 0, 3, 0},
	{"abc", "", 3, 0, 0},
	{"test\200", "test\0", 5, 5, 6},
	{NULL, "abc", 0, 3, 3, true},
	{"abc", NULL, 3, 0, 3, true}	
};

int tests_strncmp()
{
	return (arraysize(strncmp_tests));
}

bool exists_strncmp()
{
	return (ft_strncmp != NULL);
}

void	test_strncmp(int n, bool detail)
{
	bool pass = true;
	t_case test = strncmp_tests[n];
	int result, expected = 0;
	if (test.segv) passsegv();
	if (detail) testinfo("vvi",n + 1, test.str1, test.str1len, test.str2, test.str2len, test.len); 
	result = ft_strncmp(test.str1, test.str2, test.len);
	if (!test.segv)expected = strncmp(test.str1, test.str2, test.len);
	if (result != expected) pass = false;
	if (detail) resultinfo("i", result, expected);
	if (pass) setgrade(PASS);
}
