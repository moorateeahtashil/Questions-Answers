#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void main()
{
	int p;
	p=fork();
	if(p==0)
	{
		
printf("ID of children process: %d\n",getpid());
		printf("ID of parent's child process : %d\n",getppid());
	}
	else
	{
sleep(1);
		printf("ID of parent process: %d\n",getpid());
		printf("ID of parent's parent process : %d\n",getppid());
	}
}
