#ifndef TEST_FUNCS_H
# define TEST_FUNCS_H

//LIBFT tests count
int     tests_bzero() __attribute__((weak));
int     tests_isalnum() __attribute__((weak));
int     tests_isalpha() __attribute__((weak));
int     tests_isascii() __attribute__((weak));
int     tests_isdigit() __attribute__((weak));
int     tests_isprint() __attribute__((weak));
int     tests_memchr() __attribute__((weak));
int     tests_memset() __attribute__((weak));
int     tests_strchr() __attribute__((weak));
int     tests_strlen() __attribute__((weak));
int     tests_strncmp() __attribute__((weak));
int     tests_strrchr() __attribute__((weak));
int     tests_tolower() __attribute__((weak));
int     tests_toupper() __attribute__((weak));
int     tests_memcmp() __attribute__((weak));
int     tests_memcpy() __attribute__((weak));
int     tests_memmove() __attribute__((weak));
int     tests_strlcpy() __attribute__((weak));
int     tests_strlcat() __attribute__((weak));
int     tests_strnstr() __attribute__((weak));
int     tests_atoi() __attribute__((weak));
int     tests_calloc() __attribute__((weak));
int     tests_strdup() __attribute__((weak));
//int     tests_() __attribute__((weak));

//LIBFT exists
bool    exists_bzero() __attribute__((weak));
bool    exists_isalnum() __attribute__((weak));
bool    exists_isalpha() __attribute__((weak));
bool    exists_isascii() __attribute__((weak));
bool    exists_isdigit() __attribute__((weak));
bool    exists_isprint() __attribute__((weak));
bool    exists_memchr() __attribute__((weak));
bool    exists_memset() __attribute__((weak));
bool    exists_strchr() __attribute__((weak));
bool    exists_strlen() __attribute__((weak));
bool    exists_strncmp() __attribute__((weak));
bool    exists_strrchr() __attribute__((weak));
bool    exists_tolower() __attribute__((weak));
bool    exists_toupper() __attribute__((weak));
bool    exists_memcmp() __attribute__((weak));
bool    exists_memcpy() __attribute__((weak));
bool    exists_memmove() __attribute__((weak));
bool    exists_strlcpy() __attribute__((weak));
bool    exists_strlcat() __attribute__((weak));
bool    exists_strnstr() __attribute__((weak));
bool    exists_atoi() __attribute__((weak));
bool    exists_calloc() __attribute__((weak));
bool    exists_strdup() __attribute__((weak));
//bool    exists_() __attribute__((weak));

//LIBFT test func
void    test_bzero(int n, bool detail) __attribute__((weak));
void    test_isalnum(int n, bool detail) __attribute__((weak));
void    test_isalpha(int n, bool detail) __attribute__((weak));
void    test_isascii(int n, bool detail) __attribute__((weak));
void    test_isdigit(int n, bool detail) __attribute__((weak));
void    test_isprint(int n, bool detail) __attribute__((weak));
void    test_memchr(int n, bool detail) __attribute__((weak));
void    test_memset(int n, bool detail) __attribute__((weak));
void    test_strchr(int n, bool detail) __attribute__((weak));
void    test_strlen(int n, bool detail) __attribute__((weak));
void    test_strncmp(int n, bool detail) __attribute__((weak));
void    test_strrchr(int n, bool detail) __attribute__((weak));
void    test_tolower(int n, bool detail) __attribute__((weak));
void    test_toupper(int n, bool detail) __attribute__((weak));
void    test_memcmp(int n, bool detail) __attribute__((weak));
void    test_memcpy(int n, bool detail) __attribute__((weak));
void    test_memmove(int n, bool detail) __attribute__((weak));
void    test_strlcpy(int n, bool detail) __attribute__((weak));
void    test_strlcat(int n, bool detail) __attribute__((weak));
void    test_strnstr(int n, bool detail) __attribute__((weak));
void    test_atoi(int n, bool detail) __attribute__((weak));
void    test_calloc(int n, bool detail) __attribute__((weak));
void    test_strdup(int n, bool detail) __attribute__((weak));
//void    test_(int n, bool detail) __attribute__((weak));
#endif
