//polynomial LL
#include<stdio.h>
#include<stdlib.h>
#define null 0
typedef struct node{
	int coeff;
	int exp;
	struct node* link;
}*polynomial;
polynomial NEW,temp;
polynomial create(polynomial poly){
	int coeff,exp;
	scanf("%d %d",&coeff,&exp);
	while(coeff!=0||exp!=0){
		NEW=(polynomial)malloc(sizeof(polynomial));
		NEW->coeff=coeff;
		NEW->exp=exp;
		NEW->link=null;
		if(poly==null){
			poly=NEW;
			temp=NEW;
		}
		else{
			temp->link=NEW;
			temp=NEW;
		}
		scanf("%d %d",&coeff,&exp);
	}
	return poly;
}
void display(polynomial poly){
	for(temp=poly;temp!=null;temp=temp->link){
		printf("(%d)x%d",temp->coeff,temp->exp);
		if(temp->link!=null)
		printf("+");
	}
	
}

void add( polynomial poly1, polynomial poly2){
	polynomial sum=null;
	while(poly1!=null || poly2!=null){
		if(poly1->exp > poly2->exp || (poly2==null)){
			NEW=(polynomial)malloc(sizeof(polynomial));
			NEW->coeff=poly1->coeff;
			NEW->exp=poly1->exp;
			NEW->link=null;
			if(sum==null){
				sum=NEW;
				temp=NEW;
			}
			else{
				temp->link=NEW;
				temp=NEW;
			}
			poly1=poly1->link;
		}
		else if(poly2->exp > poly1->exp || (poly1==null)){
			NEW=(polynomial)malloc(sizeof(polynomial));
			NEW->coeff=poly2->coeff;
			NEW->exp=poly2->exp;
			NEW->link=null;
			if(sum==null){
				sum=NEW;
				temp=NEW;
			}
			else{
				temp->link=NEW;
				temp=NEW;
			}
			poly2=poly2->link;
		}
		else{
			NEW=(polynomial)malloc(sizeof(polynomial));
			NEW->coeff=poly1->coeff+poly2->coeff;
			NEW->exp=poly2->exp;
			NEW->link=null;
			if(sum==null){
				sum=NEW;
				temp=NEW;
			}
			else{
				temp->link=NEW;
				temp=NEW;
			}
			poly1=poly1->link;
			poly2=poly2->link;
		}
	}
	display(sum);
		
}

int main(){
	printf("\nenter 0 0 once u r done with creating ur polynomial\n");
	polynomial poly1=null;
	printf("enter the first polynomial\n");
	poly1=create(poly1);
	display(poly1);
    polynomial poly2=null;
	printf("\nenter the second polynomial\n");
	poly2=create(poly2);
	display(poly2);
	printf("\nsum of 1st n 2nd polynomials is\n");
	add(poly1,poly2);
    return 0;	
}
