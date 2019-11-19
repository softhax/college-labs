#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#define size 3
int data[size];
sem_t full,empty,mutex;

void *producer(void* arg)
{
    int outVar;
    while(1)
    {
	sem_wait(&empty);
	sem_wait(&mutex);
    
	sem_getvalue(&full,&outVar);
	*(data+outVar)=random()%20;
	printf("Producer : %d\n",data[outVar]);
	sleep(1);

	sem_post(&mutex);
	sem_post(&full);
    }
    return NULL;
}


void *consumer(void *arg)
{
    int outVar;
    while(1)
    {
	sem_wait(&full);
	sem_wait(&mutex);
	
	sem_getvalue(&full,&outVar);
	printf("Consumer : %d\n",data[outVar]);
	sleep(1);
	sem_post(&mutex);
	sem_post(&empty);

    }


}
int main()
{
    pthread_t prod,cons;
    sem_init(&full,0,0);
    sem_init(&empty,0,size-1);
    sem_init(&mutex,0,1);
    pthread_create(&prod,NULL,producer,NULL);
    pthread_create(&cons,NULL,consumer,NULL);
    pthread_join(prod,NULL);
    pthread_join(cons,NULL);
    return 0;
}
