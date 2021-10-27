#include "tester.h"

static t_args	parseargs(int argc, char **argv)
{
	t_args args;
	if (strcmp(argv[1], "libft") == 0)
		args.testing = LIBFT;
	else if (strcmp(argv[1], "printf") == 0)
		args.testing = PRINTF;
	else if (strcmp(argv[1], "gnl") == 0)
		args.testing = GNL;
	args.maxtests = getmaxtests(args.testing);
	if (argc > 2){
		args.func = gettestbyname(args.testing, argv[2]);
		if (!args.func)
			printf("\e[93mWarning tests for: %s not found (Prob incorrect spelling)\n--Running all tests for %s instead--\e[37m\n",argv[2], argv[1]);
	}
	else 
		args.func = NULL;
	if (argc == 4 && args.func){
		args.test = atoi(argv[3]);
		if (args.test > (*args.func->tests)()){
			printf("\e[93mWarning: %i is an invalid test number for %s\n--Running all tests for %s instead--\e[37m\n", args.test, argv[2], argv[2]); 
			args.test = 0;
		}
	}
	else
		args.test = 0;
	if (!args.func)
		args.testcount = testcount(args.testing);
	else
		args.testcount = 1;
	return args;
}

int main(int argc, char **argv)
{
    if (argc == 1 || argc > 4){
        printf("Invalid Args Count\n");
        return (0);
    }
	t_args args = parseargs(argc, argv);
	if (args.func)
		printf("Running test/s for %s\n",args.func->name);
	else
    	printf("Running tests for %s\n", argv[1]);
    printf("\e[96m---FUNCTION---     ----TEST----      --AVGTIME--\e[37m\n");
	for (int i = 0; i < args.testcount; i++){
		if (args.func)
			testhandler(*args.func, args.maxtests, args.test);
		else
        	testhandler(*gettest(LIBFT, i), args.maxtests, 0);
    }
}
