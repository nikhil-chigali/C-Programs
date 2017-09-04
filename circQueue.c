//circular queue
#include<stdio.h>
#include<stdlib.h>

int q[5];
int rear=-1,front=-1;
	int i;
	
int isempty()
{
	if((rear==-1&&front==-1))
	return 1;
	else
	return 0;
}
int isfull()
{
	if(front==(rear+1)%5 )
	return 1;
	else 
	return 0;
}
void deq()
{
	
	if(isempty())
	{
	printf("\nQUEUE UNDERFLOW\n");	
	}
	else if(front==rear)
	{
		printf("\nDequeued element = %d\n",q[front]);
		front=-1;
		rear=-1;
	}
	else
	{	
	printf("\nDequeued element = %d\n",q[front]);
	front=(front+1)%5;
	}
}

void enq(int e)
{

	if(front==-1&&rear==-1)
	{
		front=0;
		rear=0;
		q[rear]=e;
	}
	else{
		rear=(rear+1)%5;
		q[rear]=e;
	}
	
	}


int main()
{
	int choice,x;
	while(1)
	{
	printf("\n1.is full\n2.is empty\n3.enqueue\n4.dequeue\n5.display\n6.terminate\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: //is full
			if(isfull())
			{
				printf("\nQUEUE is full\n");
			}
			else
			{
				printf("\nQUEUE is not full\n");
			}
			break;
		case 2: //is empty
			if(isempty())
				printf("\nQUEUE is empty\n");
			else
				printf("\nQUEUE is not empty\n");
			break;
		case 3: //enqueue
			if(!isfull())		
			{
				printf("\nEnter the element to be enqueued\t");
				scanf("%d",&x);
				enq(x);	
			}
			else{
			printf("\nQUEUE OVERFLOW\n");
			}
		break;	
		case 4: //dequeue
			deq();
		break;
		case 5: //display
		if(isempty())
		{
		printf("\nQUEUE UNDERFLOW\n");
		}
		else if(isfull()){
			printf(" %d | ",q[front]);
		for(i=(front+1)%5;i!=front;i=(i+1)%5)
			{
			printf(" %d | ",q[i]);
			}
			
		}
		else
		{
			for(i=front;i!=(rear+1)%5;i=(i+1)%5)
			{
			printf(" %d | ",q[i]);
			}
			
		}
		break;
		case 6: //terminate
		exit(0);
		
		default:printf("\nInvalid choice!!! Enter valid choice\n");	
	
	}
	
	}
return 0;
}
