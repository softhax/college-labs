#include<stdlib.h>
#include<mpi.h>
#include<stdio.h>
#define SEED 3233414

int main(int argc,char *argv[]){
    double x,y,r,pi,start_time,end_time;
    int count = 0,iter=1000000,rank;
    int reduced_count,reduced_iter;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    if(rank == 0)
        start_time = MPI_Wtime();
    if(rank>0){
        srand(SEED);
        for(int i=0;i<iter;i++){
            x = (double)rand()/RAND_MAX;
            y = (double)rand()/RAND_MAX;
            r = x*x + y*y;
            if(r<=1)
                count++;
        }
    }
    MPI_Reduce(&count,&reduced_count,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
    MPI_Reduce(&iter,&reduced_iter,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
    reduced_iter = reduced_iter - iter;
    if(rank == 0){
        end_time = MPI_Wtime();
        pi = (double)reduced_count/(double)reduced_iter*4;
        printf("\nNumber Of Iterations : %d\nPI : %lf\nTime Taken : %lf\n\n",iter,pi,end_time-start_time);
    }
    

    MPI_Finalize();
    return 0;
}
