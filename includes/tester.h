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
# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define UINT_MAX 4294967295

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
	char	*group;
	bool	bonus;
} testfunc;

typedef struct {
	tester testing;
	testfunc *func;
	char *group;
	bool bonus;
	int test;
	int totalran;
	bool detail;
}	t_args;

//Global Var
extern t_args args;

//Testing Funcs
bool	parseargs(int argc,char **argv);
void	loadcolumns();
void	addcolsep(int printed, int c);
void	testhandler();
testfunc *gettestarry(tester t);
int		gettestsize(tester t);
testfunc *gettest(tester t, int n);
testfunc *gettestbyname(tester t, char *str);
bool	chkgroup(tester t, char *str);

//Grade Funcs
void	setgrade(grade g);
void	passsegv();
void	printgrade();
void	gradeinfo();

//Text Funcs
void    cprintf(char *str, colour txt, colour bkgrd,...);
void	testinfo(char *format, int test,...);
void	resultinfo(char *format,...);

//Timer Funcs
void	starttimer();
void	stoptimer();
void	printtime(int tests);

//Write Chk Funcs
bool	checkoutput(char *compare, int len);
void	resetprinted();
char	*useroutput();

//Leak Chk Funcs
bool	hasleaks();
void	freeleaks();
void	listleaks();
void	free_track(void *ptr, bool check);

#endif
