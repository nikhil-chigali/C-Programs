// linked queue
#include<stdio.h>
#include<stdlib.h>
#define null 0

typedef struct NODE {
	int data;
	struct NODE* link;
}node;
node *head=null,*NEW,*last,*temp;
void enqueue(int x){
	NEW=(node*)malloc(sizeof(node));
	NEW->data=x;
	if(head==null){
		head=NEW;
		last=NEW;
		NEW->link=null;
	}
	else{
		last->link=NEW;
		last=NEW;
		NEW->link=null;
	}
	
}

int dequeue(){
		int n;
		if(head==null) {
		printf("\nQUEUE IS EMPTY DELETION NOT POSSIBLE\n");
		return null;
	}
	else if(head->link==null){
		n=head->data;
		free(head);
		head=null;
		last=null;
		return n;
		
	} 
	else {
		
		n=head->data;
		temp=head;
		head=head->link;
		free(temp);
		return n;
	}
}
void display() {
	if(head==null)
		printf("\nStack IS EMPTY\n");
	else {
		for(temp=head; temp!=null;) {
			printf("%d --",temp->data);
			temp=temp->link;
		}
	}

}
int main()
{
	int ch,x,i;
	while(1)
 	{
	printf("\n1.is empty\n2.enqueue\n3.dequeue\n4.display\n5.terminate\n");
	scanf("%d",&ch);
    switch(ch)
    {
 
		case 1:
			if(head==null)
    		{
    			printf("\nQUEUE IS EMPTY\n");
			}
    		else
    		{
    			printf("\nQUEUE IS NOT EMPTY\n");
			}
			break;
		case 2:
		
			printf("\nenter the element u want to enqueue\n");
			scanf("%d",&x);
			enqueue(x);
			
			break;
		case 3:
			x=dequeue();
			if(!(x==null))
			printf("\n%d IS DEQUEUED FROM THE QUEUE\n",x);
	
			break;
		case 4:
			display();
			break;
    	case 5:
		exit(0);
    	default:printf("\nINVALID CHOICE\n");
	}
	
	
	}
	
	return 0;
}


