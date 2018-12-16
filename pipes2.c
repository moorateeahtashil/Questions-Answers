#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void main()
{

	int fd[2];
	int fd1;
	int p;
	char buff[50];
char buff1[50];
	int x,sz,n;

	x=pipe(fd);
	p=fork();
	fd1=open("myfiles.txt",O_CREAT);
	if(p==0)
	{
		close(fd[1]);
		n=read(fd[0],buff1,20);
		printf("%s\n",buff1);
	}
	else
	{
		close(fd[0]);
		sz=read(fd1,buff,20);
		write(fd[1],buff,strlen(buff));
printf("%s\n",buff);
	}
	exit(0);
}
