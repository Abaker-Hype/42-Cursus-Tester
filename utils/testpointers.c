#include "tester.h"

testfunc libft[] = {
	{&test_isalpha, &exists_isalpha, &tests_isalpha, "ft_isalpha", "Part-1", false},
	{&test_isdigit, &exists_isdigit, &tests_isdigit, "ft_isdigit", "Part-1", false},
	{&test_isalnum, &exists_isalnum, &tests_isalnum, "ft_isalnum", "Part-1", false},
	{&test_isascii, &exists_isascii, &tests_isascii, "ft_isascii", "Part-1", false},
	{&test_isprint, &exists_isprint, &tests_isprint, "ft_isprint", "Part-1", false},
	{&test_strchr, &exists_strchr, &tests_strchr, "ft_strchr", "Part-1", false},
	{&test_strrchr, &exists_strrchr, &tests_strrchr, "ft_strrchr", "Part-1", false},
	{&test_strncmp, &exists_strncmp, &tests_strncmp, "ft_strncmp", "Part-1", false},
	{&test_strlen, &exists_strlen, &tests_strlen, "ft_strlen", "Part-1", false},
	{&test_toupper, &exists_toupper, &tests_toupper, "ft_toupper", "Part-1", false},
	{&test_tolower, &exists_tolower, &tests_tolower, "ft_tolower", "Part-1", false},
	{&test_bzero, &exists_bzero, &tests_bzero, "ft_bzero", "Part-1", false},
	{&test_memset, &exists_memset, &tests_memset, "ft_memset", "Part-1", false},
	{&test_memchr, &exists_memchr, &tests_memchr, "ft_memchr", "Part-1", false},
	{&test_memcmp, &exists_memcmp, &tests_memcmp, "ft_memcmp", "Part-1", false},
	{&test_memcpy, &exists_memcpy, &tests_memcpy, "ft_memcpy", "Part-1", false},
	{&test_memmove, &exists_memmove, &tests_memmove, "ft_memmove", "Part-1", false},
	{&test_strlcpy, &exists_strlcpy, &tests_strlcpy, "ft_strlcpy", "Part-1", false},
	{&test_strlcat, &exists_strlcat, &tests_strlcat, "ft_strlcat", "Part-1", false},
	{&test_strnstr, &exists_strnstr, &tests_strnstr, "ft_strnstr", "Part-1", false},
	{&test_atoi, &exists_atoi, &tests_atoi, "ft_atoi", "Part-1", false},
	{&test_calloc, &exists_calloc, &tests_calloc, "ft_calloc", "Part-1", false},
	{&test_strdup, &exists_strdup, &tests_strdup, "ft_strdup", "Part-1", false},
	{&test_substr, &exists_substr, &tests_substr, "ft_substr", "Part-2", false},
	{&test_strjoin, &exists_strjoin, &tests_strjoin, "ft_strjoin", "Part-2", false},
	{&test_strtrim, &exists_strtrim, &tests_strtrim, "ft_strtrim", "Part-2", false},
	{&test_split, &exists_split, &tests_split, "ft_split", "Part-2", false},
	{&test_itoa, &exists_itoa, &tests_itoa, "ft_itoa", "Part-2", false},
	{&test_strmapi, &exists_strmapi, &tests_strmapi, "ft_strmapi", "Part-2", false},
	{&test_striteri, &exists_striteri, &tests_striteri, "ft_striteri", "Part-2", false},
	{&test_putchar_fd, &exists_putchar_fd, &tests_putchar_fd, "ft_putchar_fd", "Part-2", false},
	{&test_putstr_fd, &exists_putstr_fd, &tests_putstr_fd, "ft_putstr_fd", "Part-2", false},
	{&test_putendl_fd, &exists_putendl_fd, &tests_putendl_fd, "ft_putendl_fd", "Part-2", false},
	{&test_putnbr_fd, &exists_putnbr_fd, &tests_putnbr_fd, "ft_putnbr_fd", "Part-2", false},
	{&test_lstnew, &exists_lstnew, &tests_lstnew, "ft_lstnew", "Bonus", true},
	{&test_lstadd_front, &exists_lstadd_front, &tests_lstadd_front, "ft_lstadd_front", "Bonus", true},
	{&test_lstsize, &exists_lstsize, &tests_lstsize, "ft_lstsize", "Bonus", true},
	{&test_lstlast, &exists_lstlast, &tests_lstlast, "ft_lstlast", "Bonus", true}
};

testfunc ftprintf[] = {
	{&test_type_basic, &exists_printf, &tests_type_basic, "type_basic", "Manditory", false},
	{&test_type_percent, &exists_printf, &tests_type_percent, "type_%", "Manditory", false},
	{&test_type_c, &exists_printf, &tests_type_c, "type_c", "Manditory", false},
	{&test_type_s, &exists_printf, &tests_type_s, "type_s", "Manditory", false},
	{&test_type_i, &exists_printf, &tests_type_i, "type_i", "Manditory", false},
	{&test_type_d, &exists_printf, &tests_type_d, "type_d", "Manditory", false},
	{&test_type_u, &exists_printf, &tests_type_u, "type_u", "Manditory", false},
	{&test_type_x, &exists_printf, &tests_type_x, "type_x", "Manditory", false},
	{&test_type_X, &exists_printf, &tests_type_X, "type_X", "Manditory", false},
	{&test_type_p, &exists_printf, &tests_type_p, "type_p", "Manditory", false},
	{&test_type_mix, &exists_printf, &tests_type_mix, "type_mix", "Manditory", false},
	{&test_flag_hash_no_effect, &exists_printf, &tests_flag_hash_no_effect, "no_effect_#", "Flag-#", true},
	{&test_flag_hash_type_x, &exists_printf, &tests_flag_hash_type_x, "type_x_#", "Flag-#", true},
	{&test_flag_hash_type_X, &exists_printf, &tests_flag_hash_type_X, "type_X_#", "Flag-#", true},
	{&test_flag_width_type_percent, &exists_printf, &tests_flag_width_type_percent, "type_%_width", "Flag-Width", true},
	{&test_flag_width_type_c, &exists_printf, &tests_flag_width_type_c, "type_c_width", "Flag-Width", true},
	{&test_flag_width_type_s, &exists_printf, &tests_flag_width_type_s, "type_s_width", "Flag-Width", true},
	{&test_flag_width_type_i, &exists_printf, &tests_flag_width_type_i, "type_i_width", "Flag-Width", true},
	{&test_flag_width_type_d, &exists_printf, &tests_flag_width_type_d, "type_d_width", "Flag-Width", true},
	{&test_flag_width_type_u, &exists_printf, &tests_flag_width_type_u, "type_u_width", "Flag-Width", true},
	{&test_flag_width_type_x, &exists_printf, &tests_flag_width_type_x, "type_x_width", "Flag-Width", true},
	{&test_flag_width_type_X, &exists_printf, &tests_flag_width_type_X, "type_X_width", "Flag-Width", true},
	{&test_flag_width_type_p, &exists_printf, &tests_flag_width_type_p, "type_p_width", "Flag-Width", true},
	{&test_flag_0_type_percent, &exists_printf, &tests_flag_0_type_percent, "type_%_0", "Flag-0", true},
	{&test_flag_0_type_c, &exists_printf, &tests_flag_0_type_c, "type_c_0", "Flag-0", true},
	{&test_flag_0_type_s, &exists_printf, &tests_flag_0_type_s, "type_s_0", "Flag-0", true},
	{&test_flag_0_type_i, &exists_printf, &tests_flag_0_type_i, "type_i_0", "Flag-0", true},
	{&test_flag_0_type_d, &exists_printf, &tests_flag_0_type_d, "type_d_0", "Flag-0", true},
	{&test_flag_0_type_u, &exists_printf, &tests_flag_0_type_u, "type_u_0", "Flag-0", true},
	{&test_flag_0_type_x, &exists_printf, &tests_flag_0_type_x, "type_x_0", "Flag-0", true},
	{&test_flag_0_type_X, &exists_printf, &tests_flag_0_type_X, "type_X_0", "Flag-0", true},
	{&test_flag_0_type_p, &exists_printf, &tests_flag_0_type_p, "type_p_0", "Flag-0", true},
	{&test_flag_minus_type_percent, &exists_printf, &tests_flag_minus_type_percent, "type_%_minus", "Flag-Minus", true},
	{&test_flag_minus_type_c, &exists_printf, &tests_flag_minus_type_c, "type_c_minus", "Flag-Minus", true},
	{&test_flag_minus_type_s, &exists_printf, &tests_flag_minus_type_s, "type_s_minus", "Flag-Minus", true},
	{&test_flag_minus_type_i, &exists_printf, &tests_flag_minus_type_i, "type_i_minus", "Flag-Minus", true},
	{&test_flag_minus_type_d, &exists_printf, &tests_flag_minus_type_d, "type_d_minus", "Flag-Minus", true},
	{&test_flag_minus_type_u, &exists_printf, &tests_flag_minus_type_u, "type_u_minus", "Flag-Minus", true},
	{&test_flag_minus_type_x, &exists_printf, &tests_flag_minus_type_x, "type_x_minus", "Flag-Minus", true},
	{&test_flag_minus_type_X, &exists_printf, &tests_flag_minus_type_X, "type_X_minus", "Flag-Minus", true},
	{&test_flag_minus_type_p, &exists_printf, &tests_flag_minus_type_p, "type_p_minus", "Flag-Minus", true},
	{&test_flag_space_no_effect, &exists_printf, &tests_flag_space_no_effect, "no_effect_space", "Flag-Space", true},
	{&test_flag_space_type_i, &exists_printf, &tests_flag_space_type_i, "type_i_space", "Flag-Space", true},
	{&test_flag_space_type_d, &exists_printf, &tests_flag_space_type_d, "type_d_space", "Flag-Space", true},
	{&test_flag_plus_no_effect, &exists_printf, &tests_flag_plus_no_effect, "no_effect_+", "Flag-Plus", true},
	{&test_flag_plus_type_i, &exists_printf, &tests_flag_plus_type_i, "type_i_+", "Flag-Plus", true},
	{&test_flag_plus_type_d, &exists_printf, &tests_flag_plus_type_d, "type_d_+", "Flag-Plus", true},
	{&test_flag_dot_no_effect, &exists_printf, &tests_flag_dot_no_effect, "no_effect_dot", "Flag-Dot", true},
	{&test_flag_dot_type_s, &exists_printf, &tests_flag_dot_type_s, "type_s_dot", "Flag-Dot", true},
	{&test_flag_dot_type_i, &exists_printf, &tests_flag_dot_type_i, "type_i_dot", "Flag-Dot", true},
	{&test_flag_dot_type_d, &exists_printf, &tests_flag_dot_type_d, "type_d_dot", "Flag-Dot", true},
	{&test_flag_dot_type_u, &exists_printf, &tests_flag_dot_type_u, "type_u_dot", "Flag-dot", true},
	{&test_flag_dot_type_x, &exists_printf, &tests_flag_dot_type_x, "type_x_dot", "Flag-dot", true},
	{&test_flag_dot_type_X, &exists_printf, &tests_flag_dot_type_X, "type_X_dot", "Flag-dot", true},
	{&test_flag_dot_type_p, &exists_printf, &tests_flag_dot_type_p, "type_p_dot", "Flag-dot", true},
	{&test_flag_mix_type_percent, &exists_printf, &tests_flag_mix_type_percent, "type_%_mix", "Flag-Mix", true},
	{&test_flag_mix_type_c, &exists_printf, &tests_flag_mix_type_c, "type_c_mix", "Flag-Mix", true},
	{&test_flag_mix_type_s, &exists_printf, &tests_flag_mix_type_s, "type_s_mix", "Flag-Mix", true},
	{&test_flag_mix_type_i, &exists_printf, &tests_flag_mix_type_i, "type_i_mix", "Flag-Mix", true},
	{&test_flag_mix_type_d, &exists_printf, &tests_flag_mix_type_d, "type_d_mix", "Flag-Mix", true},
	{&test_flag_mix_type_u, &exists_printf, &tests_flag_mix_type_u, "type_u_mix", "Flag-Mix", true},
	{&test_flag_mix_type_x, &exists_printf, &tests_flag_mix_type_x, "type_x_mix", "Flag-Mix", true},
	{&test_flag_mix_type_X, &exists_printf, &tests_flag_mix_type_X, "type_X_mix", "Flag-Mix", true}
};

testfunc gnl[] = {
	{&test_bad_inputs, &exists_gnl, &tests_bad_inputs, "bad_inputs", "Manditory", false},
	{&test_buffer_1, &exists_gnl, &tests_buffer_1, "buffer_1", "Manditory", false},
	{&test_buffer_42, &exists_gnl, &tests_buffer_42, "buffer_42", "Manditory", false},
	{&test_buffer_215600, &exists_gnl, &tests_buffer_215600, "buffer_215600", "Manditory", false}
};


testfunc *gettestarry(tester t)
{
	switch (t){
		case LIBFT: return (libft);
		case PRINTF: return (ftprintf); 
		case GNL: return (gnl);
		default: return NULL;
	}
}

int gettestsize(tester t)
{
	switch (t){
		case LIBFT: return (arraysize(libft));
		case PRINTF: return (arraysize(ftprintf));
		case GNL: return (arraysize(gnl));
		default: return (0);
	}
}

testfunc *gettest(tester t, int n)
{
	return (&gettestarry(t)[n]);
}

testfunc *gettestbyname(tester t, char *str)
{
	testfunc *arry = gettestarry(t);
	if (!arry) return (NULL);
	int max = gettestsize(t);
	for (int i = 0; i < max; i++)
		if (strcmp(str, arry[i].name) == 0) return (&arry[i]);
	return (NULL);
}

bool chkgroup(tester t, char *g)
{
	testfunc *arry = gettestarry(t);
	if (!arry) return (false);
	int size = gettestsize(t);
	for (int i = 0; i < size; i++)
		if (strcmp(arry[i].group, g) == 0) return (true);
	return (false);
}
