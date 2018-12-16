#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

double randomnum()
{
    double range = 1;
    double div = RAND_MAX / range;
    return 0 + (rand() / div);
}
 

int inout(double x,double y)
{
    double sum=(x*x)+(y*y);
    if(sum>1){
    return 0;
     }
    else{
    return 1;
    }   
}

void main(int argc,char* argv[])
{
   
    MPI_Init(&argc,&argv);
    double start=MPI_Wtime();
    double x,y;
    int n=0;
    int insideout;
    int num=100000;
    int circles=0;
    int squares=0;
     while(n<num){
            x=randomnum();
            y=randomnum();
            insideout=inout(x,y);
            if(insideout==1){
            circles=circles+1;
            }
           
            squares=squares+1;
           
            n=n+1;
        }
     double pi=(circles/(double)squares)*4;
     printf("PI : %f \n",pi);
    double end=MPI_Wtime();
    printf("Time using one processor : %lf \n",end-start);
    MPI_Finalize();
}
