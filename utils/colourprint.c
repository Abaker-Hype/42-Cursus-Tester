#include "tester.h"
#include <stdarg.h>

char *TESTINFO = "Test No. \e[%im%i\e[%im\nInput Arg/s = \e[%im%s\n";
char *TESTINTRSLT = "Your result: \e[%im%i\e[%im\nExpected: \e[%im%i\n";
char *TESTSTRRSLT = "Your result: \e[%im[%s]\e[%im\nExpected: \e[%im[%s]\n";



void	cprintf(char *str, colour txt, colour bkgrd,...)
{
	va_list args;
	printf("\e[%i;%im",txt ,bkgrd + 10);
	va_start(args, bkgrd);
	vprintf(str, args);
	va_end(args);
	printf("\e[39;49m");
}
