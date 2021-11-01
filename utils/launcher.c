#include "tester.h"

//Strings
char	*WARNFUNC = "Warning tests for: %s not found (Prob incorrect spelling)\n--Running all tests for %s instead--\n";
char	*WARNNUM = "Warning: %s is an invalid test number for %s\n--Running all tests for %s instead--\n";
char	*ERRTESTER = "ERROR: %s isn't a valid tester\n";
char	*ERRARGC = "ERROR: only between 1-3 args are accepted\nYou supplied %i\n";
char	*RUNTEST = "Running test/s for %s\n";
char	*COLHEADERS = "---FUNCTION---     ----TEST----      --AVGTIME--\n";

static t_args defaultargs()
{
	t_args args;
	args.func = NULL;
	args.testcount = 1;
	args.maxtests = 0;
	args.test = -1;
	args.detailed = false;
	return (args);
}

static tester parsetester(char *arg)
{
	if (strcmp(arg, "libft") == 0) return (LIBFT);
	if (strcmp(arg, "printf") == 0) return (PRINTF);
	if (strcmp(arg, "GNL") == 0) return (GNL);
	cprintf(ERRTESTER, RED, DEFAULT, arg);
	exit(0);
}

static t_args	parseargs(int argc, char **argv)
{
	if (argc == 1 || argc > 4){
		cprintf(ERRARGC, RED, DEFAULT, argc - 1);
		exit(0);
	}
	t_args args = defaultargs();
	args.testing = parsetester(argv[1]);
	args.maxtests = getmaxtests(args.testing);
	if (argc > 2){
		args.func = gettestbyname(args.testing, argv[2]);
		if (!args.func) cprintf(WARNFUNC, YELLOW, DEFAULT, argv[2], argv[1]);
	}
	if (argc == 4 && args.func){
		if (strcmp(argv[3], "detail") == 0) args.detailed = true;
		else {
			args.test = atoi(argv[3]);
			args.detailed = true;
			if (args.test > (*args.func->tests)() || args.test <= 0){
				cprintf(WARNNUM, YELLOW, DEFAULT, argv[3], argv[2], argv[2]); 
				args.test = 0;
				args.detailed = false;
			}
			args.test--;
		}
	}
	if (!args.func) args.testcount = testcount(args.testing);
	return args;
}

int main(int argc, char **argv)
{
	t_args args = parseargs(argc, argv);
	if (args.func) cprintf(RUNTEST, LBLUE, DEFAULT, args.func->name);
	else cprintf(RUNTEST,PINK, DEFAULT, argv[1]);
  if (!args.detailed) cprintf(COLHEADERS, LBLUE, DEFAULT);
	for (int i = 0; i < args.testcount; i++){
		if (args.func)
			testhandler(*args.func, args.test, args.maxtests, args.detailed);
		else
			testhandler(*gettest(LIBFT, i), args.test, args.maxtests, args.detailed);
	}
	gradeinfo();
	if (args.testcount == 1 && args.detailed && args.test == 4 && strcmp(args.func->name, "ft_strnstr") == 0){
		sleep(5);
		system("open https://www.youtube.com/watch?v=rTgj1HxmUbg");
	}
}
