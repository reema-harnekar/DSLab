/*
Name:-Harnekar Reema Salahuddin
Roll No:- 16CO02
Description:-Program to implement binary search technique.
*/
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
	printf("Enter the elements::\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the element to be searched\n");
	scanf("%d",&e);
	if(binary_search(a,n,e)!=-1)
		printf("Element found at %d\n",1+binary_search(a,n,e));
	else
		printf("Element not found\n");
	return 0;
}
/*
OUTPUT:-
Enter the no of elements(max 100):
8
Enter the elements::
2
6
8
9
16
45
62
84
Enter the element to be searched
16
Element found at 5
*/
