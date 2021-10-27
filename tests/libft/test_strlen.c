#include "tester.h"

typedef struct s_case{
	char *str;
	char *input;
} t_case;

t_case strlen_tests[] = {
	{"", ""},
	{"        ","         "},
	{"abc def ghi","abc def ghi"},
	{"177013", "177013"},
	{"\n\f\r\\\t","\\n\\f\\r\\\\\\t"},
	{"test\0test","test\\0test"}
};

int tests_strlen()
{
	return (arraysize(strlen_tests));
}

bool exists_strlen()
{
	return (ft_strlen != NULL);
}

void	test_strlen(int n, bool detail)
{
	bool pass = true;
	t_case test = strlen_tests[n];
	if (detail)
		printf("Test No. = %i\nInput Args = str[\"%s\"]\n",n + 1, test.input);
	int result = ft_strlen(test.str);
	int expected = strlen(test.str);
	if (result != expected)
		pass = false;
	if (detail)
		printf("Your result: %i\nExpected: %i\n",result, expected);
	if (pass)
		setgrade(PASS);
}
