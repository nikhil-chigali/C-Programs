//polynomial LL
#include<stdio.h>
#include<stdlib.h>
#define null 0
typedef struct node{
	int coeff;
	int exp;
	struct node* link;
}*polynomial;
polynomial NEW,temp,temp1,temp2,prod=null,track;


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
	temp1=poly1;
	temp2=poly2;
	while(temp1!=null || temp2!=null){
		if(temp1->exp > temp2->exp || (temp2==null)){
			NEW=(polynomial)malloc(sizeof(polynomial));
			NEW->coeff=temp1->coeff;
			NEW->exp=temp1->exp;
			NEW->link=null;
			if(sum==null){
				sum=NEW;
				temp=NEW;
			}
			else{
				temp->link=NEW;
				temp=NEW;
			}
			temp1=temp1->link;
		}
		else if(temp2->exp > temp1->exp || (temp1==null)){
			NEW=(polynomial)malloc(sizeof(polynomial));
			NEW->coeff=temp2->coeff;
			NEW->exp=temp2->exp;
			NEW->link=null;
			if(sum==null){
				sum=NEW;
				temp=NEW;
			}
			else{
				temp->link=NEW;
				temp=NEW;
			}
			temp2=temp2->link;
		}
		else{
			NEW=(polynomial)malloc(sizeof(polynomial));
			NEW->coeff=temp1->coeff+temp2->coeff;
			NEW->exp=temp2->exp;
			NEW->link=null;
			if(sum==null){
				sum=NEW;
				temp=NEW;
			}
			else{
				temp->link=NEW;
				temp=NEW;
			}
			temp1=temp1->link;
			temp2=temp2->link;
		}
	}
	display(poly1);
	printf(" + ");
	display(poly2);
	printf("\n");
	display(sum);
		
}

void traverse ( polynomial traverse  ){
	track = prod;
	if ( track==null )
	{
		prod = traverse;
		return ;
	}
	else{
		
		while ( track->link != null ){
			
			if( track->exp == traverse->exp ){
				
				track->coeff += traverse->coeff;
				free(traverse);
				return ;
				
			}
			
			track = track->link;
			
		}
		
		if ( track->link == null && track->exp == traverse->exp ){
				
				track->coeff += traverse->coeff;
				free(traverse);
				return ;
				
			}
		else {
			
			track->link = traverse;
			return;
			}
	
	
}

}
void multiply( polynomial poly1 , polynomial poly2 ){
//	polynomial prod=null;
	temp1=poly1;
	while( temp1 !=null ){
		temp2=poly2;
		while( temp2 !=null ){
			
			NEW = (polynomial)malloc (sizeof(polynomial));
			NEW->coeff = temp1->coeff * temp2->coeff;
			NEW->exp = temp1->exp + temp2->exp;
			NEW->link = null;
			traverse (NEW );
			temp2 = temp2->link;
		}
		temp1=temp1->link;
	}
	display(prod);
}


void diff(polynomial poly){
	temp1=poly;
	while(temp1 != null){
		if(temp1->exp == 0){
			return ;
		}
		else{
		printf("(%d)x%d",(temp1->coeff)*(temp1->exp) , (temp1->exp - 1));
		if(temp1->link!=null)
		printf("+");
		
		temp1 = temp1->link;
	    }
	}
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
    printf("\n\nproduct of 1st n 2nd polynomials is\n\n");
	multiply(poly1,poly2);
	printf("\n");
	
	printf("\ndifferentiation of the 1st polynomial is;\n\n");
	diff(poly1);
	printf("\ndifferentiation of the 2nd polynomial is;\n\n");
	diff(poly2);
	
	
	return 0;	
}
