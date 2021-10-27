#include "tester.h"
#include <sys/time.h>


struct timeval start, end;
long	microsec = 0;

void	starttimer()
{
	gettimeofday(&start, NULL);
}

void	stoptimer()
{
	gettimeofday(&end, NULL);
	long seconds = (end.tv_sec - start.tv_sec);
	microsec += (long)(((seconds * 1000000) + end.tv_usec) - start.tv_usec);
}

void	printtime(int tests)
{
	if(tests == 0) tests = 1;
	printf("\e[93m %.4fms\e[37m", (double)(microsec/tests)/1000);
	microsec = 0;
}
