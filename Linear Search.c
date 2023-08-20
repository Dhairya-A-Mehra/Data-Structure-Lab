#include<stdio.h>
#include<stdbool.h>
int main()
{
	int arr[5]={2,10,5,6,37};
	int key,i,count=0;
	//bool x=false;
	printf("Enter the key element: ");
	scanf("%d",&key);
	for (i=0;i<5;i++)
	{
		if(arr[i]==key)
		{
			//x=true;
			count++;
		}
		/*else
		{
			printf("Element not found.");
		}*/
	}
	if(count>0)
	{
		printf("Element found.");
	}
	else
	{
		printf("Element not found.");
	}
	return 0;
}
