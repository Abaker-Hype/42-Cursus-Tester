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

void	testhandler(testfunc test, int maxtests, int testnum)
{
	int tests = testnum;
	if(tests == 0) tests = (*test.tests)() -1;
	printf("%-16s\e[96m-\e[37m ", test.name);
	if ((*test.exists)()) {
		for (int i = testnum; i <= tests; i++) {
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
		printf("\e[96m%*c\e[37m", maxtests+2-tests, '-');
		if (testnum != 0) tests = 0;
		printtime(tests + 1);
	} else
		printf("\e[41mNTI\e[49m");
	printf("\n");
}
