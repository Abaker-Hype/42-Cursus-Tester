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
			if (hasleaks()) grade = 'L';
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
		default:
			if (hasleaks()) grade = 'L';
	}
	cprintf("%c", c, DEFAULT, grade);
	if (hasleaks()) freeleaks();
}

void	gradeinfo()
{
	cprintf("\nGRADE INFO\n", PINK, DEFAULT);
	cprintf("P", GREEN, DEFAULT);
	cprintf(" = Pass  ",LBLUE, DEFAULT);
	cprintf("F", RED, DEFAULT);
	cprintf(" = Fail  ",LBLUE, DEFAULT);
	cprintf("S", RED, DEFAULT);
	cprintf(" = SEGV  ",LBLUE, DEFAULT);
	cprintf("S", GREEN, DEFAULT);
	cprintf(" = SEGV(PASS) ",LBLUE, DEFAULT);
	cprintf("T", RED, DEFAULT);
	cprintf(" = Timeout\n",LBLUE, DEFAULT);
	cprintf("A", RED, DEFAULT);
	cprintf(" = Abort  ",LBLUE, DEFAULT);
	cprintf("L", RED, DEFAULT);
	cprintf(" = Leaks (Wrong Return)  ",LBLUE, DEFAULT);
	cprintf("L", GREEN, DEFAULT);
	cprintf(" = Leaks (Correct Return)\n",LBLUE, DEFAULT);
}
