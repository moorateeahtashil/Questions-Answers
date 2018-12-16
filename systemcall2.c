#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

	
void main()
{

	int fd=open("input131.dat",O_RDONLY);
	char buff[100];
	char dummy[200];
	int count=0;
	while(read(fd,buff,1))
		{
printf("%s",buff);
	int result=strcmp(buff,"A");
printf("%d\n",result);
if(result==78)
{
		printf("%d",count);	
read(fd,buff,1);
}
dummy[count]=buff[0];
count++;
		}	
		
printf("%s\n",dummy);
}	
