//Open hashing(seperate chaining)
#include<stdio.h>
#include<stdlib.h>
#define h_size 11   /*Some random prime number*/
#define null 0
typedef unsigned int index;



typedef struct node{
	int data;
	struct node* link;
}*h_node;

h_node neww ,h_table[h_size];

index hash(int key){
	return key % h_size;
}

void insert(int value){
	index ind = hash(value);
	neww = (h_node)calloc(sizeof(h_node),1);
	neww->data = value;	
	if(!h_table[ind]){
	h_table[ind] = neww; 
	}
	else{
		h_node temp;
		temp = h_table[ind];
		while(temp->link!=null){
			temp = temp->link;
		}
		temp->link = neww;
	}
}

void search(int value){
	index ind = hash(value);

		h_node temp;
		temp = h_table[ind];
		while(temp){
			if(temp->data == value){
				printf("\nElement %d found at %d\n",value,ind);
				return;
			}
			temp = temp->link;
		}
		printf("\nElement %d not found\n",value);
	
}

int main(){
	int i;
	for(i = 0;i<h_size;i++){
		h_table[i] = null;
	}
	
	int ch;
	int temp;
	printf("\nEnter 1 to insert a new element and 2 to search for an element\n-1 to terminate\n");
	scanf("%d",&ch);
	while(ch){

	if(ch==1){
		printf("Enter element\n");
		scanf("%d",&temp);
		insert(temp);
	}
	else{
		printf("Enter element\n");
		scanf("%d",&temp);
		search(temp);
	}
	
	printf("\nEnter 1 to insert a new element and 2 to search for a string\n 0 to terminate\n");
	scanf("%d",&ch);
	
	}
	return 0;
}
