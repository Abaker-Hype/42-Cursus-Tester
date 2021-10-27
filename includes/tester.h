#ifndef TESTER_H
# define TESTER_H

//All the system includes (Most for comparing libft funcs)
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <ctype.h>

//Special headers for weak fuctions
# include "dummyheaders.h"
# include "testfuncs.h"

//Linux header
# ifdef LINUX
#	include <bsd/string.h>
# endif

//Macros
# define arraysize(X) sizeof(X)/sizeof(X[0])

//Function pointer types
typedef void (*Run)(int a);
typedef bool (*Exists)();
typedef int (*Tests)();

//Enums
typedef enum {
	LIBFT,
	PRINTF,
	GNL
} tester;

typedef enum {
	PASS,
	FAIL,
	SEGV,
	ABRT,
	TIME,
	BUS
}	grade;

//Structs
typedef struct {
	Run run;
	Exists exists;
	Tests tests;
	char	*name;
	bool	bonus;
} testfunc;

//Universal Funcs
int testcount(tester t);
int getmaxtests(tester t);
testfunc *gettest(tester t, int n);
void	setgrade(grade g);
void	printgrade();

//Timer Funcs
void	starttimer();
void	stoptimer();
void	printtime(int tests);

//Write Chk Funcs
bool	checkoutput(char *compare, int len);
void	resetprinted();
void	outputuser();

//Leak Chk Funcs
bool	hasleaks();
void	freeleaks();
void	listleaks(bool unique);

#endif
