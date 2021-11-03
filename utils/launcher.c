#include "tester.h"

int main(int argc, char **argv)
{
	if (!parseargs(argc, argv)) return (0);
	if (args.func) cprintf("Running test/s for %s\n", LBLUE, DEFAULT, args.func->name);
	else cprintf("Running test/s for %s\n",PINK, DEFAULT, argv[1]);
	loadcolumns();
	testhandler();
	gradeinfo();
}
