//circularly linked lists
#include<stdio.h>
#include<stdlib.h>
#define null 0
typedef struct NODE {
	int data;
	struct NODE* link;
}node;
node *head=null,*NEW,*temp,*last=null;

void insertAtBegin(int x) {
	NEW=(node*)malloc(sizeof(node));
	NEW->data=x;
	NEW->link=head;
	head=NEW;
	
	if(head->link==null)
	last=head;
	
	last->link=head;

}
void insertAtNthPosition(int x,int n) {
	if(n==1)
		insertAtBegin(x);
	else {
		NEW=(node*)malloc(sizeof(node));
		NEW->data=x;
		int i;
		temp=head->link;
		for(i=2; i!=n-1&&temp->link!=head; i++) {
			temp=temp->link;
		}

		if(i!=n-1&&temp->link==head) {	//if n is greater than the size of list
			printf("\nERROR:Given position is greater than the size of the list\n");
		}
		else if(i==n-1&&temp->link==head){
		last->link=NEW;
		last=NEW;
		last->link=head;
			
		}
		else {
			
			NEW->link=temp->link;
			temp->link=NEW;
		}
	}
}
void insertAtEnd(int x) {
	if(head==null) {
		insertAtBegin(x);
	} else {
		NEW=(node*)malloc(sizeof(node));
		NEW->data=x;
		last->link=NEW;
		last=NEW;
		last->link=head;
	}
}
int deleteAtBegin() {
	int n;
	if(head==null) {
		printf("\nLIST IS EMPTY DELETION NOT POSSIBLE\n");
		return null;
	}
	else if(head->link==head){
		n=head->data;
		free(last);
		head=null;
		last=null;
		return n;
	} 
	else {
		n=head->data;
		temp=head;
		head=head->link;
		last->link=head;
		free(temp);
		return n;
	}
}

int deleteAtNthPosition(int n) {
	int l;
	if(n==1) {
		deleteAtBegin();
	} else if(head==null) {
		printf("\nLIST IS EMPTY DELETION NOT POSSIBLE\n");
		return null;
	} else {
		int i;
		temp=head;
		for(i=1; i!=n-1&&temp->link!=head; i++) {
			temp=temp->link;
		}
		
		if(i!=n-1&&temp->link==head) {	//if n is greater than the size of list
			printf("\nERROR:Given position is greater than the size of the list\n");
			return null;
		}
		else if(i==n-1&&temp->link==last)
		return deleteatend();
		
		 else {
			NEW=temp->link;
			l=NEW->data;
			temp->link=NEW->link;
			free(NEW);
			return l;
		}
	}
}


int deleteatend() {
	int n;
	if(head==null) {
		printf("\nLIST IS EMPTY DELETION NOT POSSIBLE\n");
		return null;
	} else if(head->link==head) {
		return deleteAtBegin();
	} else {
		for(temp=head;temp->link!=last;temp=temp->link){}
		temp->link=head;
		n=last->data;
		free(last);
		last=temp;
		return n;
	}
}

void display() {
	if(head==null)
		printf("\nLIST IS EMPTY\n");
	else {
			printf("%d --> ",head->data);
		for(temp=head->link; temp!=head;) {
			printf("%d --> ",temp->data);
			temp=temp->link;
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
				insertAtEnd(x);
				break;
			case 3:		//insert at nth position
				printf("\nEnter the element you want to insert and the position u want to insert it in:");
				scanf("%d%d",&x,&n);
				insertAtNthPosition(x,n);
				break;
			case 4:		//delete 1st
				x=deleteAtBegin();
				if(x!=null)
					printf("%d is removed from the list\n",x);
				break;
			case 5:		//delete last
				x=deleteatend();
				if(x!=null)
					printf("%d is removed from the list\n",x);
				break;
			case 6:		//delete at nth
				printf("\nEnter the position n :\n");
				scanf("%d",&n);
				x=deleteAtNthPosition(n);
				if(x!=null)
					printf("%d is removed from the list\n",x);
				break;
			case 7:		//display
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
