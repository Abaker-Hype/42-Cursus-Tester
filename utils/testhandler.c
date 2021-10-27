#include "tester.h"
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

bool	detail = false;

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
	printgrade(detail);
	exit(EXIT_FAILURE);
}

static void setsignals()
{
	signal(SIGSEGV, sighandler);
	signal(SIGALRM, sighandler);
	signal(SIGBUS, sighandler);
	signal(SIGABRT, sighandler);
}

void	testhandler(testfunc test, int maxtests, int testnum, bool detailed)
{
	int tests = testnum;
	detail = detailed;
	if (tests == 0)
		tests = (*test.tests)();
	if (!detailed)
		printf("%-16s\e[96m-\e[37m ", test.name);
	if ((*test.exists)()) {
		for (int i = 0; i < tests; i++) {
			if (testnum != 0)
				i += testnum - 1;
			fflush(stdout);
			pid_t tester = fork();
			if (tester == 0){
				setsignals();
				if (hasleaks()) freeleaks();
				alarm(2);
				(*test.run)(i, detailed);
				alarm(0);
				printgrade(detailed);
				exit(EXIT_SUCCESS);
			} else {
				starttimer();
				waitpid(tester, NULL, 0);
				stoptimer();
			}
		}
		if (!detailed)
			printf("\e[96m%*c\e[37m", maxtests+2-tests, '-');
		if (testnum != 0)
			tests = 0;
		printtime(tests + 1, detailed);
	} else
		printf("\e[41mNTI\e[49m");
	printf("\n");
}
