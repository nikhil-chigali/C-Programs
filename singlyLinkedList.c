//linked lists
#include<stdio.h>
#include<stdlib.h>
#define null 0
struct node {
	int data;
	struct node* link;
}*head=null,*NEW,*temp,*temp2;

void insertAtBegin(int x) {
	NEW=(struct node*)malloc(sizeof(struct node));
	NEW->data=x;
	NEW->link=head;
	head=NEW;

}
void insertAtNthPosition(int x,int n) {
	if(n==1)
		insertAtBegin(x);
	else {
	
		int i;
		temp=head;
		for(i=1; i!=n-1&&temp->link!=null; i++) {
			temp=temp->link;
		}

		if(i!=n-1&&temp->link==null) {	//if n is greater than the size of list
			printf("\nERROR:Given position is greater than the size of the list\n");
		}

		else {
				NEW=(struct node*)malloc(sizeof(struct node));
		NEW->data=x;
			NEW->link=temp->link;
			temp->link=NEW;
		}
	}
}
void insertAtEnd(int x) {
	if(head==null) {
		insertAtBegin(x);
	} else {
		NEW=(struct node*)malloc(sizeof(struct node));
		NEW->data=x;
		temp=head;
		while(temp->link!=null) {
			temp=temp->link;
		}
		NEW->link=temp->link;
		temp->link=NEW;
	}
}
int deleteAtBegin() {
	if(head==null) {
		printf("\nLIST IS EMPTY DELETION NOT POSSIBLE\n");
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

int deleteAtNthPosition(int n) {
	int l;
	if(n==1) {
		return deleteAtBegin();
	} else if(head==null) {
		printf("\nLIST IS EMPTY DELETION NOT POSSIBLE\n");
		return null;
	} else {
		int i;
		temp=head;
		for(i=1; i!=n-1&&temp->link!=null; i++) {
			temp=temp->link;
		}
		if(i!=n-1&&temp->link==null) {	//if n is greater than the size of list
			printf("\nERROR:Given position is greater than the size of the list\n");
			return null;
		} else if(temp->link==null&&i==n-1) {
			l=(temp->link)->data;
			free(temp->link);
			return l;
		} else {
			l=(temp->link)->data;
			temp2=temp->link;
			temp->link=(temp->link)->link;
			free(temp2);
			return l;
		}
	}
}


int deleteatend() {
	int n;
	if(head==null) {
		printf("\nLIST IS EMPTY DELETION NOT POSSIBLE\n");
		return null;
	} else if(head->link==null) {
		n=deleteAtBegin();
		return n;
	} else {
		temp=head;

		while((temp->link)->link!=null) {

			temp=temp->link;
		}
		n=(temp->link)->data;
		free(temp->link);
		temp->link=null;
		return n;
	}
}

void display() {
	if(head==null)
		printf("\nLIST IS EMPTY\n");
	else {
		for(temp=head; temp!=null;) {
			printf("%d --> ",temp->data);
			temp=temp->link;
		}
	}

}
void reverse(){
	if(head==null){
		printf("\nLIST IS EMPTY\n");
	}
	else{
	struct node *curr,*prev=null,*nex;
	curr=head;
	nex=curr->link;
	while(nex!=null){
		curr->link=prev;
		prev=curr;
		curr=nex;
		nex=curr->link;
	}
	curr->link=prev;
	
	head=curr;
	printf("\nreversed list:\n");
	display();
	}
}



int main() {
	int choice,x,n;
	while(1) {
		printf("\n1.insert an element at the beginning\n2.insert an element at the end\n3.insert an element at nth position\n4.delete the first element\n5.delete the last element\n6.delete the element at nth position\n7.reverse\n8.Display the list\n9.terminate\n");
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
			case 7:   //reverse
				reverse();
				break;
			case 8:		//display
				display();
				break;
				
			case 9:		//terminate
				exit(0);
				break;
			default:
				printf("\nINVALID CHOICE\n");
		}

	}
	return 0;
}
