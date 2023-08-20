#include<stdio.h>
void InsertionSort(int arr[], int size)
{
	int i,j;
	for (i=1; i<size;i++)
	{
		int key=arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}

int main()
{
	int arr[]={64,34,55,90,100,55};
	int i;
	int size=sizeof(arr)/sizeof(arr[0]);
	InsertionSort(arr, size);
	
	printf("Sorted Array: ");
	for (i=0;i<size-1;i++)
	{
		printf("%d",arr[i]);
		printf("\n");
	}

	return 0;
}
