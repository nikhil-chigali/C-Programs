//doubly linked list
#include<stdio.h>
#include<stdlib.h>
#define null 0
typedef struct NODE{
	struct NODE* prev;
	int data;
	struct NODE* next;
}node;
node *head=null,*NEW,*temp,*last=null;
int r;
void insertAtBegin(int x){
	NEW=(node*)malloc(sizeof(node));
	NEW->data=x;
	NEW->next=head;
	NEW->prev=null;
	head=NEW;
	if(NEW->next==null){
		last=NEW;
	}
} 

void insertAtLast(int x){
	if(head==null){
		insertAtBegin(x);
	}
	else{
		NEW=(node*)malloc(sizeof(node));
		NEW->data=x;
		NEW->next=null;
		NEW->prev=last;
		last->next=NEW;
		last=NEW;
	}
}

int delAtBegin(){
	if(head==null){
		printf("\nLIST IS EMPTY : DELETION NOT POSSIBLE\n");
		return null;
	}
	else{
		r=head->data;
		temp=head;
		head=head->next;
		if(head!=null)
		head->prev=null;
		free(temp);
		if(head==null)
		last=null;
		return r;
	}
}

int delAtLast(){
	if(head==null){
		printf("\nLIST IS EMPTY : DELETION NOT POSSIBLE\n");
		return null;
	}
	else if(head->next==null){
	return delAtBegin();	
	}
	else{
		r=last->data;
		last=last->prev;
		free(last->next);
		last->next=null;
		return r;
	}
}

void display(){
	if(head==null){
		printf("\nLIST IS EMPTY\n");
	}
	else{
		for(temp=head;temp!=null;temp=temp->next){
			printf("%d | ",temp->data);
		}
	}
}

int delAtNthPosition(int n){
	if(head==null){
		printf("\nLIST IS EMPTY : DELETION NOT POSSIBLE\n");
		return null;
	}
	else{
		int pos;
		if(n==1)
		return delAtBegin();
		else{
			temp=head;
			for(pos=1;pos!=n&&temp->next!=null;pos++){
			temp=temp->next;
			}
			if(pos!=n&&temp->next==null){
				printf("\nINVALID POSITION : DELETION NOT POSSIBLE\n");
				return null;
			}
			else if(pos==n&&temp->next==null)
			return delAtLast();
			else{
				(temp->prev)->next=temp->next;
				(temp->next)->prev=temp->prev;
				r=temp->data;
				free(temp);
				return r;
			}
		}
	}
}

void insertAtNthPosition(int x,int n){
	int i;
	if(n==1){
		insertAtBegin(x);
	}
	else{
		temp=head;
		for(i=1;i!=n&&temp->next!=null;i++){
		temp=temp->next;
		}
		if(i==n-1&&temp->next==null){
			insertAtLast(x);
		}
		else if(i!=n&&temp->next==null){
			printf("\nINVALID POSITION : INSERTION NOT POSSIBLE\n");
		}
		else{
			NEW=(node*)malloc(sizeof(node));
			NEW->data=x;
			(temp->prev)->next=NEW;
			NEW->prev=temp->prev;
			temp->prev=NEW;
			NEW->next=temp;
		}
	}
}

int main() {
	int choice,x,n;
	while(1) {
		printf("\n1.insert an element at the beginning\n2.insert an element at the end\n3.insert an element at nth position\n4.delete the first element\n5.delete the last element\n6.delete the element at nth position\n7.Display the list\n8.terminate\n");
		scanf("%d",&choice);
		switch(choice) {
			case 1:		//insert at begin
				printf("\nEnter the element you want to insert:");
				scanf("%d",&x);
				insertAtBegin(x);
				break;
			case 2:		//insert at end
				printf("\nEnter the element you want to insert:");
				scanf("%d",&x);
				insertAtLast(x);
				break;
			case 3:		//insert at nth position
				printf("\nEnter the element you want to insert and the position u want to insert it in:");
				scanf("%d%d",&x,&n);
				insertAtNthPosition(x,n);
				break;
			case 4:		//delete 1st
				x=delAtBegin();
				if(x!=null)
					printf("%d is removed from the list\n",x);
				break;
			case 5:		//delete last
				x=delAtLast();
				if(x!=null)
					printf("%d is removed from the list\n",x);
				break;
			case 6:		//delete at nth
				printf("\nEnter the position n :\n");
				scanf("%d",&n);
				x=delAtNthPosition(n);
				if(x!=null)
					printf("%d is removed from the list\n",x);
				break;
			case 7:   //display
				display();
				break;
			case 8:		//terminate
				exit(0);
				break;
			default:
				printf("\nINVALID CHOICE\n");
		}

	}
	return 0;
}
