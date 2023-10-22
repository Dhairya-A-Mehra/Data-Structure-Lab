#include<stdio.h>
void SS(int arr[],int n)
{
	int i,j;
	for(i=0; i<n-1; i++)
	{
		int min_index=1;
		for(j=i+1; j<n; j++)
		{
			if(arr[j]<arr[min_index])
			{
				min_index=j;
			}
		}
		int temp=arr[i];
		arr[i]=arr[min_index];
		arr[min_index]=temp;
	}
}

int main()
{
	int i;
	int arr[]={64,25,12,22,11};
	int n=sizeof(arr)/sizeof(arr[0]);
	printf("Original Array: \n");
	for(i=0; i<n; i++)
	{
		printf("%d\n",arr[i]);
	}
	SS(arr,n);
	printf("\nSorted Array: ");
	for(i=0; i<n; i++)
	{
		printf("\n%d",arr[i]);
	}
	return 0;
}