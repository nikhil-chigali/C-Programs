//Selection Sort
#include<stdio.h>
#include<stdlib.h>

/*
	time complexity = O(n^2)
*/
void swap(int* x,int* y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void selection_sort(int* a,int n){
	int i,imin,j;
	for(i=0;i<=n-2;i++){
		imin = i;
		for(j=i+1;j<=n-1;j++){
			if(a[j]<a[imin])
			imin = j;
		}
		swap(a+i , a+imin);
	}
}


int main(){
	int n;
	printf("\nEnter the size of the array\n");
	scanf("%d",&n);
	int *a = (int*)malloc(sizeof(int)*n);
	printf("\nEnter the array elements\n");
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	    printf("\nBefore sorting\n");
    for(i=0;i<n;i++){
        printf("%d,",a[i]);
        }
       selection_sort(a,n);
    printf("\nAfter sorting\n");
    for(i=0;i<n;i++){
        printf("%d,",a[i]);
        }
	return 0;
}
