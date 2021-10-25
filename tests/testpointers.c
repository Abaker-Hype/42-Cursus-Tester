#include "tester.h"

testfunc libft[] = {
	{&test_isalpha, &exists_isalpha, &tests_isalpha, "ft_isalpha", false},
	{&test_isdigit, &exists_isdigit, &tests_isdigit, "ft_isdigit", false},
	{&test_isalnum, &exists_isalnum, &tests_isalnum, "ft_isalnum", false},
	{&test_isascii, &exists_isascii, &tests_isascii, "ft_isascii", false},
	{&test_isprint, &exists_isprint, &tests_isprint, "ft_isprint", false},
	{&test_strchr, &exists_strchr, &tests_strchr, "ft_strchr", false},
	{&test_strrchr, &exists_strrchr, &tests_strrchr, "ft_strrchr", false},
	{&test_strncmp, &exists_strncmp, &tests_strncmp, "ft_strncmp", false},
	{&test_strlen, &exists_strlen, &tests_strlen, "ft_strlen", false},
	{&test_toupper, &exists_toupper, &tests_toupper, "ft_toupper", false},
	{&test_tolower, &exists_tolower, &tests_tolower, "ft_tolower", false},
	{&test_bzero, &exists_bzero, &tests_bzero, "ft_bzero", false},
	{&test_memset, &exists_memset, &tests_memset, "ft_memset", false}
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
