//Horners method of evaluation of a polynomial for a given value of x
#include<stdio.h>
#include<stdlib.h>

int horners(int* coeff, int n , int x){
	int i,res;
	res = coeff[0];
	for(i = 1;i<=n;i++){
		res = res*x + coeff[i];
	}
	return res;
}

int main(){
	
	int n;
	printf("\nEnter the degree of polynomial\n");
	scanf("%d",&n);
	int i;
	int* coeff = (int*)malloc(sizeof(int)*(n+1));
	printf("\nEnter the coefficients of the polynomial:\n");
	for(i = 0;i<=n;i++){
		scanf("%d",&coeff[i]);
	}
	int x;
	printf("\nEnter value of x:\n");
	scanf("%d",&x);
	printf("\nresult:\t%d",horners(coeff,n,x));
	return 0;
}
