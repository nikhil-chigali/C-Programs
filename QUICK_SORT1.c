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
		int pi , pivot ,piv_lctn , i;
		piv_lctn = ub;		
		//here the element at upper bound is taken as pivot
		//you can change the ub to some other number between lb and ub to change the pivot element
		pivot = a[piv_lctn];
		pi = lb;
		for(i=lb;i<=ub;i++){
			if(piv_lctn!=i){
				if(a[i]<=pivot){
					if(pi == piv_lctn)
						pi++;
					swap(a+i,a+pi);
					pi++;
				}
			}
		}
		swap(a+piv_lctn , a+pi);
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
