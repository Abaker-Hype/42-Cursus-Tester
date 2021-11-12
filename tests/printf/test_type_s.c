#include "tester.h"

printftest type_s_tests[] = {
	{" %s ", 1, "ss", {{.s="string"}}},
	{" %s %s ", 2, "sss",{{.s="SUFFER\n"}, {.s="SUFFER AGAIN"}}},
	{" %s ", 1, "ss", {{.s=NULL}}},
	{"NULL %s NULL", 1, "ss", {{.s=NULL}}},
	{"%s", 1, "ss", {{.s=""}}},
	{"\\%s\\", 1, "ss", {{.s="\\"}}},
	{"%s", 1, "ss", {{.s="] str[\"FUCK YOU\"]"}}},
	{" %s ", 2, "sv", {{.s="test\0test"}, 9}},
	{"%s", 1, "ss", {{.s="⛵⛱⛄❎⚡"}}},
	{" %s %s %s ", 3, "ssss",{{.s="sdagkjhag"}, {.s="4w5y92045j"}, {.s="}{:}\\><:\"*&^#$"}}},
	{" %s ", 1, "ss", {{.s="\r\t\v\f\n "}}}
};

int tests_type_s()
{
	return (arraysize(type_s_tests));
}

void	test_type_s(int n, bool detail)
{
	printftestcore(type_s_tests[n], n, detail);
}
