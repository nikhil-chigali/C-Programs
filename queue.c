#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define null 0
int q[5];
int f=-1,r=-1;

int isFull()
{
	if(r==4)
	return 1;
	else 
	return 0;
}
int isEmpty()
{
	if(r<f||(r==-1&&f==-1))
	return 1;
	else return 0;
}
void nq(int e)
{
	if(isFull())
	{
	printf("\nQUEUE OVERFLOW\n");
	}
	else if(isEmpty())
	{
		r=0;
		f=0;
		q[r]=e;
	}
 	else
	{
		r++;
		q[r]=e;
	}
	
}
int dq()
{
	if(isEmpty())
	{
	printf("\nQUEUE UNDERFLOW\n");
	return null;
	}
	
	else{
		return q[f++];
	}
}	
int main()
{
	int ch,x,i;
	while(1)
 	{
	printf("\n1.is full\n2.is empty\n3.enqueue\n4.dequeue\n5.display\n6.terminate\n");
	scanf("%d",&ch);
    switch(ch)
    {
    	case 1:
    		if(isFull())
    		{
    			printf("\nQUEUE IS FULL\n");
			}
    		else
    		{
    			printf("\nQUEUE IS NOT FULL\n");
			}
			break;
		case 2:
			if(isEmpty())
    		{
    			printf("\nQUEUE IS EMPTY\n");
			}
    		else
    		{
    			printf("\nQUEUE IS NOT EMPTY\n");
			}
			break;
		case 3:
			if(!isFull())
			{
			printf("\nenter the element u want to enqueue\n");
			scanf("%d",&x);
			nq(x);
			}
			else
			printf("\nQUEUE OVERFLOW\n");
			break;
		case 4:
			x=dq();
			if(!(x==null))
			printf("\n%d IS DEQUEUED FROM THE QUEUE\n",x);
			else
			printf("\nQUEUE UNDERFLOW\n");
			break;
		case 5:
			if(isEmpty())
			{
			printf("\nQUEUE IS EMPTY\n");
			}
			else {
				for(i=f;i<=r;i++)
				{
					printf(" %d | ",q[i]);
				}
			
			}break;
    	case 6:
		exit(0);
    	default:printf("\nINVALID CHOICE\n");
	}
	
	
	}
	
	return 0;
}




/*
19-51/1,Tejas Residency,flatno-SF01,Near KCP Siddhartha School,Kanuru,Vijayawada


*/
