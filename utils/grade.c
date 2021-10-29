#include "tester.h"

char *SEGVPASS = "Your Function SEGV but this is fine as the func you are replicating also SEGVs\nMoulenette wont test this\n";

grade result = FAIL;
bool	segvpass = false;

void setgrade(grade g)
{
	result = g;
}

void	passsegv()
{
	segvpass = true;
}

void printgrade(bool detail)
{
	char grade = 'F';
	colour c = RED;
	if (detail){
		if (segvpass && result == SEGV) cprintf(SEGVPASS, YELLOW, DEFAULT);
		cprintf("Grade: ", LBLUE, DEFAULT);
	}
	switch (result){
		case PASS:
			grade = 'P';
			c = GREEN;
			break;
		case SEGV:
			grade = 'S';
			if(segvpass) c = GREEN;
			break;
		case ABRT:
			c = 'A';
			break;
		case TIME:
			c = 'T';
			break;
		default:;
	}
	cprintf("%c", c, DEFAULT, grade);
	if(hasleaks()){
		cprintf("(L)", RED, DEFAULT);
		freeleaks();
	}
}
