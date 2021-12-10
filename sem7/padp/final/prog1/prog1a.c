#include<stdlib.h>
#include<omp.h>
#include<stdio.h>
#define SEED 3233414

int main(int argc,char *argv[]){
    for(int iter=1000;iter<=1000000;iter*=10){
        for(int nt=1;nt<=8;nt*=2){
            double x,y,r,pi;
            int count = 0;
            srand(SEED);
            double start_time = omp_get_wtime();
            #pragma omp parallel for private(x,y,r) num_threads(nt) reduction(+:count) 
            for(int i=0;i<iter;i++){
                x = (double)rand()/RAND_MAX;
                y = (double)rand()/RAND_MAX;
                r = x*x + y*y;
                if(r<=1)
                    count++;
            }
            pi = 4.0*count/iter;
            double end_time = omp_get_wtime();
            printf("\nNumber Of Iterations : %d\nNumber Of Threads :%d\nPI : %lf\nTime Taken : %lf\n\n",iter,nt,pi,end_time-start_time);
        }
    }

    return 0;
}
