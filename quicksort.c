#include <stdio.h>
#define MAX 100

int split(int arr[], int lower, int upper)
{
	int pivot = lower,temp;
	int a = pivot+1;
	int b=upper;
	while(b>=a)
	{
		while(arr[a]<arr[pivot])
			a++;
		while(arr[b]>arr[pivot])
			b--;
		if(b>a)
		{
			temp=arr[a];
			arr[a]=arr[b];
			arr[b]=temp;
		}
	}
	temp=arr[b];
	arr[b]=arr[pivot];
	arr[pivot]=temp;
	return b;
}

void quicksort(int a[],int l,int u)
{
	int i;
	if(u>l)
	{
		i=split(a,l,u);
		quicksort(a,l,i-1);
		quicksort(a,i+1,u);
	}
}

int main()
{
	int a[MAX],n,i;
	printf("Enter the no of elements(max 100):\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	quicksort(a,0,n-1);
	printf("The sorted array is :\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}
