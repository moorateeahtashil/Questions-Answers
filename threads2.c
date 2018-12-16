#include <sys/stat.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>


void * thread1(void * arg);
void * thread2(void *arg);

float power(float x,int num)
{

	if(num==0)
	{return 0;}
	return x+power(x,num-1);
}

void calculatesin(float x)
{
	float sin=0;  
	int i;	
	int po=3;
	for(i=0;i<100;i++)
	{
		sin+=power(x,po);
	po=po+2;	
	}
	sin=x-sin;
}
void calculatesin2(float *x)
{
	float sin=0;  
	int i;	
	int po=3;
	for(i=0;i<100;i++)
	{
		sin+=power(*x,po);
	po=po+2;	
	}
	sin=*x-sin;
	printf("%f",sin);
}


void *funct1(void * arg);
void * funct2(void * arg);

void main()
{
	
	float x;
	scanf("%f",&x);
	pthread_t threa1;
	pthread_t threa2;
	pthread_create(&threa1,NULL,thread1,(void *)&x);
	pthread_create(&threa2,NULL,thread2,(void *)&x);

	pthread_join(threa1,NULL);
	pthread_join(threa2,NULL);
}

void * thread1(void * arg){
	float *x=(float *) arg;
	calculatesin2(x);
	pthread_exit(NULL);
}

void * thread2(void * arg){
	float *x=(float *) arg;
	calculatesin2(x);
	pthread_exit(NULL);
}		
