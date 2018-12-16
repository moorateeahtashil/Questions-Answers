#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main()
{
	printf("Enter the number of user");
	int n;
	scanf("d",n);
	int i,p;
	for(i=0;i<n;i++)
	{
	 p=fork();
		
	
	
