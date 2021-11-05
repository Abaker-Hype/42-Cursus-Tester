#include "tester.h"

# define subcore(format, info, test, ...) \
	if (detail) testinfo(info, test + 1, format, __VA_ARGS__); \
	result = ft_printf(format, __VA_ARGS__); \
	expected = asprintf(&output, format, __VA_ARGS__);

bool exists_printf()
{
	return (ft_printf != NULL);
}

void printftestcore(printftest test, int testnum,  bool detail)
{
	bool pass = true;
	char *output = NULL;
	int result, expected;
	switch (test.datasize){
		case 0:
			subcore(test.format, test.info, testnum, NULL);
			break;
		case 1:
			subcore(test.format, test.info, testnum, test.data[0]);
			break;
		case 2:
			subcore(test.format, test.info, testnum, test.data[0], test.data[1]);
			break;
		case 3:
			subcore(test.format, test.info, testnum, test.data[0], test.data[1], test.data[2]);
			break;
		case 4:
			subcore(test.format, test.info, testnum, test.data[0], test.data[1], test.data[2], test.data[3]);
			break;
		case 5:
			subcore(test.format, test.info, testnum, test.data[0], test.data[1], test.data[2], test.data[3], test.data[4]);
			break;
		case 6:
			subcore(test.format, test.info, testnum, test.data[0], test.data[1], test.data[2], test.data[3], test.data[4], test.data[5]);
			break;
		case 7:
			subcore(test.format, test.info, testnum, test.data[0], test.data[1], test.data[2], test.data[3], test.data[4], test.data[5], test.data[6]);
			break;
		default:;
	}
	if (result != expected || !checkoutput(output, expected))pass = false;
	if (detail) resultinfo("i*o", result," - ", useroutput(), expected, " - ", output);
	if (output) free(output);
	if (pass) setgrade(PASS);
}
