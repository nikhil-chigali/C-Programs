// Insertion sort

#include<stdio.h>
#include<stdlib.h>
/*
	Best case = O(n)
	avg & worst case = O(n^2)
	
	but yet better than bubble sort b'cuz no. of comparisons & shifts are relatively less
*/

int* insertion_sort(int* a , int n){
	
	int key,unsorted,hole,t;
	for	(unsorted = 1;unsorted < n;unsorted++){
		key = a[unsorted];			// runs n-1 times
		hole = unsorted;
		while( hole>0 && a[hole-1]>key){			// the hole moves to the left in this loop
			a[hole] = a[hole-1];
			hole--;
		}
		a[hole] = key;			// the hole is filled with the key value
		printf("\nAfter %d pass(es):\n",unsorted);
    	for(t=0;t<n;t++){
            printf("%d , ",a[t]);
        }
	}
	return a;
}


int main(){
	int n;
	printf("\nenter the size of the array:\t");
	scanf("%d",&n);
	int *a = (int*)malloc(sizeof(int)*n);
	int i;
    printf("\nEnter array elements:\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("\nBefore sorting:\n");
    for(i = 0; i<n ; i++){
    printf("%d , ",a[i]);
    }
    printf("\n\n*********************\n");
    a = insertion_sort( a , n );
    printf("\n\n*********************\n");
    printf("\nAfter sorting:\n");
    for(i = 0; i<n ; i++){
    printf("%d , ",a[i]);
    }
	
	return 0;
}

