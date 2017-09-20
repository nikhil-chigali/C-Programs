#include<stdio.h>
#include<stdlib.h>

int compare(const void* a,const void* b){
	int m=*((int*)a);
	int n=*((int*)b);
	return m-n;
}

int main(){
	int a[]={5,4,3,8,9,22,7,11,23,10};
	qsort(a,10,sizeof(int),compare);
	int i;
	for(i=0;i<10;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
