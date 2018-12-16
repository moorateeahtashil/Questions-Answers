#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void * funct1(void * arg);
int i=0;;
 pthread_mutex_t mylock=PTHREAD_MUTEX_INITIALIZER;
 
int main()
{ 
  pthread_t threadid;
  int j;
   			int x=1;                                                                            
 
 pthread_create(&threadid,NULL,funct1,(void *)&x);
  for (j=0; j <10; j++){
pthread_mutex_lock(&mylock);
   for (i; i<10; i++);{
     printf("Hi I'm the parent\n");
	printf("%d",i);
sleep(1);
   }
pthread_mutex_unlock(&mylock);

}
pthread_join(threadid,NULL);
return 0;
}
 void * funct1(void * arg)
  { int j;
 
  for (j=0;j<10; j++){
pthread_mutex_lock(&mylock);

    for (i; i<15; i++){

printf("%d",i);
     printf("Hi I'm the created thread\n");
	 sleep(1);
   }
pthread_mutex_unlock(&mylock);
        }
pthread_exit(NULL);
}
