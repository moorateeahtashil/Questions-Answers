#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

void funct1()
{
	printf("Alarm Triggered\n");
}
void main()
{
	struct timeval start,end;
	gettimeofday(&start,NULL);
	int i=0;
	for(i;i<10;i++)
	{
	signal(SIGALRM,funct1);
	alarm(5);
	pause();
	gettimeofday(&end,NULL);
	printf("Number of second elapsed : %ld\n",end.tv_sec-start.tv_sec);
	}
}

