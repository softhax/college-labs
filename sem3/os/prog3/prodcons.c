#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

#define SIZE 3
#define TIMES 5

sem_t full,empty,mutex;
int data[SIZE];

void* producer(void* arg)
{
    int outVar;
    for(;;)
    {
	sem_wait(&empty);
	sem_wait(&mutex);

	sem_getvalue(&full,&outVar);
	*(data+outVar)=random()%20;
	printf("Producer: %d\n",data[outVar]);
	sleep(1);


	sem_post(&mutex);
	sem_post(&full);
    }

    return NULL;
}


void* consumer(void* arg)
{
    int outVar;
    for(;;)
    {
	sem_wait(&full);
	sem_wait(&mutex);

	sem_getvalue(&full,&outVar);
	printf("Consumer: %d\n",data[outVar]);
	sleep(1);

	sem_post(&mutex);
	sem_post(&empty);
    }

    return NULL;
}


int main()
{
    pthread_t producer_t,consumer_t;
    sem_init(&full,0,0);
    sem_init(&empty,0,SIZE-1);
    sem_init(&mutex,0,1);
    pthread_create(&producer_t,NULL,producer,NULL);
    pthread_create(&consumer_t,NULL,consumer,NULL);
    pthread_join(producer_t,NULL);
    pthread_join(consumer_t,NULL);
    return 0;
}
