#include "tester.h"
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

static void	sighandler(int sig)
{
	switch (sig){
		case SIGABRT :
			setgrade(ABRT);
			break;
		case SIGSEGV :
			setgrade(SEGV);
			break;
		case SIGALRM :
			setgrade(TIME);
			break ;
		case SIGBUS :
			setgrade(BUS);
			break;
		default :
			exit(EXIT_FAILURE);;
	}
	printgrade();
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
	printf("%-16s\e[96m-\e[37m ", test.name);
	if ((*test.exists)()) {
		for (int i = 0; i < tests; i++) {
			fflush(stdout);
			pid_t tester = fork();
			if (tester == 0){
				setsignals();
				if (hasleaks()) freeleaks();
				alarm(2);
				(*test.run)(i);
				alarm(0);
				printgrade();
				exit(EXIT_SUCCESS);
			} else {
				starttimer();
				waitpid(tester, NULL, 0);
				stoptimer();
			}
		}
		printf("\e[96m%*c\e[37m", 14-tests, '-');
		printtime(tests);
	} else
		printf("\e[41mNTI\e[37m");
	printf("\n");
}

int main(int argc, char **argv)
{
	if (argc == 1 || argc > 2){
		printf("Invalid Args Count\n");
		return (0);
	}
	printf("Run tests for %s\n", argv[1]);
	printf("\e[96m---FUNCTION---    ---TEST---     --AVGTIME--\e[37m\n");
	int tests = testcount(LIBFT);
	for (int i = 0; i < tests; i++){
		testhandler(*gettest(LIBFT, i));
	}
}
