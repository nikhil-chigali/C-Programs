//Linear search
#include<stdio.h>
#include<stdlib.h>

int main(){
int n;
printf("\nEnter size:\n");
scanf("%d",&n);
int* a = (int*)malloc(sizeof(int)*n);
printf("\nEnter elements\n");
int i;
for (i = 0;i <n ;i++){
    scanf("%d",&a[i]);
    }
printf("\nEnter the element you want to search....Enter -1 to stop ur search\n");
int key,flag;
scanf("%d",&key);
while(key!=-1){
    flag = 0;
    for(i = 0;i<n;i++){
        if(key == a[i]){
            flag = 1;
            break;
            }
        }
        if(flag)
        printf("\nElement found\n");
        else
        printf("\nElement not found\n");
        scanf("%d",&key);
    }

return 0;
}
