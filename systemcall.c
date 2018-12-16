#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

	
void main()
{
 	int fd ,sz;
	fd=open("input131.dat",O_WRONLY|O_CREAT|O_TRUNC);
	int sizename,sizeaddress;
	char sizen[2];
	char sizea[2];
	
	char address[20];
	char name[]=" ";
scanf("%s\n",name);
	scanf("%s\n",address);
	sizename=strlen(name);
	sizeaddress=strlen(address);	
	sprintf(sizen,"%d",sizename);
	sprintf(sizea,"%d",sizeaddress);
	printf("%s",sizen);
	sz=write(fd,name,strlen(name));
	sz=write(fd,"\t",strlen("\t"));
	sz=write(fd,sizen,strlen(sizen));

	
	
}
