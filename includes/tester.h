#ifndef TESTER_H
# define TESTER_H

//All the system includes (Mostly for comparing libft funcs)
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
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
typedef void (*Run)(int i, bool b);
typedef bool (*Exists)();
typedef int (*Tests)();

//Enums
typedef enum {
	LIBFT,
	PRINTF,
	GNL,
	NONE
} tester;

typedef enum {
	PASS,
	FAIL,
	SEGV,
	ABRT,
	TIME,
	BUS
}	grade;

typedef enum {
	WHITE = 97,
	BLACK = 30,
	RED = 91,
	YELLOW = 93,
	GREEN = 92,
	PINK = 95,
	LBLUE = 96,
	DBLUE = 94,
	DEFAULT = 39
} colour;

//Structs
typedef struct {
	Run run;
	Exists exists;
	Tests tests;
	char	*name;
	bool	bonus;
} testfunc;

typedef struct {
	tester testing;
	testfunc *func;
	int testcount;
	int maxtests;
	int test;
	bool detailed;
}	t_args;

//Testing Funcs
void	testhandler(testfunc test, int start, int colwidth, bool detailed);
int testcount(tester t);
int getmaxtests(tester t);
testfunc *gettest(tester t, int n);
testfunc *gettestbyname(tester t, char *str);

//Grade Funcs
void	setgrade(grade g);
void	passsegv();
void	printgrade(bool detail);
void	gradeinfo();

//Text Funcs
void    cprintf(char *str, colour txt, colour bkgrd,...);
void	testinfo(char *format, int test,...);
void	resultinfo(char *format,...);

//Timer Funcs
void	starttimer();
void	stoptimer();
void	printtime(int tests, bool detail);

//Write Chk Funcs
bool	checkoutput(char *compare, int len);
void	resetprinted();
void	outputuser();

//Leak Chk Funcs
bool	hasleaks();
void	freeleaks();
void	listleaks(bool unique);

#endif
