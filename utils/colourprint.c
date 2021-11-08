#include "tester.h"
#include <stdarg.h>

static void	cvprintf(char *type, char *mem, int size)
{
	printf("%s[", type);
	if (!mem) printf("(NULL)");
	else {
		for (int i = 0; i < size; i++){
			if (isspace(mem[i]) || !mem[i]){
				switch (mem[i]){
					case '\t': printf("\\t");
						break;
					case '\n': printf("\\n");
						break;
					case '\v': printf("\\v");
						break;
					case '\r': printf("\\r");
						break;
					case '\f': printf("\\f");
						break;
					case '\0': printf("\\0");
						break;
					default: printf(" ");
				}
			} else
				printf("%c", mem[i]);
		}
	}
	printf("] ");
}

void	testinfo(char *format, int test,...)
{
	va_list args;
	char c;
	char *str;
	cprintf("Test No. ", LBLUE, DEFAULT);
	cprintf("%i\n", YELLOW, DEFAULT, test);
	cprintf("Input Arg/s = ", LBLUE, DEFAULT);
	va_start(args, test);
	printf("\e[%i;%im", RED, DEFAULT + 10);
	for (int i = 0; format[i] != '\0'; i++){
		switch (format[i]){
			case 'i': printf("int[%i] ", va_arg(args, int));
				break;
			case 'u' :printf("unsigned int[%u] ", va_arg(args, unsigned int));
				break;
			case 'c': c = va_arg(args, int);
				cvprintf("char", &c, 1);
				break;
			case 's': str = va_arg(args, char *);
				if (str) cvprintf("str", str, strlen(str));
				else cvprintf("str", str, 0);
				break;
			case 'v': str = va_arg(args, char *);
				cvprintf("void", str, va_arg(args, int));
				break;
			case '*': printf("%s ", va_arg(args, char *));
				break;
			default:;
		}
	}
	va_end(args);
	printf("\n\e[39;49m");
}

void	resultinfo(char *format,...)
{
	va_list args;
	char c;
	char *str;
	char **arry;
	va_start(args, format);
	for (int i = 0; i < 2; i++){
		if (i == 0) cprintf("Your result: ", LBLUE, DEFAULT);
		else cprintf("Expected:    ", LBLUE, DEFAULT);
		printf("\e[%i;%im", YELLOW, DEFAULT + 10);
		for (int j = 0; format[j] != '\0'; j++){
			switch (format[j]){
				case 'i': printf("%i", va_arg(args, int));
					break;
				case 'c': c = va_arg(args, int);
					cvprintf("", &c, 1);
					break;
				case 's': str = va_arg(args, char *);
					if (str)cvprintf("", str, strlen(str));
					else cvprintf("", str, 0);
					break;
				case 'v': str = va_arg(args, char *);
					cvprintf("", str, va_arg(args, int));
					break;
				case 'o': str = va_arg(args, char *);
					cvprintf("printed", str, va_arg(args, int));
					break;
				case 'a': arry = va_arg(args, char **);
					int i = 0;
					if (!arry){
						cvprintf("", NULL, 0);
						break;
					}
					while (arry[i]){
						printf("\narry[%i] = ", i);
						cvprintf("", arry[i], strlen(arry[i]));
						i++;
					}
					printf("\narry[%i] = ", i);
					cvprintf("", arry[i], 1);
					break;
				case '*': printf("%s", va_arg(args, char *));
					break;
				default:;
			}
		}
		printf("\n\e[39;49m");
	}
	va_end(args);
}

void	cprintf(char *str, colour txt, colour bkgrd,...)
{
	va_list args;
	printf("\e[%i;%im",txt ,bkgrd + 10);
	va_start(args, bkgrd);
	vprintf(str, args);
	va_end(args);
	printf("\e[39;49m");
}
