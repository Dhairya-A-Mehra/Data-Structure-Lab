#include<iostream>
using namespace std;
void BS(int arr[],int key, int n)
{
    int i, count=0;
    for(i=0; i<n; i++)
    {
        if(arr[i]==key)
        {
            count++;
        }
    }
    if(count>0)
    {
        cout<<"Element found."<<endl;
    }
    else
    {
        cout<<"Element not found."<<endl;
    }
}

int main()
{
    int n, i, key;
    cout<<"Enter the no. of elements in array."<<endl;
    cin>>n ;
    int *arr= new int[n];
    cout<<"Enter the array elements."<<endl;
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the key element."<<endl;
    cin>>key;
    BS(arr, key, n);
    return 0;

}
