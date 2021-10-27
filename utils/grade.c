#include "tester.h"

grade resault = FAIL;

void setgrade(grade g)
{
	resault = g;
}

void printgrade(bool detail)
{
	if (detail)
		printf("Grade: ");
	printf("\e[31m");
	switch (resault){
		case PASS:
			printf("\e[32mP");
			 break;
		case SEGV:
			 printf("S");
			 break;
		case ABRT:
			 printf("A");
			 break;
		case TIME:
			 printf("T");
		default:
			 printf("F");
	}
	if(hasleaks()){
		printf("\e[31m");
		printf("(L)");
		freeleaks();
	}
	printf("\e[37m");
}
