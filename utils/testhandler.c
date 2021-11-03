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

static void runfunctest(testfunc *test,int start, int total)
{
	pid_t tester;
	for (int i = 0; i < total; i++){
		fflush(stdout);
		if ((tester = fork()) == 0){
			setsignals();
			alarm(2);
			(*test->run)(start + i, args.detail);
			alarm(0);
			printgrade(args.detail);
			exit(EXIT_SUCCESS);
		} else {
			starttimer();
			waitpid(tester, NULL, 0);
			stoptimer();
			if (args.detail){
				printtime(1);
				printf("\n");
				for (int j = 0; j < 50; j++)
					cprintf("--", PINK, DEFAULT);
				printf("\n");
			}
		}
	}
}

static void	funchandler(testfunc *test)
{
	if (args.group && strcmp(args.group, test->group) != 0) return;
	if (args.bonus && !test->bonus) return;
	int start = args.test;
	int total = 1;
	if (start == -1){
		total = (*test->tests)();
		start = 0;
	}
	if (!args.detail){
		cprintf("%s", DBLUE, DEFAULT, test->group);
		addcolsep(strlen(test->group), 0);
		cprintf("%s", WHITE, DEFAULT, test->name);
		addcolsep(strlen(test->name), 1);
	}
	if ((*test->exists)()) {
		runfunctest(test, start, total);
		if (!args.detail){
			addcolsep(total - 1, 2); 
			printtime(total);
		}
	} else
		cprintf("NTI", WHITE, RED);
	printf("\n");
}

void testhandler()
{
	if (args.func) funchandler(args.func);
	else {
		int tests = gettestsize(args.testing);
		for (int i = 0; i < tests; i++)
			funchandler(gettest(args.testing, i));
	}
}
