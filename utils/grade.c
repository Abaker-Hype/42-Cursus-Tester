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

void printgrade()
{
	char grade = 'F';
	colour c = RED;
	if (args.detail){
		if (segvpass && result == SEGV) cprintf(SEGVPASS, YELLOW, DEFAULT);
		if (hasleaks()) listleaks();
		cprintf("Grade: ", LBLUE, DEFAULT);
	}
	switch (result){
		case PASS:
			if (hasleaks()) grade = 'L';
			else {	
				grade = 'P';
				c = GREEN;
			}
			break;
		case SEGV:
			grade = 'S';
			if(segvpass) c = GREEN;
			break;
		case ABRT:
			grade = 'A';
			break;
		case TIME:
			grade = 'T';
			break;
		case BUS:
			grade = 'B';
			break;
		default:;
	}
	cprintf("%c", c, DEFAULT, grade);
	if (hasleaks()) freeleaks();
	if (useroutput()) resetprinted();
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
	cprintf(" = SEGV(PASS)\n",LBLUE, DEFAULT);
	cprintf("B", RED, DEFAULT);
	cprintf(" = Bus Error ", LBLUE, DEFAULT);
	cprintf("T", RED, DEFAULT);
	cprintf(" = Timeout ",LBLUE, DEFAULT);
	cprintf("A", RED, DEFAULT);
	cprintf(" = Abort  ",LBLUE, DEFAULT);
	cprintf("L", RED, DEFAULT);
	cprintf(" = Leaks\n",LBLUE, DEFAULT);
}
