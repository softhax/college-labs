#include<omp.h>
#include<stdio.h>


int total = 0;
int main(int argc,char *agrv[]){

int arr[100];
for(int i=0;i<100;i++){
    arr[i] = i+1;
}
int i,tid;
#pragma omp parallel for num_threads(100) private(i) reduction(+:total)

for(i=0;i<100;i++){

    total += arr[i];
    tid = omp_get_thread_num();
    printf("Total : %d at thread %d\n",total,tid);
}

}
