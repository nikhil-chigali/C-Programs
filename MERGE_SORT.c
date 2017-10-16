//merge sort
#include<stdio.h>
#include<stdlib.h>
#define and &&
#define or ||

/*
 *
 * worst case time complexity = O(NlogN)
 * space complexity = O(N)
 *
 * */
  void merge(int *left ,int Ln ,int* right ,int Rn ,int* a ,int n);
 void split(int* a,int n);


 void split(int* a,int n){
     if(n == 1){
     return;
     }

     else{
     int Ln = n/2 , i;
     int Rn = n-Ln;
     int *left = (int*)malloc(sizeof(int)*Ln);
     int *right= (int*)malloc(sizeof(int)*Rn);
     for(i = 0;i < Ln; i++){
         left[i]=a[i];
         }
     for(i=Ln;i<n;i++){
         right[i-Ln] = a[i];
         }
     split(left , Ln);
     split(right , Rn);
     merge(left , Ln , right , Rn , a , n);
     }
 }
/*
 *
 * Ignore this part
 *
 *
 void merge(int *left ,int Ln ,int* right ,int Rn ,int* a ,int n){
     while(left != left+Ln and right != right+Rn){
         if(*left <= *right){
         *a = *left;
         a++;left++;
         }
         else if(*left > *right){
         *a = *right;
         a++;right++;
         }
         }
         while(left == left+Ln){
             *a = *right;
             a++;right++;
             }
         while(right == right+Rn){
            *a = *left;
            a++;left++;
             }

     }
*/
void merge(int *left ,int Ln ,int* right ,int Rn ,int* a ,int n){
    int i=0;    //for left
    int j=0;    //for right
    int k=0;    //for a
    while(i<Ln and j<Rn){
        if(left[i]>right[j]){
            a[k]=right[j];
            k++;j++;
            }
        else{
            a[k] = left[i];
            k++;i++;
            }
        }
    while(i<Ln){
        a[k] = left[i];
        k++;i++;
        }
    while(j<Rn){
        a[k] = right[j];
        k++;j++;
        }

}

 int main(){
    int i,n;
    printf("\nEnter size of the array\n");
    scanf("%d",&n);
    int* a = (int*)malloc(sizeof(int)*n);
    printf("\nEnter the elements of the array\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        }
    printf("\nBefore sorting\n");
    for(i=0;i<n;i++){
        printf("%d,",a[i]);
        }
       split(a,n);
    printf("\nAfter sorting\n");
    for(i=0;i<n;i++){
        printf("%d,",a[i]);
        }

return 0;
 }

