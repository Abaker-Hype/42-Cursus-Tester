#ifndef TESTER_H
# define TESTER_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "dummyheaders.h"

typedef struct s_case {
	void **inputs;
	void *expected;
	char *output;
}	t_case;

//Write Chk Funcs
bool	checkoutput(char *compare, int len);
void	resetprinted();
void	outputuser();

//Leak Chk Funcs
bool	hasleaks();
void	freeleaks();
void	listleaks(bool unique);

#endif
