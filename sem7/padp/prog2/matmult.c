#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

int main(){

    int m1,n1;
    int m2,n2;
    int **matA,**matB,**res;
    
    // For Manual Input
    // printf("Enter rows and columns for matrix 1:\n");
    // scanf("%d %d",&m1,&n1);
    
    // printf("Enter rows and columns for matrix 2:\n");
    // scanf("%d %d",&m2,&n2);

    m1 = 1000;
    n1 = 1000;
    m2 = 1000;
    n2 = 1000;    
    
    
    
    if(n1!=m2){
        printf("\nCannot multiply!!!!!");
        exit(0);
    }
    

    // printf("Enter elements of first matrix\n");
    // Input Matrix A
    matA = (int**)malloc(sizeof(int)*m1);
    for(int i=0;i<m1;i++){
        matA[i] = (int *)malloc(sizeof(int)*n1);
        for(int j=0;j<n1;j++){
            
            // Manual Input
            // int x;
            // scanf("%d",&x);

            matA[i][j] = i+j;
        }
    }

    // Display Matrix A
    // printf("Matrix A is : \n");
    // for(int i=0;i<m1;i++){
    //     for(int j=0;j<n1;j++){
    //         printf("%d ",matA[i][j]);
    //     }
    //     printf("\n");
    // }

   
    // printf("Enter elements of second matrix\n");
    // Input Matrix B
    matB = (int**)malloc(sizeof(int)*m2);
    for(int i=0;i<m2;i++){
        matB[i] = (int *)malloc(sizeof(int)*n2);
        for(int j=0;j<n2;j++){
            // Manual Input
            // int x;
            // scanf("%d",&x);

            matB[i][j] = i+j;
        }
    }

    // Display Matrix B
    // printf("Matrix B is : \n");
    // for(int i=0;i<m2;i++){
    //     for(int j=0;j<n2;j++){
    //         printf("%d ",matB[i][j]);
    //     }
    //     printf("\n");
    // }

    res = (int**)malloc(sizeof(int)*m1);
    //Multiply
    double start_time = omp_get_wtime();
    
    // Parallelize
    int i=0,j=0,k=0;
    omp_set_num_threads(8);
    #pragma omp parallel for private(i,j,k)
    for(i=0;i<m1;i++){
        res[i] = (int*)malloc(sizeof(int)*n2);
        for(j=0;j<n2;j++){
            res[i][j] = 0;        
            for(k=0;k<m2;k++){
                res[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }

    double end_time = omp_get_wtime();
    printf("Time elapsed for execution : %lf",end_time-start_time);
    // Display Result Matrix
    // printf("\nResult:\n");
    // for(int i=0;i<m1;i++){
    //     for(int j=0;j<n2;j++){
    //         printf("%d ",res[i][j]);
    //     }
    //     printf("\n");
    // }

    return 0;

}

