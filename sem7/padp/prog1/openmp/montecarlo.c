#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#define SEED 35791246


void main(){
    int n=0,i,inside_count=0;
    double z,pi,x,y;

    printf("Enter the number of iterations used to estimate pi :");
    scanf("%d",&n);
    srand(SEED);

    double start_time = omp_get_wtime();

    //Change number of threads here
    int number_of_threads = 8;
    printf("\nNumber Of Threads : %d\n",number_of_threads);
    
    
    #pragma omp parallel for num_threads(number_of_threads) private(x,y,z,i)
    for(i=0;i<n;i++){
        x = (double)rand()/RAND_MAX;
        y = (double)rand()/RAND_MAX;
        z = x*x + y*y;
        
        // Comparing with 1 since we are considering radius = 1
        if(z<=1)
        #pragma omp atomic
            ++inside_count;
    }
    pi = (double)inside_count/n*1.0;
    pi = pi * 4;
    printf("# of trials = %d, estimate of pi is %g \n",n,pi);
    double end_time = omp_get_wtime();
    printf("Time elapsed for execution : %lf",end_time-start_time);
}