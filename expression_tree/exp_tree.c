//expression tree
#include<stdio.h>
#include<stdlib.h>
#include"inf_pst.h"
#define MAX 50
#define null 0
/*
  
  NOTE: dont forget to paste the header file inf_pst.h in the same location(folder) as this code

*/
typedef struct tree_node{
	struct tree_node* lc;
	char data;
	struct tree_node* rc;
}*node;
node temp,neww;

node stack[MAX];
int top=-1;

void push(node temp){
	stack[++top] = temp;
}

node pop(){
	return stack[top--];
}



void create(char x){
	neww = (node)calloc(sizeof(node) , 1);
	neww->data = x;
	if(isdigit(x)){
		push(neww);
	}
	else{
		neww->rc = pop();
		neww->lc = pop();
		push(neww);
	}
		
}

void inorder_traversal(node temp){
	
	if(temp->lc){
		inorder_traversal(temp->lc);
	}
	printf("%c",temp->data);
	if(temp->rc){
		inorder_traversal(temp->rc);
	}
	
}

void postorder_traversal(node temp){

	if(temp->lc){
		postorder_traversal(temp->lc);
	}
	if(temp->rc){
		postorder_traversal(temp->rc);
	}
	
	printf("%c",temp->data);

}

void preorder_traversal(node temp){
	
	printf("%c",temp->data);
	if(temp->lc){
		preorder_traversal(temp->lc);
	}
	if(temp->rc){
		preorder_traversal(temp->rc);
	}
	
}

int main(){
	
	int i=0;
	char inf[MAX],pst[MAX];
	
	printf("\nEnter the infix expression:\n");
	scanf("%s",inf);
	
	convert(inf,pst);
	
	printf("\nAfter coverting to postfix: %s" , pst);
	
	while(pst[i]!='\0'){
		create(pst[i]);
		i++;
	}
	printf("\nInorder traversal:\t");
	inorder_traversal(stack[top]);
	printf("\nPostorder traversal:\t");
	postorder_traversal(stack[top]);
	printf("\nPreorder traversal:\t");
	preorder_traversal(stack[top]);
		
	return 0;
}
