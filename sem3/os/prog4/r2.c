#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<semaphore.h>

char buff[20];

void *reader()
{
    while(1)
    {
	sem_wait(&mutex);
	rc++;
	if(rc==1)
	    sem_wait(&db);
	sem_post(&mutex);


	sem_wait(&mutex);
	rc--;
	if(rc==0)
	    sem_post(&db);
	sem_post(&mutex);



    }
}

void *writer()
{
    while(1)
    {
	sem_wait(&db);	
	printf("Element written is %d\n",buff[i]);
	sleep(1);
	sem_post(&db);
    }
    pthread_exit(0);

}

int main()
{
    sem_t db,mutex;
    pthread_t thread1,thread2;
    sem_init(&db,0,1);
    sem_init(&mutex,0,1);
    pthread_create(&thread1,NULL,reader,NULL);
    pthread_crate(&thread2,NULL,writer,NULL);
    pthread_join(thread2,NULL);
    pthrad_join(thread1,NULL):
    return 0;
}
