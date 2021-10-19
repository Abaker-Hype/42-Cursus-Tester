#include "tester.h"
#include "macros.h"

int main(void)
{
	char *str;

	write(1,"hello",5);
	write(1," ",1);
	write(1,"world",5);

	if(checkoutput("hello world", 11))
		printf("Same\n");
	else
		printf("Diff\n");
	outputuser();
	printf("[hello world]\n");
	printf("\n");

	for(int i = 0; i < 1; i++){
		str = malloc(10);
	}
	free(str);
	listleaks(false);
	printf("\n");
	listleaks(true);
	freeleaks();
	printf("test\e[s\n1234567890");
	printf("\e[u - No");
}
