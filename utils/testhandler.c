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

static void runfunctest(testfunc test,int start, int total)
{
	pid_t tester;
	for (int i = 0; i < total; i++){
		fflush(stdout);
		if ((tester = fork()) == 0){
			setsignals();
			alarm(2);
			(*test.run)(start + i, detail);
			alarm(0);
			printgrade(detail);
			exit(EXIT_SUCCESS);
		} else {
			starttimer();
			waitpid(tester, NULL, 0);
			stoptimer();
			if (detail){
				printtime(1, true);
				printf("\n");
				for (int j = 0; j < 50; j++)
					cprintf("--", PINK, DEFAULT);
				printf("\n");
			}
		}
	}
}

void	testhandler(testfunc test, int start, int colwidth, bool detailed)
{
	int total = 1;
	detail = detailed;
	if (start == -1){
		total = (*test.tests)();
		start = 0;
	}
	if (!detailed)
		cprintf("%-16s \e[%im- ", WHITE, DEFAULT, test.name, LBLUE);
	if ((*test.exists)()) {
		runfunctest(test, start, total);
		if (!detailed){
			cprintf("%*c",LBLUE, DEFAULT, colwidth+2-total, '-');
			printtime(total, detailed);
		}
	} else
		cprintf("NTI", WHITE, RED);
	printf("\n");
}
