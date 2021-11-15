#include "tester.h"
#include "macros.h"
#include <fcntl.h>

int BUFFER_SIZE;

bool exists_gnl()
{
	return (get_next_line != NULL);
}

void gnlcore(gnltest test, int n, bool detail)
{
	BUFFER_SIZE = test.buffer;
	bool pass = true;
	size_t linecap = 0;
	int fd = -1, i = 1;
	FILE *fp = NULL;
	char *result = NULL;
	if (test.file) {
		fd = open(test.file, O_RDONLY);
		fp = fopen(test.file, "r");
	}
	if (detail) testinfo("*s*i*i", n + 1, "FILE =", test.file, "FD =", fd, "BUFFER_SIZE =", BUFFER_SIZE); 
	if (fd == -1 || BUFFER_SIZE < 1) {
		result = get_next_line(fd);
		if (detail) resultinfo("s", result, NULL);
		if (result) {
			pass = false;
			free_track(result, true);
		}
	} else {
		while (true){
			char *expected = NULL;
			result = get_next_line(fd);
			int read = getline(&expected, &linecap, fp);
			if (!expected[0]) expected = NULL;
			if ((!result && expected) || (result && (!expected || strcmp(expected, result) != 0))) pass = false;
			if (detail) {
				cprintf("Line %i\n", YELLOW, DEFAULT, i++);
				resultinfo("s", result, expected);
			}
			if (result) free_track(result, true);
			if (expected) free_track(expected, false);
			if (read == -1 || !pass) break;
		}
	}
	if (pass) setgrade(PASS);
}
