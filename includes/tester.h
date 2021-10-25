#ifndef TESTER_H
# define TESTER_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
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

typedef enum {
	PASS,
	FAIL,
	SEGV,
	ABRT,
	TIME,
	BUS
}	grade;

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
void	setgrade(grade g);
void	printgrade();
void	starttimer();
void	stoptimer();
void	printtime(int tests);

//libft test funcs
int		tests_isalpha();
bool	exists_isalpha();
void	test_isalpha(int n);
int		tests_isdigit();
bool	exists_isdigit();
void	test_isdigit(int n);
int     tests_isalnum();
bool    exists_isalnum();
void    test_isalnum(int n);
int     tests_isascii();
bool    exists_isascii();
void    test_isascii(int n);
int     tests_isprint();
bool    exists_isprint();
void    test_isprint(int n);
int     tests_strchr();
bool    exists_strchr();
void    test_strchr(int n);
int     tests_strncmp();
bool    exists_strncmp();
void    test_strncmp(int n);
int     tests_strrchr();
bool    exists_strrchr();
void    test_strrchr(int n);
int     tests_strlen();
bool    exists_strlen();
void    test_strlen(int n);
int     tests_tolower();
bool    exists_tolower();
void    test_tolower(int n);
int     tests_toupper();
bool    exists_toupper();
void    test_toupper(int n);
int     tests_bzero();
bool    exists_bzero();
void    test_bzero(int n);
int     tests_memset();
bool    exists_memset();
void    test_memset(int n);

//Write Chk Funcs
bool	checkoutput(char *compare, int len);
void	resetprinted();
void	outputuser();

//Leak Chk Funcs
bool	hasleaks();
void	freeleaks();
void	listleaks(bool unique);

#endif
