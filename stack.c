//stack
#include<stdio.h>
#include<stdlib.h>
int stack[5],top=-1;
int isFull()
{
	if(top==4)
	return 1;
	else return 0;
}
int isEmpty()
{
	if(top==-1)
	return 1;
	else 
	return 0;
}
void push(int e)
{
	if(!isFull())
	{
		stack[++top]=e;
		printf("\n%d is pushed into the stack\n",e);
	}
	else
	printf("\nSTACK OVERFLOW\n");
		
}
void pop()
{
	if(!isEmpty())
	{
		printf("\n%d is popped from the stack\n",stack[top--]);
	}
	else printf("\nSTACK UNDERFLOW\n");
}
int main()
{
	int choice,e;
	while(1)
	{
	printf("\n1.check if the stack is full\n2.check if the stack is empty\n3.push\n4.pop\n5.peep\n6.display the whole stack\n7.terminate the program\n");
	scanf("%d",&choice);
	
		switch(choice)
		{
			case 1://isFull
				if(isFull())
				{
					printf("\nstack is full\n");
				}
				else{
					printf("\nstack is not full\n");
				}break;
			case 2://isEmpty
				if(isEmpty())
				{
					printf("\n the stack is empty\n");
					}	
				else{
					printf("\n the stack is not empty\n");
				}	break;
			case 3://push
				printf("\nenter the element you want to push\n");
				scanf("%d",&e);
				push(e);
				break;
			case 4://pop
				pop();break;
			case 5://peep
			    if(top!=-1)
			    printf("\n%d\n",stack[top]);
			    else
			    printf("\nSTACK UNDERFLOW\n");
			    break;
			case 6://display the whole stack
			    if(top==-1)
			    printf("\nStack is empty\n");
			    else{
			    	for(e=top;e>=0;e--)
			    	{
			    		printf(" %d \n __ \n",stack[e]);
					}
				}break;
			case 7:
			exit(0);
			break;
			default:printf("\ninvalid choice\n");	
		}
	}
	return 0;
}
