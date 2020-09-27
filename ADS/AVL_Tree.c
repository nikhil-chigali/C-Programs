//AVL TREE
#include<stdio.h>
#include<stdlib.h>
#define null 0
#define MAX 100
typedef struct tree{
	int data;
	struct tree* left;
	struct tree* right;
}*node;

node root = NULL , New , temp;

#finding the height of the tree
int height(node x){
	if(x){
		int hl = height(x->left);
		int hr = height(x->right);
		return hl >= hr? hl+1:hr+1;
	}
	return 0;
}

int bf(node x){
	return height(x->left) - height(x->right);
}

node singleRotationLeft(node x){
	node t;
	t = x->right;
	x->right = t->left;
	t->left = x;
	return t;
}

node singleRotationRight(node x){
	node t;
	t = x->left;
	x->left = t->right;
	t->right = x;
	return t;
}

node insert(node temp, node root){
	if(!root)
		return temp;
	else{
		if(temp->data <= root->data){
			 root->left = insert(temp, root->left);
		}
		else{
			root->right = insert(temp, root->right);
		}
	}
	
	int x = bf(root);
	if(x >= 2 || x<=-2){ 					//Unbalanced node
		if(x <= -2 && bf(root->right) < 0){			
			if(x > 1 && temp->data <= root->left->data){		//Left-Left case
				return singleRotationRight(root);
			}
			else if(x < -1 && temp->data > root->right->data){	//Right-Right case
				return singleRotationLeft(root);
			}
			else if(x > 1 && temp->data > root->left->data){	//Left-Right case
				root->left = singleRotationLeft(root->left);
				return singleRotationRight(root);
			}
			else{												//Right-Left case
				root->right = singleRotationRight(root->right);
				return singleRotationLeft(root);
			}
		}
	}
	
	return root;
}
node find_min(node temp){
	if(temp){
	if(temp->left){
		return find_min(temp->left);
	}
	else{
		return temp;
	}
	}
}
#deleting node from the tree
node delete(node root, int x){
	if(!root){
		printf("Key not found!");
		return root;
	}
		if(x > root->data){
			root->right = delete(root->right, x);
		}
		else if(x < root->data){
			root->left = delete(root->left, x);
		}
		else{
			if(!root->left || !root->right){		//one or zero child
				node temp = root->left ? root->left : root->right;
				if(!temp){			//no child
					temp=root;
					root = null;
				}
				else{				//one child
					root->data = temp->data;
					root->left = temp->left;
					root->right = temp->right;	
				}
				free(temp);
			}
			else{					//two children
				node temp = find_min(root->right);
				root->data = temp->data;
				root->right = delete(root->right, root->data);
			}
		}
	
	
	if(!root)
	return root;
	int b = bf(root);
	
	if(b > 1 && bf(root->left) > 0){		//LL
		return singleRotationRight(root);
	}	
	else if(b < -1 && bf(root->right) < 0){	//RR
		return singleRotationLeft(root);
	}
	else if(b > 1 && bf(root->left) < 0){	//LR
		root->left = singleRotationLeft(root->left);
		return singleRotationRight(root);
	}
	else if(b < -1 && bf(root->right) > 0){	//RL
		root->right = singleRotationRight(root->right);
		return singleRotationLeft(root);
	}
	
	
	return root;
}

void inorder_traversal(node temp){
	if(temp){
	if(temp->left){
		inorder_traversal(temp->left);
	}
	printf("%d ",temp->data);
	if(temp->right){
		inorder_traversal(temp->right);
	}
	}
	else
	printf("\nTree is empty\n");
}


void postorder_traversal(node temp){
	
	if(temp){
	if(temp->left){
		postorder_traversal(temp->left);
	}
	if(temp->right){
		postorder_traversal(temp->right);
	}
	
	printf("%d ",temp->data);
	}
	else
	printf("\nTree is empty\n");
}

void preorder_traversal(node temp){
	if(temp){
	printf("%d ",temp->data);
	if(temp->left){
		preorder_traversal(temp->left);
	}
	if(temp->right){
		preorder_traversal(temp->right);
	}
	}
	else
	printf("\nTree is empty\n");
	
}

int main(){					//driver
	//inserting 10 15 20 25 30 40 50 90
	node z = (node)calloc(sizeof(node),1);
	z->data = 20;
	root = insert(z, root);

	z = (node)calloc(sizeof(node),1);
	z->data = 30;
	root = insert(z, root);

	z = (node)calloc(sizeof(node),1);
	z->data = 40;
	root = insert(z , root);

	z = (node)calloc(sizeof(node),1);
	z->data = 50;
	root = insert(z , root);

	z = (node)calloc(sizeof(node),1);
	z->data = 90;
	root = insert(z , root);

	z = (node)calloc(sizeof(node),1);
	z->data = 10;
	root = insert(z , root);

	z = (node)calloc(sizeof(node),1);
	z->data = 15;
	root = insert(z , root);

	z = (node)calloc(sizeof(node),1);
	z->data = 25;
	root = insert(z , root);

	//traversals
	printf("\nInOrder:	");
	inorder_traversal(root);
	printf("\nPreOrder:	");
	preorder_traversal(root);
	printf("\nPostOrder:	");
	postorder_traversal(root);
	
	printf("\ndeleting 25, 15, 50, 999\n");
	
	//deleting 25, 15, 50, 999
	root=delete(root, 15);
	root=delete(root, 25);
	root=delete(root, 50);
	root=delete(root, 999);
	//traversals
	printf("\nInOrder:	");
	inorder_traversal(root);
	printf("\nPreOrder:	");
	preorder_traversal(root);
	printf("\nPostOrder:	");
	postorder_traversal(root);
	
	return 0;
}
