#include "tester.h"
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

static void	sighandler(int sig)
{
	switch (sig){
		case SIGABRT :
			printf("A");
			break;
		case SIGSEGV :
			printf("S");
			break;
		case SIGALRM :
			printf("T");
			break ;
		case SIGBUS :
			printf("B");
			break;
		default :;
	}
	exit(EXIT_FAILURE);
}

static void setsignals()
{
	signal(SIGSEGV, sighandler);
	signal(SIGALRM, sighandler);
	signal(SIGBUS, sighandler);
	signal(SIGABRT, sighandler);
}

static void	testhandler(int test)
{
	int *p = NULL;
	fflush(stdout);
	pid_t tester = fork();
	if (tester == 0){
		setsignals();
		alarm(2);
		switch (test){
			case 2: sleep(7);
				break;
			case 4: *p = 1;
				break ;
			case 7: printf("F");
				break ;
			default: printf("P");
		}
		alarm(0);
		exit(EXIT_SUCCESS);
	} else {
		waitpid(tester, NULL, 0);
	}
}

int main(int argc, char **argv)
{
	char *test[] = {"ft_split", "ft_strlen", "ft_putchar", "ft_strnstr"};
	if (argc == 1 || argc > 2){
		printf("Invalid Args Count\n");
		return (0);
	}
	printf("Run tests for %s\n", argv[1]);
	printf("---FUNCTION---    ---TEST---\n");
	for (int j = 0; j < 4; j++){
		printf("%-16s", test[j]);
		for (int i = 0; i < 10; i++){
			testhandler(i);
		}
		printf("\n");
	}
}
