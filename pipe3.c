#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
void main(char *argv[])
{
 	int fd[2],fd1,fd2,x,n,p,sz;
	char buff[30];
	char buff1[30];
	x=pipe(fd);
	p=fork();	
fd1=open(argv[0],O_CREAT);

	if(p==0)
	{
	close(fd[1]);
	x=read(fd[0],buff1,30);
	fd2=open(argv[1],O_WRONLY|O_CREAT);
	sz=write(fd2,buff1,strlen(buff1));
	}
	else
	{
	close(fd[0]);
	
	sz=read(fd1,buff,30);
	write(fd[1],buff,strlen(buff));
	}
}
