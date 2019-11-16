#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 5

struct queue{
    char msgq[MAX][100];
    int front;
    int rear;
};

void enqueue(struct  queue *q,char *msg)
{
    if(q->rear == MAX-1)
	printf("\n\n ------- MESSAGE QUEUE IS FULL !!! -----------\n\n");
    else
    {
	if(q->rear==-1)
	    q->rear=q->front=0;
	else
	    q->rear++;
	strcpy(q->msgq[q->rear],msg);
    }
}

void dequeue(struct queue *q)
{
    if(q->rear == -1)
	printf("\n\n ------- MESSAGE QUEUE IS EMPTY !!! -----------\n\n");
    else
    {
	printf("\nThe deleted message is : %s",q->msgq[q->front]);
	if(q->front==q->rear)
	    q->front=q->rear=-1;
	else
	    q->front++;
    }
}


void display(struct queue q)
{
    int i;
    if(q.rear==-1)
	printf("\n\n ------- MESSAGE QUEUE IS EMPTY !!! ----------\n\n");
    else
	for(i=q.front;i<=q.rear;i++)
	    printf("%s\n",q.msgq[i]);
}

void main()
{
    int ch;
    char msg[100];
    struct queue q;
    q.rear=-1;
    q.front=-1;

    while(1)
    {
//	system("clear");
//	fflush(stdin);
	printf("\n\nEnter your choice :\n");
	printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
	scanf("%d",&ch);
	fflush(stdin);
	switch(ch)
	{   
	    case 1:
		printf("Enter the message to enqueue :\n");		
		scanf(" %s",msg);
		enqueue(&q,msg);
		break;
	    case 2:
		dequeue(&q);
		break;
	    case 3:
		display(q);
		break;
	    case 4:
		exit(0);
	
	}

    }
}
