#include "tester.h"

char *substr(char *str, int start, int len)
{
	if (!str) return (NULL);
	char *sub = malloc(sizeof(char) * (len +1));
	if (!sub) return (NULL);
	int i = 0;
	if (start < strlen(str)){
		for (i = 0; i < len; i++){
			if (str[start + i] == '\0') break;
			sub[i] = str[start + i];
		}
	}
	sub[i] = '\0';
	return (sub);
}

char *strjoin(char *s1, char *s2)
{
	if (!s1 || !s2) return (NULL);
	char *join = malloc(sizeof(char) * (strlen(s1) + strlen(s2)));
	if (!join) return (NULL);
	int i, j;
	for (i = 0; i < strlen(s1); i++)
		join[i] = s1[i];
	for (j = 0; j < strlen(s2); j++)
		join[i + j] = s2[j];
	join[i+j] = '\0';
	return (join);
}

char *strtrim(char *str, char *set)
{
	if (!str) return (NULL);
	if (!set) return (strdup(str));
	int start = 0, end = strlen(str);
	while (strchr(set, str[start]))
		start++;
	while (strchr(set, str[end]))
		end--;
	if (start > end) return (NULL);
	return (substr(str, start, end - start + 1));
}

char **split(char *str, char c)
{
	if (!str) return (NULL);
	int splits = 0;
	for (int i = 0; i < strlen(str); i++)
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			splits++;
	char **arry = malloc(sizeof(char *) * (splits + 1));
	if (!arry) return (NULL);
	arry[splits] = NULL;
	for (int i = 0, j = 0; i < splits;){
		if (str[j] == c) j++;
		else {
			int k = 0;
			while (str[j + k] != '\0' && str[j + k] != c)
				k++;
			arry[i] = substr(str, j, k);
			j += k;
			i++;
		}
	}
	return (arry);
}

char *itoa(int n)
{
	bool neg = n < 0;
	unsigned int un = n * (1 + (-2 * neg));
	int d = 1 + neg;
	for (;n > 9 || n < -9; d++)
		n /= 10;
	char *num = malloc(sizeof(char) * (d + 1));
	if (!num) return (NULL);
	num[d] = '\0';
	while (d > 0){
		d--;
		if (d == 0 && neg){
			num[0] = '-';
			break;
		}
		num[d] = ((un % 10)) + '0';
		un /= 10;
	}
	return (num);
}

char *strmapi(char const *s, char (*f)(unsigned int, char))
{
	if (!s) return (NULL);
	char *str = strdup(s);
	if (!str) return (NULL);
	for (unsigned int i = 0; str[i] != '\0'; i++)
		str[i] = (*f)(i, str[i]);
	return (str);
}

void striteri(char *s, void (*f)(unsigned int, char *))
{
	if (!s) return;
	for (unsigned int i = 0; s[i] != '\0'; i++)
		(*f)(i, s + i);
}
