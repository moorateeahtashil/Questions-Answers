#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
void * thread1(void * arg);
void * thread2(void * arg);
int size=3;
void main()
{
	pthread_t threadid1;
	pthread_t threadid2;
	
	char name[3][50];
	int i;
	int *id=(int *)malloc(3*sizeof(int));
	for(i=0;i<3;i++)
	{
		scanf("%s",name[i]);
		scanf("%d",&id[i]);
		
	}	
pthread_create(&threadid1,NULL,thread1,(void *)id);
pthread_create(&threadid2,NULL,thread2,(void *)name);
	sleep(7);
	

}

void * thread1(void *arg)
{
	int *val=(int *) arg;
	int i;
	for(i=0;i<size;i++)
	{
		printf("Id : %d\n",val[i]);
		sleep(1);
	}
}

void * thread2(void * arg)
{
	char *name=(char *) arg;
	int i;
	for(i=0;i<size;i++)
	{
		printf("Name : %s\n",&name[i]);
		sleep(1);
	}
}
