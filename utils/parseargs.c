#include "tester.h"

t_args args;

//Strings
char    *WARNFUNC = "Warning tests for: %s not found (Prob incorrect spelling)\n--Running all tests for %s instead--\n";
char    *WARNNUM = "Warning: %s is an invalid test number for %s\n--Running all tests for %s instead--\n";
char    *ERRTESTER = "ERROR: %s isn't a valid tester\n";
char    *ERRARGC = "ERROR: only between 1-3 args are accepted\nYou supplied %i\n";

static void	loaddefaultargs()
{
	args.func = NULL;
	args.group = NULL;
	args.bonus = false;
	args.test = -1;
	args.totalran = 0;
	args.detail = false;
}

static bool parsetester(char *arg)
{
	if (!arg) return (false);
	if (strcmp(arg, "libft") == 0) args.testing = LIBFT;
	else if (strcmp(arg, "printf") == 0) args.testing = PRINTF;
	else if (strcmp(arg, "gnl") == 0) args.testing = GNL;
	else return (false);
	return (true);
}

bool parseargs(int argc, char **argv)
{
	loaddefaultargs();
	if (argc == 1){
		cprintf(ERRARGC, RED, DEFAULT, argc - 1);
		return (false);
	} else if (!parsetester(argv[1])){
		cprintf(ERRTESTER, RED, DEFAULT, argv[1]);
		return (false);
	}
	if (argc == 2) return (true);
	args.func = gettestbyname(args.testing, argv[2]);
	if (!args.func){
		if (strcmp(argv[2], "Bonus") == 0) args.bonus = true;
		else if (chkgroup(args.testing, argv[2])) args.group = argv[2];
		else cprintf(WARNFUNC, YELLOW, DEFAULT, argv[2], argv[1]);
	}
	if (argc == 3) return (true);
	if (args.func){
		if (strcmp(argv[3], "detail") == 0) args.detail = true;
		else{
			args.test = atoi(argv[3]) - 1;
			if (args.test < 0 || args.test >= (*args.func->tests)()){
				cprintf(WARNNUM, YELLOW, DEFAULT, argv[3], argv[2], argv[2]);
				args.test = -1;
			} else 
				args.detail = true;
		}
	}
	return (true);
}
