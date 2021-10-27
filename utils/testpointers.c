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
	{&test_memset, &exists_memset, &tests_memset, "ft_memset", false},
	{&test_memchr, &exists_memchr, &tests_memchr, "ft_memchr", false},
	{&test_memcmp, &exists_memcmp, &tests_memcmp, "ft_memcmp", false},
	{&test_memcpy, &exists_memcpy, &tests_memcpy, "ft_memcpy", false},
	{&test_memmove, &exists_memmove, &tests_memmove, "ft_memmove", false},
	{&test_strlcpy, &exists_strlcpy, &tests_strlcpy, "ft_strlcpy", false},
	{&test_strlcat, &exists_strlcat, &tests_strlcat, "ft_strlcat", false},
	{&test_strnstr, &exists_strnstr, &tests_strnstr, "ft_strnstr", false},
	{&test_atoi, &exists_atoi, &tests_atoi, "ft_atoi", false}
};

int testcount(tester t)
{
	switch (t){
		case LIBFT: return arraysize(libft);
		default: return 0;
	}
}

static int gettestnum(testfunc lib[], int tests)
{
	int max = 0;
	for (int i = 0; i < tests; i++)
		if ((*lib[i].tests)() > max) max = (*lib[i].tests)();
	return max;
}

int getmaxtests(tester t)
{
	switch (t){
		case LIBFT: return gettestnum(libft, testcount(t));
		default: return 0;
	}
}

testfunc *gettest(tester t, int n)
{
	switch (t){
		case LIBFT: return &libft[n];
		default: return NULL;
	}
}

testfunc *gettestbyname(tester t, char *str)
{
	testfunc *arry;
	switch (t){
        case LIBFT: arry = libft;
			break;
        default: return NULL;
    }
	int max = testcount(t);
	for (int i = 0; i < max; i++)
		if (strcmp(str, arry[i].name) == 0) return &arry[i];
	return NULL;
}
