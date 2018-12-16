#include <stdio.h>
#include <mpi.h>

int main(int argc,char *argv[])
{
	MPI_Init(&argc,&argv);
	int npes,myrank,final,myvalue,v,dest;
MPI_Status status;
	MPI_Comm_size(MPI_COMM_WORLD,&npes);
	MPI_Comm_rank(MPI_COMM_WORLD,&myrank);
	int value=10,count=0;

	if(myrank==0)
	{
	
	value=15;
	MPI_Send(&value,1,MPI_INT,1,10,MPI_COMM_WORLD);
	MPI_Recv(&final,1,MPI_INT,1,10,MPI_COMM_WORLD,&status);

	printf("Final value = %d \n",final);
	}
	else
	{
	MPI_Recv(&v,1,MPI_INT,myrank-1,10,MPI_COMM_WORLD,&status);
	myvalue=v-1;

	if(myrank==npes-1){
		dest=0;
	}
	else{
		dest=npes+1;
	}
	MPI_Send(&myvalue,1,MPI_INT,dest,10,MPI_COMM_WORLD);
	}
	MPI_Finalize();
}
