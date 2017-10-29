//String Hashing method 2 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define h_size 10007   /*Some random large prime number*/

typedef unsigned int index;

char h_table[h_size][100];

index hash(char *key){
unsigned int hash_val = 0, i = 0, n = strlen(key);
 while( *key != '\0' ){
 hash_val = ( (hash_val/n-1-i) << 5 ) + *key++;
 i++;
 }
 return( hash_val % h_size );
}


int main(){
	
	int ind,ch;
	char temp[100];
	printf("\nEnter 1 to insert a new string and 2 to search for a string\n-1 to terminate\n");
	scanf("%d",&ch);
	while(ch){

	if(ch==1){
		printf("Enter string\n");
		scanf("%s",temp);
		ind = hash(temp);
		strcpy(h_table[ind],temp);
	}
	else{
		printf("Enter string\n");
		scanf("%s",temp);
		ind = hash(temp);
		if(!strcmp( h_table[ind] , temp ))
		printf("\n The string \"%s\" found at index %d\n",temp,ind);
		else
		printf("\n The string \"%s\" not found",temp);
	}
	
	printf("\nEnter 1 to insert a new string and 2 to search for a string\n 0 to terminate\n");
	scanf("%d",&ch);
	
	}
	return 0;
}
