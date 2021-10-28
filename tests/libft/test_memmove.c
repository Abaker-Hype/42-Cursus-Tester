#include "tester.h"

typedef struct s_case{
	char *str;
	int len;
	bool dest;
	bool segv;
	char *input;
} t_case;

char src1[]="abcde0123456789";
char src2[]="abcde0123456789";
char *dest1 = src1 + 1;
char *dest2 = src2 + 1;

t_case memmove_tests[] = {
	{"zyxwv", 5, true, false, "void[bcde0123456789] void[zyxwv] int[5]"},
	{"z\0y\0x\0w\0v\0",10,true, false, "void[bcde0123456789] void[z\0y\0x\0w\0v\0] int[10]"},
	{NULL, 10, true, false, "void[bcde0123456789] void[*str-1] int[10]"},
	{NULL, 10, false, false, "void[abcde0123456789] void[*str+1] int[10]"},
	{NULL, 0 , false, false, "void[abcde0123456789] void[*str+1] int[0]"},
	{NULL, 5 , true, true, "void[bcde0123456789] void[(NULL)] int[5]"},
	{"abc", 5, true, true, "void[(NULL)] void[abc] int[5]"},
	{NULL, 0, true, true, "void[(NULL)] void[(NULL)] int[0]"}
};

int tests_memmove()
{
	return (arraysize(memmove_tests));
}

bool exists_memmove()
{
	return (ft_memmove != NULL);
}

void	test_memmove(int n, bool detail)
{
	bool pass = true;
	char *result, *expected;
	t_case test = memmove_tests[n];
	if (detail) cprintf(TESTINFO, LBLUE, DEFAULT, YELLOW, n + 1, LBLUE, RED, test.input);
	if (test.segv){
		passsegv();
		if (test.str) result = ft_memmove(NULL, test.str, test.len);
		else result = ft_memmove(src1, NULL, test.len);
		expected = NULL;
	} else if (test.dest){
		if (test.str){
			result = ft_memmove(dest1, test.str, test.len);
			expected = memmove(dest2, test.str, test.len);
		}else{
				result = ft_memmove(dest1, src1, test.len);
				expected = memmove(dest2, src2, test.len);
		}
	} else {
		result = ft_memmove(src1, dest1, test.len);
		expected = memmove(src2, dest2, test.len);
	}
	if ((test.segv && result != expected) || (!test.segv && memcmp(result, expected, 15) != 0))pass = false;
	if (detail) cprintf(TESTSTRRSLT, LBLUE, DEFAULT, YELLOW, result, LBLUE, YELLOW, expected);
	if(pass)setgrade(PASS);
}
