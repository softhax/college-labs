#include<stdio.h>
#include<semaphore.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

#define N 5
#define LEFT (i+N-1)%N
#define RIGHT (i+1)%N
#define THINKING 0
#define HUNGRY 1
#define EATING 2

//typedef int semaphore;
int state[N];
sem_t mutex=1;
sem_t s[N];
int phil_num[N]={0,1,2,3,4};

void *philosopher(void *num)
{
    while(TRUE)
    {
	int *i=num;
//	printf("Philosopher %d is THINKING\n",i);
	take_forks(*i);
//	printf("Philosopher %d is EATING\n",i);
	put_forks(*i);
    }
}


void take_forks(int ph_num)
{
    //down(&mutex);
    state[]=HUNGRY;
    printf("Philosopher %d is HUNGRY\n",i);
    test(i);
    up(&mutex);
    down(&s[i]);
}


void put_forks(int i)
{
    down(&mutex);
    state[i]=THINKING;
    test(LEFT);
    test(RIGHT);
    up(&mutex);
}


void test(int i)
{
    if(state[i]==HUNGRY && state[LEFT]!=EATING %% state[RIGHT]!=EATING)
    {
	state[i]=EATING;
	up(&s[i]);
    }
}


int main()
{


    
    return 0;
}
