#include "tester.h"

testfunc libft[] = {
	{&test_isalpha, &exists_isalpha, &tests_isalpha, "ft_isalpha", false},
	{&test_isdigit, &exists_isdigit, &tests_isdigit, "ft_isdigit", false}
};

int testcount(tester t)
{
	switch (t){
		case LIBFT: return arraysize(libft);
		default: return -1;
	}
}

testfunc *gettest(tester t, int n)
{
	switch (t){
		case LIBFT: return &libft[n];
		default: return NULL;
	}
}
