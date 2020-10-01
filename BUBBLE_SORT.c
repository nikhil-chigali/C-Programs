// Bubble sort Algorithm

#include<stdio.h>
#include<stdlib.h>
#define null 0

/*
 *
 * best-case : O(n)
 * average and worst case : O(n^2)
 *
 * */


void swap(int* x, int* y){

    int temp;
    temp = *x;
    *x = *y;
    *y = temp;

    }

int* bubble_sort(int* a , int n){
    int i,j,flag,t;
    for(i=0;i<n-1;i++){
        flag = 0;
        for(j=0;j<=n-2-i;j++){

            if(a[j]>a[j+1]){

                swap( a+j , a+j+1 );
                flag = 1;

                }

            }
            printf("\nAfter %d pass(es):\n",i+1);
            for(t=0;t<n;t++){

                printf("%d , ",a[t]);

                }
            if(flag == 0)
                return a;
        }
        return a;
    }

int main(){

    int n,i;
    printf("Enter the size of the array\t");
    scanf("%d",&n);
    int *a = (int*)malloc(sizeof(int)*n);
    printf("\nEnter array elements:\n");
    for(i = 0; i<n ; i++){
        scanf("%d",&a[i]);
        }
    printf("\nBefore sorting:\n");
        for(i = 0; i<n ; i++){
        printf("%d , ",a[i]);
        }
        printf("\n\n*********************\n");
        a = bubble_sort( a , n );
        printf("\n\n*********************\n");

    printf("\nAfter sorting:\n");
        for(i = 0; i<n ; i++){
        printf("%d , ",a[i]);
        }
    return 0;
    }

