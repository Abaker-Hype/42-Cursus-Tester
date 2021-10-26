#include "tester.h"

typedef struct s_case{
	char *str;
	int len;
	bool dest;
} t_case;

char src1[]="abcde0123456789";
char src2[]="abcde0123456789";
char *dest1 = src1 + 1;
char *dest2 = src2 + 1;

t_case memmove_tests[] = {
	{"zyxwv", 5, true},
	{"z\0y\0x\0w\0v\0",10,true},
	{NULL, 10, true},
	{NULL, 10, false},
	{NULL, 0 , false}
};

int tests_memmove()
{
	return (arraysize(memmove_tests));
}

bool exists_memmove()
{
	return (ft_memmove != NULL);
}

void	test_memmove(int n)
{
	char *result, *expected;
	t_case test = memmove_tests[n];
	if (test.dest){
		if (test.str){
			result = ft_memmove(dest1, test.str, test.len);
			expected = memmove(dest2, test.str, test.len);
		}else{
			result = ft_memmove(dest1, src1, test.len);
			expected = memmove(dest2, src2, test.len);
		}
		if (memcmp(result, expected, 15) != 0)return;
	}else{
		result = ft_memmove(src1, dest1, test.len);
		expected = memmove(src2, dest2, test.len);
		if (memcmp(result, expected, 15) != 0)return;
	}
	setgrade(PASS);
}
