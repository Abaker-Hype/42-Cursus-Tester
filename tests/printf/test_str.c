#include "tester.h"

printftest str_tests[] = {
	{" %s ", 1, "ss", {{.s="string"}}},
	{" %s %s ", 2, "sss",{{.s="SUFFER\n"}, {.s="SUFFER AGAIN"}}},
	{" %s ", 1, "ss", {{.s=NULL}}},
	{"%s", 1, "ss", {{.s=""}}},
	{"%s", 1, "ss", {{.s="] str[\"FUCK YOU\"]"}}},
	{" %s ", 2, "sv", {{.s="test\0test"}, 9}},
	{" %s %s %s ", 3, "ssss",{{.s="sdagkjhag"}, {.s="4w5y92045j"}, {.s="}{:}\\><:\"*&^#$"}}},
	{" %s ", 1, "ss", {{.s="\r\t\v\f\n "}}}
};

int tests_str()
{
	return (arraysize(str_tests));
}

void	test_str(int n, bool detail)
{
	printftestcore(str_tests[n], n, detail);
}
