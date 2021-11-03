#include "tester.h"

char *headers[] = {
	"--GROUP--",
	"--FUNCTION--",
	"--TESTS--",
	"--AVGTIME--"
};

int col[] = {0,0,0};

static int	ncmp(int n1, int n2)
{
	if (n2 > n1) return (n2);
	return (n1);
}

static void initcols()
{
	for (int i = 0; i < arraysize(headers) - 1; i++)
		col[i] = strlen(headers[i]);
	if (args.func){
		col[0] = ncmp(col[0], strlen(args.func->group));
		col[1] = ncmp(col[1], strlen(args.func->name));
		col[2] = ncmp(col[2], (*args.func->tests)());
	}else{
		testfunc *arry = gettestarry(args.testing);
		int size = gettestsize(args.testing);
		if (args.group) col[0] = ncmp(col[0], strlen(args.group));
		for (int i = 0; i < size; i++){
			if (!args.group) col[0] = ncmp(col[0], strlen(arry[i].group));
			if (!args.group || strcmp(args.group, arry[i].group) == 0){
				col[1] = ncmp(col[1], strlen(arry[i].name));
				col[2] = ncmp(col[2], (*arry[i].tests)());
			}
		}
	}
	col[0]++;
	col[1]++;
	col[2]++;
}

void loadcolumns()
{
	if (args.detail) return;
	initcols();
	cprintf(" %-*s|", LBLUE, DEFAULT, col[0], headers[0]);
	cprintf(" %-*s|", LBLUE, DEFAULT, col[1], headers[1]);
	cprintf(" %-*s|", LBLUE, DEFAULT, col[2], headers[2]);
	cprintf(" %s\n", LBLUE, DEFAULT, headers[3]);
}

void addcolsep(int printed, int c)
{
	cprintf("%*s", LBLUE, DEFAULT, col[c] - printed + (3 - c), "- ");
}
