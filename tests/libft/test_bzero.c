#include "libft.h"
#include "tester.h"

typedef struct s_case{
	int len;
} t_case;

t_case bzero_tests[] = {
	{10},
	{5},
	{0}
};

int tests_bzero()
{
	return (arraysize(bzero_tests));
}

bool exists_bzero()
{
	return (ft_bzero != NULL);
}

void	test_bzero(int n)
{
	bool pass = true;
	char *mem = malloc(sizeof(char) * 10);
	memset(mem, 'a', 10);
	ft_bzero(mem, bzero_tests[n].len);
	for (int i = 0; i < bzero_tests[n].len; i++){
		if (mem[i] != '\0'){
			pass = false;
			break;
		}
	}
	if (bzero_tests[n].len < 10)
		if (mem[bzero_tests[n].len + 1] != 'a') pass = false;
	free(mem);
	if (pass) setgrade(PASS);
}
