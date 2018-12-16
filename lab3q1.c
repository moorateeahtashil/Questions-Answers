#include <stdio.h>
#include <mpi.h>

int main(int argc,char *argv[])
{

	int npe,rank,value,sum;
	int v1,v2,v3;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&npe);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);

	if(rank==1)
	{
		value=5+rank;
		MPI_Send(&value,1,MPI_INT,0,10,MPI_COMM_WORLD);
	}	

	if(rank==2)
	{
		value=rank*rank;
		MPI_Send(&value,1,MPI_INT,0,11,MPI_COMM_WORLD);
	}

	if(rank==3)
	{
		value=rank*4;
		MPI_Send(&value,1,MPI_INT,0,12,MPI_COMM_WORLD);
	}

	if(rank==0)
	{
		MPI_Status status;
		MPI_Recv(&v1,1,MPI_INT,1,10,MPI_COMM_WORLD,&status);
		MPI_Recv(&v2,1,MPI_INT,2,11,MPI_COMM_WORLD,&status);
		MPI_Recv(&v3,1,MPI_INT,3,12,MPI_COMM_WORLD,&status);

		sum=v1+v2+v3;
		printf("Sum = %d", sum);	
	}

	MPI_Finalize();
}
