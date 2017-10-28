//Binary search

#include<stdio.h>
#include<stdlib.h>

int compare(const void* a,const void* b){
    int x = *((int*)a);
    int y = *((int*)b);
    return x-y;
    }

int binary_search(int *a,int lb,int ub ,int key){
    if(ub == lb){
        return a[lb] == key;

        }
    else if(ub>lb){
    int mid;
    mid = (ub+lb)/2;
    if(key<a[mid]){
        return binary_search(a,lb,mid-1,key);
        }
    else if(key>a[mid]){
        return binary_search(a,mid+1,ub,key);
        }
    else {
        return a[mid] == key;
        }
    }
    else
    return 0;
    }

int main(){
    int i,n;
    printf("Enter size:\t");
    scanf("%d",&n);
    int* a = (int*)malloc(sizeof(int)*n);
    for(i = 0;i<n;i++){
        scanf("%d",&a[i]);
        }
    qsort(a,n,sizeof(int),compare);
    int key,temp;
    printf("\nEnter the element you want to search, enter -1 to stop your search\n");
    scanf("%d",&key);
    while(key!=-1){

        temp = binary_search(a,0,n-1,key);
        if(temp){
            printf("\nElement %d is found\n",key);
            }
        else{
            printf("\nElement not found\n");
            }

        scanf("%d",&key);
        }
    return 0;
    }
