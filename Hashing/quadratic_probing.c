//quadratic probing
#include<stdio.h>
#include<stdlib.h>
#define h_size 11
typedef unsigned int index;
float lambda = 0;
index ele_count = 0;
int h_table[h_size];


index hash(int key ){
	int i;
	int h1 = key%h_size;
	for(i = 1;h_table[h1];i++){
		h1 = (key+i*i)%h_size;
	}
	return h1;
}

void insert(int key){

	if(lambda == 1){
		printf("\nHASH TABLE is full.No further insertions can be made\n");
		return;
	}
	else{
		int i;
		i = hash( key);
		h_table[i] = key;
	ele_count++;
	lambda = ele_count/h_size;
	}
	
}

void search(int key){
	int i;
	int h1 = key%h_size;
	for(i = 1;1;i++){
		
		 if(h_table[h1] == key){
			printf("\nElement %d found at %d\n",key,h1);
			return;
		}
		else if(h_table[h1] == 0 || i > h_size){
			printf("\nElement not found\n");
			return;
		}
		h1 = (key+i*i)%h_size;
	}
}

int main(){
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
