#include<stdio.h>

void swap(int *a, int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int arr[], int low, int high)
{
	int pivot=arr[high];
	int j;
	int i=low-1;
	for(j=low;j<=high-1;j++)
	{
		if(arr[j]<=pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return i+1;
}

void Quick_Sort(int arr[], int low, int high)
{
	if(low<high)
	{
		int pivot_index=partition(arr,low,high);
		Quick_Sort(arr,low,pivot_index-1);
		Quick_Sort(arr,pivot_index+1,high);
	}
}

int main()
{
	int arr[]={64,34,55,90,100,55};
	int i;
	int size=sizeof(arr)/sizeof(arr[0]);
	Quick_Sort(arr, 0, size-1);
	
	printf("Sorted Array: ");
	for (i=0;i<size-1;i++)
	{
		printf("%d",arr[i]);
		printf("\n");
	}

	return 0;
}
