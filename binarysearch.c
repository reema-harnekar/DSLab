#include<stdio.h>
#define MAX 100
int binary_search(int a[], int n, int x)
{
	int mid=n/2;
	int high=n-1,low=0;
	while(high>=low)
	{
		if(a[mid]==x)
			return mid;
		if(x>a[mid])
			low=mid+1;
		else
			high=mid-1;
		mid=(high+low)/2;
	}
	return -1;
}

int main()
{
	int a[MAX],n,e,i;
	printf("Enter the no of elements(max 100):\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the element to be searched\n");
	scanf("%d",&e);
	if(binary_search(a,n,e)!=-1)
		printf("Element found at %d\n",binary_search(a,n,e));
	else
		printf("Element not found\n"); 
	return 0;
}
