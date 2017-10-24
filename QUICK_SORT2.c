//Quick sort
#include<stdio.h>
#include<stdlib.h>
/*

	best and average case = O(NlogN)
	worst case = O(N*N) 

*/


void swap(int* x , int* y){
	int t;
	t=*x;
	*x=*y;
	*y=t;
}
void quick_sort(int* a, int lb , int ub ){
	if(lb >= ub){		//base condition
		return;			
	}
	else{
		int i,j,pi,pivot;
		i = lb;
		j = ub;
		pi = lb;
		pivot = a[pi];
		while(i<j){
			while(pivot>=a[i]){
			i++;
			}
			while(pivot<a[j]){
			j--;
			}
			if(i<j)
			swap(a+i,a+j);
		}
		swap(a+pi,a+j);
		pi = j;
		quick_sort(a,lb,pi-1);
		quick_sort(a,pi+1,ub);
	}
}

int main(){
	int n,i;
	printf("\nEnter the size of the array\n");
	scanf("%d",&n);
	int* a = (int*)malloc(sizeof(int)*n);
	printf("\nEnter elements\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	    printf("\nBefore sorting\n");
    for(i=0;i<n;i++){
        printf("%d,",a[i]);
        }
	quick_sort(a,0,n-1);
    printf("\nAfter sorting\n");
    for(i=0;i<n;i++){
        printf("%d,",a[i]);
        }
	return 0;
}
