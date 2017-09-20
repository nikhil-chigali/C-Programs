//linkedlist ordered insertion
#include<stdio.h>
#include<stdlib.h>
#define null 0
struct node{
	int data;
	struct node* link;
}*head=null,*NEW,*temp,*temp2;

void insert(int x){
	NEW=(struct node*)malloc(sizeof(struct node));
	NEW->data=x;
	if(head==null){
		head=NEW;
		NEW->link=null;
	}
	else{
		temp=head;
		temp2=null;
		while(temp->data<=x&&temp->link!=null){
			temp2=temp;
			temp=temp->link;
		}
		if(temp2==null&&temp->data>x){
			NEW->link=temp;
			head=NEW;
		}
		else if(temp->link==null&&temp->data<=x){
			NEW->link=temp->link;
			temp->link=NEW;
		}
		else {
			temp2->link=NEW;
			NEW->link=temp;
		}
		
	}
	
}
void display(){
	for(temp=head;temp!=null;){
		printf("%d --> ",temp->data);
	temp=temp->link;
	}
	
}

int main(){
	int choice,x;
	while(1){
		printf("\nEnter 1 to insert an element,2 to display and exit\n");
		scanf("%d",&choice);
		if(choice==1){
			printf("\nEnter element you eant to insert\t\a");
			scanf("%d",&x);
			insert (x);
			
		}
		else if(choice==2){
			display();
			exit(0);
		}
		else{
			printf("\nINVALID choice\n");
		}
	}
	getch();
	return 0;
}
