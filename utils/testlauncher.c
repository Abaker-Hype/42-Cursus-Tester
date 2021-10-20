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

static void	testhandler(testfunc test)
{
	int tests = (*test.tests)();
	printf("%-16s", test.name);
	if ((*test.exists)()) {
		for (int i = 0; i < tests; i++) {
			fflush(stdout);
			pid_t tester = fork();
			if (tester == 0){
				setsignals();
				alarm(2);
				(*test.run)(i);
				alarm(0);
				exit(EXIT_SUCCESS);
			} else 
			waitpid(tester, NULL, 0);
		}
	} else
		printf("NTI");
	printf("\n");
}

int main(int argc, char **argv)
{
	if (argc == 1 || argc > 2){
		printf("Invalid Args Count\n");
		return (0);
	}
	printf("Run tests for %s\n", argv[1]);
	printf("---FUNCTION---    ---TEST---\n");
	int tests = testcount(LIBFT);
	for (int i = 0; i < tests; i++){
		testhandler(*gettest(LIBFT, i));
	}
}
