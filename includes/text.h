#ifndef TEXT_H
# define TEXT_H

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

//Global Strings (Init here. Set in utils/strings.c) (Mostly for strings needed in Detailed Tests)
char *TESTINFO;
char *TESTINTRSLT;
char *TESTSTRRSLT;

void	cprintf(char *str, colour txt, colour bkgrd,...);

#endif
