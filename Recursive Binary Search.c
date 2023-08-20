#include<stdio.h>
int BSR(int arr[],int l, int h, int key)
{
	if(l<=h)
	{
		int mid=(l+h)/2;
		if (key==arr[mid])
	
			return mid;
	
		if (key<arr[mid])
	
			return BSR(arr,l,mid-1,key);
	
		else
		
		{	return BSR(arr,mid+1,h,key);
		
			}
}
		return -1;
	
}
int main()
{
	int arr[8]={20,30,40,50,60,70,80,90};
	int key;
	printf("Enetr the key element: ");
	scanf("%d",&key);
	int element=BSR(arr,0,7,key);
	if(element == -1)
	{
		printf("Element not found.");
	}
	else
	{
		printf("Element found at : %d", element);
	}
	return 0;
}
