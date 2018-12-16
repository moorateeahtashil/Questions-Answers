#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main()
{

	int fd[2];
	int p;
	int n;
	int x;
	char line[20];
	x=pipe(fd);
	p=fork();
	if(p==0)
	{
		printf("Hello I am the child\n");
		close(fd[1]);
		n=read(fd[0],line,12);
		printf("%s\n",line);

	}
	else
	{
		close(fd[0]);
		write(fd[1],"Hello\n",strlen("Hello"));
	}
		exit(0);
	}
