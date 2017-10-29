//Double hashing

#include<stdio.h>
#include<stdlib.h>
#define h_size 11
typedef unsigned int index;



int h_table[h_size];
index hash2(int key){
	int r = 7;
	return (r-(key%r))%h_size;
}
index hash1(int key){
	int ind;
	ind = key%h_size;
	if(h_table[ind]){
		return hash2(key);
	}
	else{
		return ind;
	}
}


void insert(int key){


		int i;
		i = hash1( key);
		h_table[i] = key;

	
}

void search(int key){
	int ind = hash1(key);
	if(h_table[ind] == key){
		printf("\nElement %d found at %d\n",key,ind);
	}
	else {
		printf("\nElement not found\n");
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
	
	printf("\nEnter 1 to insert a new element and 2 to search for a element\n 0 to terminate\n");
	scanf("%d",&ch);
	
	}	
	
	
	return 0;
}
