// Bubble Sort
#include<stdio.h>
#include<stdbool.h>
void swap(int *a, int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int BS(int arr[],int n)
{
	int i,j;
	bool flag;
	for (i=0; i<n-1; i++)
	{
		flag=false;
		for(j=0; j<n-i-1; j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(&arr[j], &arr[j+1]);
				flag=true;
			}
		}
		if(flag==false)
		{
			printf("The Array is already Sorted\n");
			break;
		}
	}
	return 0;
}

int main()
{
	int arr[5];
	int n=5;
	int i,j;
	printf("Enter array element: ");
	for(i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	BS(arr,n);
	printf("Sorted Array is: ");
	for(i=0;i<n;i++)
	{
		printf("\n %d",arr[i]);
	}
	return 0;
}