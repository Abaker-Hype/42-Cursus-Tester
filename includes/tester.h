#ifndef TESTER_H
# define TESTER_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "dummyheaders.h"

# define arraysize(X) sizeof(X)/sizeof(X[0])

typedef void (*Run)(int a);
typedef bool (*Exists)();
typedef int (*Tests)();

typedef enum {
	LIBFT,
	PRINTF,
	GNL
} tester;

typedef struct {
	Run run;
	Exists exists;
	Tests tests;
	char	*name;
	bool	bonus;
} testfunc;

//universal test funcs
int testcount(tester t);
testfunc *gettest(tester t, int n);

//libft test funcs
int		tests_isalpha();
bool	exists_isalpha();
void	test_isalpha(int n);
int		tests_isdigit();
bool	exists_isdigit();
void	test_isdigit(int n);

//Write Chk Funcs
bool	checkoutput(char *compare, int len);
void	resetprinted();
void	outputuser();

//Leak Chk Funcs
bool	hasleaks();
void	freeleaks();
void	listleaks(bool unique);

#endif
