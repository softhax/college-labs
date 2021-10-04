#include<omp.h>
#include<stdio.h>

int main(int argc,char *argv[]){

#pragma omp parallel num_threads(16)

    printf("Hello World");

}
