#ifndef TEST_FUNCS_H
# define TEST_FUNCS_H

//LIBFT compare funcs
char *substr(char *str, int start, int len) __attribute__((weak));
char *strjoin(char *s1, char *s2) __attribute__((weak));
char *strtrim(char *str, char *set) __attribute__((weak));
char **split(char *str, char c) __attribute__((weak));
char *itoa(int n) __attribute__((weak));
char *strmapi(char const *s, char (*f)(unsigned int, char)) __attribute__((weak));
void striteri(char *s, void (*f)(unsigned int, char *)) __attribute__((weak));
void freelst(t_list *start) __attribute__((weak));
t_list *genlist(int n) __attribute__((weak));
t_list *lstnew(void *data) __attribute__((weak));
void lstadd_front(t_list **list, t_list *new) __attribute__((weak));
void lstadd_back(t_list **list, t_list *new) __attribute__((weak));
t_list *lstlast(t_list *start) __attribute__((weak));


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
int     tests_substr() __attribute__((weak));
int     tests_strjoin() __attribute__((weak));
int     tests_strtrim() __attribute__((weak));
int     tests_split() __attribute__((weak));
int     tests_itoa() __attribute__((weak));
int     tests_strmapi() __attribute__((weak));
int     tests_striteri() __attribute__((weak));
int     tests_putchar_fd() __attribute__((weak));
int     tests_putstr_fd() __attribute__((weak));
int     tests_putendl_fd() __attribute__((weak));
int     tests_putnbr_fd() __attribute__((weak));
int     tests_lstnew() __attribute__((weak));
int     tests_lstadd_front() __attribute__((weak));
int     tests_lstsize() __attribute__((weak));
int     tests_lstlast() __attribute__((weak));
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
bool    exists_substr() __attribute__((weak));
bool    exists_strjoin() __attribute__((weak));
bool    exists_strtrim() __attribute__((weak));
bool    exists_split() __attribute__((weak));
bool    exists_itoa() __attribute__((weak));
bool    exists_strmapi() __attribute__((weak));
bool    exists_striteri() __attribute__((weak));
bool    exists_putchar_fd() __attribute__((weak));
bool    exists_putstr_fd() __attribute__((weak));
bool    exists_putendl_fd() __attribute__((weak));
bool    exists_putnbr_fd() __attribute__((weak));
bool    exists_lstnew() __attribute__((weak));
bool    exists_lstadd_front() __attribute__((weak));
bool    exists_lstsize() __attribute__((weak));
bool    exists_lstlast() __attribute__((weak));
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
void    test_substr(int n, bool detail) __attribute__((weak));
void    test_strjoin(int n, bool detail) __attribute__((weak));
void    test_strtrim(int n, bool detail) __attribute__((weak));
void    test_split(int n, bool detail) __attribute__((weak));
void    test_itoa(int n, bool detail) __attribute__((weak));
void    test_strmapi(int n, bool detail) __attribute__((weak));
void    test_striteri(int n, bool detail) __attribute__((weak));
void    test_putchar_fd(int n, bool detail) __attribute__((weak));
void    test_putstr_fd(int n, bool detail) __attribute__((weak));
void    test_putendl_fd(int n, bool detail) __attribute__((weak));
void    test_putnbr_fd(int n, bool detail) __attribute__((weak));
void    test_lstnew(int n, bool detail) __attribute__((weak));
void    test_lstadd_front(int n, bool detail) __attribute__((weak));
void    test_lstsize(int n, bool detail) __attribute__((weak));
void    test_lstlast(int n, bool detail) __attribute__((weak));
//void    test_(int n, bool detail) __attribute__((weak));

//PRINTF
typedef struct {
	char *format;
	int datasize;
	char *info;
    union {
		char c;
		char *s;
		int i;
		unsigned int u;
		void *p;
	} data[7];
} printftest;

//PRINTF Core Funcs
void	printftestcore(printftest test, int testnum, bool detail) __attribute__((weak));

//PRINTF exists
bool    exists_printf() __attribute__((weak));

//PRINTF tests
int     tests_type_basic() __attribute__((weak));
int     tests_type_percent() __attribute__((weak));
int     tests_type_c() __attribute__((weak));
int     tests_type_s() __attribute__((weak));
int     tests_type_i() __attribute__((weak));
int     tests_type_d() __attribute__((weak));
int     tests_type_u() __attribute__((weak));
int     tests_type_x() __attribute__((weak));
int     tests_type_X() __attribute__((weak));
int 	tests_type_p() __attribute__((weak));
int		tests_type_mix() __attribute__((weak));
int		tests_flag_hash_no_effect() __attribute__((weak));
int     tests_flag_hash_type_x() __attribute__((weak));
int     tests_flag_hash_type_X() __attribute__((weak));
int     tests_flag_width_type_percent() __attribute__((weak));
int     tests_flag_width_type_c() __attribute__((weak));
int     tests_flag_width_type_s() __attribute__((weak));
int     tests_flag_width_type_i() __attribute__((weak));
int     tests_flag_width_type_d() __attribute__((weak));
int     tests_flag_width_type_u() __attribute__((weak));
int     tests_flag_width_type_x() __attribute__((weak));
int     tests_flag_width_type_X() __attribute__((weak));
int     tests_flag_width_type_p() __attribute__((weak));
int     tests_flag_0_type_percent() __attribute__((weak));
int     tests_flag_0_type_c() __attribute__((weak));
int     tests_flag_0_type_s() __attribute__((weak));
int     tests_flag_0_type_i() __attribute__((weak));
int     tests_flag_0_type_d() __attribute__((weak));
int     tests_flag_0_type_u() __attribute__((weak));
int     tests_flag_0_type_x() __attribute__((weak));
int     tests_flag_0_type_X() __attribute__((weak));
int     tests_flag_0_type_p() __attribute__((weak));
int     tests_flag_minus_type_percent() __attribute__((weak));
int     tests_flag_minus_type_c() __attribute__((weak));
int     tests_flag_minus_type_s() __attribute__((weak));
int     tests_flag_minus_type_i() __attribute__((weak));
int     tests_flag_minus_type_d() __attribute__((weak));
int     tests_flag_minus_type_u() __attribute__((weak));
int     tests_flag_minus_type_x() __attribute__((weak));
int     tests_flag_minus_type_X() __attribute__((weak));
int     tests_flag_minus_type_p() __attribute__((weak));
int     tests_flag_space_no_effect() __attribute__((weak));
int     tests_flag_space_type_i() __attribute__((weak));
int     tests_flag_space_type_d() __attribute__((weak));
int     tests_flag_plus_no_effect() __attribute__((weak));
int     tests_flag_plus_type_i() __attribute__((weak));
int     tests_flag_plus_type_d() __attribute__((weak));
int     tests_flag_dot_no_effect() __attribute__((weak));
int     tests_flag_dot_type_s() __attribute__((weak));
int     tests_flag_dot_type_i() __attribute__((weak));
int     tests_flag_dot_type_d() __attribute__((weak));
int     tests_flag_dot_type_u() __attribute__((weak));
int     tests_flag_dot_type_x() __attribute__((weak));
int     tests_flag_dot_type_X() __attribute__((weak));
int     tests_flag_dot_type_p() __attribute__((weak));
int     tests_flag_mix_type_percent() __attribute__((weak));
int     tests_flag_mix_type_c() __attribute__((weak));
int     tests_flag_mix_type_s() __attribute__((weak));
int     tests_flag_mix_type_i() __attribute__((weak));
int     tests_flag_mix_type_d() __attribute__((weak));
int     tests_flag_mix_type_u() __attribute__((weak));
int     tests_flag_mix_type_x() __attribute__((weak));
int     tests_flag_mix_type_X() __attribute__((weak));
//int     tests_type_() __attribute__((weak));

//PRINTF test func
void    test_type_basic(int n, bool detail) __attribute__((weak));
void    test_type_percent(int n, bool detail) __attribute__((weak));
void    test_type_c(int n, bool detail) __attribute__((weak));
void    test_type_s(int n, bool detail) __attribute__((weak));
void    test_type_i(int n, bool detail) __attribute__((weak));
void    test_type_d(int n, bool detail) __attribute__((weak));
void    test_type_u(int n, bool detail) __attribute__((weak));
void    test_type_x(int n, bool detail) __attribute__((weak));
void    test_type_X(int n, bool detail) __attribute__((weak));
void    test_type_p(int n, bool detail) __attribute__((weak));
void    test_type_mix(int n, bool detail) __attribute__((weak));
void    test_flag_hash_no_effect(int n, bool detail) __attribute__((weak));
void    test_flag_hash_type_x(int n, bool detail) __attribute__((weak));
void    test_flag_hash_type_X(int n, bool detail) __attribute__((weak));
void    test_flag_width_type_percent(int n, bool detail) __attribute__((weak));
void    test_flag_width_type_c(int n, bool detail) __attribute__((weak));
void    test_flag_width_type_s(int n, bool detail) __attribute__((weak));
void    test_flag_width_type_i(int n, bool detail) __attribute__((weak));
void    test_flag_width_type_d(int n, bool detail) __attribute__((weak));
void    test_flag_width_type_u(int n, bool detail) __attribute__((weak));
void    test_flag_width_type_x(int n, bool detail) __attribute__((weak));
void    test_flag_width_type_X(int n, bool detail) __attribute__((weak));
void    test_flag_width_type_p(int n, bool detail) __attribute__((weak));
void    test_flag_0_type_percent(int n, bool detail) __attribute__((weak));
void    test_flag_0_type_c(int n, bool detail) __attribute__((weak));
void    test_flag_0_type_s(int n, bool detail) __attribute__((weak));
void    test_flag_0_type_i(int n, bool detail) __attribute__((weak));
void    test_flag_0_type_d(int n, bool detail) __attribute__((weak));
void    test_flag_0_type_u(int n, bool detail) __attribute__((weak));
void    test_flag_0_type_x(int n, bool detail) __attribute__((weak));
void    test_flag_0_type_X(int n, bool detail) __attribute__((weak));
void    test_flag_0_type_p(int n, bool detail) __attribute__((weak));
void    test_flag_minus_type_percent(int n, bool detail) __attribute__((weak));
void    test_flag_minus_type_c(int n, bool detail) __attribute__((weak));
void    test_flag_minus_type_s(int n, bool detail) __attribute__((weak));
void    test_flag_minus_type_i(int n, bool detail) __attribute__((weak));
void    test_flag_minus_type_d(int n, bool detail) __attribute__((weak));
void    test_flag_minus_type_u(int n, bool detail) __attribute__((weak));
void    test_flag_minus_type_x(int n, bool detail) __attribute__((weak));
void    test_flag_minus_type_X(int n, bool detail) __attribute__((weak));
void    test_flag_minus_type_p(int n, bool detail) __attribute__((weak));
void    test_flag_space_no_effect(int n, bool detail) __attribute__((weak));
void    test_flag_space_type_i(int n, bool detail) __attribute__((weak));
void    test_flag_space_type_d(int n, bool detail) __attribute__((weak));
void    test_flag_plus_no_effect(int n, bool detail) __attribute__((weak));
void    test_flag_plus_type_i(int n, bool detail) __attribute__((weak));
void    test_flag_plus_type_d(int n, bool detail) __attribute__((weak));
void    test_flag_dot_no_effect(int n, bool detail) __attribute__((weak));
void    test_flag_dot_type_s(int n, bool detail) __attribute__((weak));
void    test_flag_dot_type_i(int n, bool detail) __attribute__((weak));
void    test_flag_dot_type_d(int n, bool detail) __attribute__((weak));
void    test_flag_dot_type_u(int n, bool detail) __attribute__((weak));
void    test_flag_dot_type_x(int n, bool detail) __attribute__((weak));
void    test_flag_dot_type_X(int n, bool detail) __attribute__((weak));
void    test_flag_dot_type_p(int n, bool detail) __attribute__((weak));
void    test_flag_mix_type_percent(int n, bool detail) __attribute__((weak));
void    test_flag_mix_type_c(int n, bool detail) __attribute__((weak));
void    test_flag_mix_type_s(int n, bool detail) __attribute__((weak));
void    test_flag_mix_type_i(int n, bool detail) __attribute__((weak));
void    test_flag_mix_type_d(int n, bool detail) __attribute__((weak));
void    test_flag_mix_type_u(int n, bool detail) __attribute__((weak));
void    test_flag_mix_type_x(int n, bool detail) __attribute__((weak));
void    test_flag_mix_type_X(int n, bool detail) __attribute__((weak));
//void    test_type_(int n, bool detail) __attribute__((weak));

//GNL
typedef struct {
	char *file;
	int buffer;
} gnltest;

//GNL Core
void	gnlcore(gnltest test, int n, bool detail) __attribute__((weak));

//GNL Exists
bool	exists_gnl() __attribute__((weak));

//GNL Tests
int     tests_bad_inputs() __attribute__((weak)); 
int     tests_buffer_1() __attribute__((weak));
int     tests_buffer_42() __attribute__((weak));
int     tests_buffer_215600() __attribute__((weak));

//GNL Test Func
void    test_bad_inputs(int n, bool detail) __attribute__((weak));
void    test_buffer_1(int n, bool detail) __attribute__((weak));
void    test_buffer_42(int n, bool detail) __attribute__((weak));
void    test_buffer_215600(int n, bool detail) __attribute__((weak));
#endif
