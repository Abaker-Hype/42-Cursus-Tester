#include "tester.h"

typedef struct s_case{
	char *str;
	int len;
	bool dest;
	bool segv;
} t_case;

char src1[]="abcde0123456789";
char src2[]="abcde0123456789";
char *dest1 = src1 + 1;
char *dest2 = src2 + 1;

t_case memmove_tests[] = {
	{"zyxwv", 5, true, false},
	{"z\0y\0x\0w\0v\0",10,true, false},
	{NULL, 10, true, false},
	{NULL, 10, false, false},
	{NULL, 0 , false, false},
	{NULL, 5 , true, true},
	{"abc", 5, true, true},
	{NULL, 0, true, true}
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
	char *i1 = NULL, *i2 = NULL, *e1, *e2;
	void *result = NULL, *expected = NULL;
	t_case test = memmove_tests[n];
	if (test.segv){
		passsegv();
		if (test.str) {
			i2 = test.str;
			if (detail) testinfo("vsi", n + 1, i1, 15, i2, test.len);
		} else {
			i1 = src1;
			if (detail) testinfo("vvi", n + 1, i1, 15, i2, 15, test.len);
		}
	} else if (test.dest){
		i1 = dest1;
		e1 = dest2;
		if (test.str){
			i2 = test.str;
			e2 = test.str;
			if (detail) testinfo("ssi", n + 1, i1, test.str, 15, test.len);
		}else{
			i2 = src1;
			e2 = src2;
			if (detail) testinfo("*vi", n + 1, "void[*str+1]", i2, 15, test.len);
		}
	} else {
		i1 = src1;
		i2 = dest1;
		e1 = src2;
		e2 = dest2;
		if (detail) testinfo("v*i", n + 1, i1, 15, "void[*str+1]", test.len);
	}
	result = ft_memmove(i1, i2, test.len);
	if (!test.segv) expected = memmove(e1, e2, test.len);
	if ((test.segv && result != expected) || (!test.segv && memcmp(result, expected, 15) != 0))pass = false;
	if (detail) resultinfo("v", result, 15, expected, 15);
	if(pass)setgrade(PASS);
}
