#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>

int data=5;
int rc=0;
pthread_t thread1,thread2;
sem_t wrt,mutex;

void initialize()
{
    sem_init(&wrt,0,1);
    sem_init(&mutex,0,1);
}


void *reader()
{
    while(1)
    {
    sem_wait(&mutex);
    rc++;
    if(rc==1)
	sem_wait(&wrt);
    sem_post(&mutex);    
	printf("Element read is %d\n",data);
	sleep(1);
    sem_wait(&mutex);
    rc--;
    if(rc==0)
        sem_post(&wrt);
    sem_post(&mutex);
    }
}


void *writer()
{
    while(1)
    {
	sem_wait(&wrt);
	printf("Element written is %d\n",data);
	sleep(1);
	sem_post(&wrt);
    }
}

int main()
{
    initialize();
    pthread_create(&thread1,NULL,reader,NULL);
    pthread_create(&thread2,NULL,writer,NULL);
    pthread_join(thread2,NULL);
    pthread_join(thread1,NULL);
    return 0;
}
