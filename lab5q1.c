#include <stdio.h>
#include <mpi.h>

int main(int argc,char *argv[]){

   MPI_Init(&argc,&argv);
   int rank,npes;
   int num=1000,a=15,b=10,c=11;
   int x,y,z,value,x1;
   MPI_Comm_size(MPI_COMM_WORLD,&npes);
   MPI_Comm_rank(MPI_COMM_WORLD,&rank);
   MPI_Status status;
   int fact=1;
   if(rank==0){
     
     MPI_Send(&a,1,MPI_INT,1,10,MPI_COMM_WORLD);
     MPI_Send(&b,1,MPI_INT,2,11,MPI_COMM_WORLD);
     MPI_Send(&c,1,MPI_INT,3,12,MPI_COMM_WORLD);

     MPI_Recv(&x,1,MPI_INT,1,10,MPI_COMM_WORLD,&status);
     MPI_Recv(&y,1,MPI_INT,2,11,MPI_COMM_WORLD,&status);
     MPI_Recv(&z,1,MPI_INT,3,12,MPI_COMM_WORLD,&status);
    
     fact=x*y*z;
	
     printf("Factorial of %d is %d \n",a+b+c,fact);
   }

   if(rank==1){
    int test=1;
    MPI_Recv(&value,1,MPI_INT,0,10,MPI_COMM_WORLD,&status);

    for(int i=1;i<value;i++){
         test=test*i;
	
      } 

    MPI_Send(&test,1,MPI_INT,0,10,MPI_COMM_WORLD);
   }


   if(rank==2){
    y=1;
    MPI_Recv(&value,1,MPI_INT,0,11,MPI_COMM_WORLD,&status);
    for(int i=1;i<value;i++){
         y=y*i;
printf("%d \n",y);
      } 
    MPI_Send(&y,1,MPI_INT,0,11,MPI_COMM_WORLD);
   }

   if(rank==3){
    z=1;
    MPI_Recv(&value,1,MPI_INT,0,12,MPI_COMM_WORLD,&status);
    for(int i=1;i<value;i++){
         z=z*i;
      }
    MPI_Send(&z,1,MPI_INT,0,12,MPI_COMM_WORLD);
   }   

   MPI_Finalize();
}
