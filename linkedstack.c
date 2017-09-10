//linked stack
#include<stdio.h>
#include<stdlib.h>
#define null 0

typedef struct NODE {
	int data;
	struct NODE* link;
}node;
node *head=null,*NEW,*temp;
void push(int x) {
	NEW=(node*)malloc(sizeof(node));
	NEW->data=x;
	NEW->link=head;
	head=NEW;

}

int pop() {
	if(head==null) {
		printf("\nStack IS EMPTY DELETION NOT POSSIBLE\n");
		return null;
	} else {
		int n;
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
			printf("%d \n--\n",temp->data);
			temp=temp->link;
		}
	}

}

int main(){
	int ch,n;
	printf("\n1.is empty\n2.push\n3.pop\n4.display\n5.terminate");
	while(1){
	printf("\nenter choice\n");
	scanf("%d",&ch);
	switch(ch){
		case 1:		//is empty
			if(head==null)
			printf("\nThe stack is empty\n");
			else
			printf("\nThe stack is not empty\n");
			break;
		case 2:		//push
			printf("\nenter an element to push\n");	scanf("%d",&n);
			push(n);
			break;
		case 3:		//pop
			n=pop();
			if(n!=null){
				printf("\npopped element=%d\n",n);
			}
			break;
		case 4:		//display
		printf("\n");
		display();
		printf("\n");
		
			break;
		case 5:		//terminate
			exit(0);
			break;
		default:printf("\ninvalid choice\n");	
	}
	}
	return 0;
}
