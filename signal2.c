#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

struct timeval start,end;
void file()
{
 gettimeofday(&end,NULL);
 printf ("s\n");
printf("%ld\n",end.tv_sec-start.tv_sec);
}

void main()
{
	struct itimerval timer;
	
     signal(SIGALRM, file);
	gettimeofday(&start,NULL);
	timer.it_value.tv_sec=1;
	timer.it_value.tv_usec=0;
	timer.it_interval.tv_sec=1;
	timer.it_interval.tv_usec=0;
	setitimer(ITIMER_REAL,&timer,NULL);

	pause();

while(((end.tv_sec-start.tv_sec)!=5)&&(1));
	
}

