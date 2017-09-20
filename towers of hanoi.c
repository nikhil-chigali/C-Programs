#include<stdio.h>

void th(int n,char sp,char dp,char ap)
{
	if(n==1)
	{
		printf("\nmove disk 1 from %c to %c\n",sp,dp);
	}
	else{
		th(n-1,sp,ap,dp);
		printf("\nmove disk %d from %c to %c\n",n,sp,dp);
		th(n-1,ap,dp,sp);
	}
}

int main()
{
	int n;
	printf("enter no. of disks: ");
	scanf("%d",&n);
	th(n,'s','d','a');
	return 0;
}
