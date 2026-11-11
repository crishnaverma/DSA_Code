
#include <iostream>
using namespace std;

void merge(int arr[],int start,int mid,int end)
{
    int arr1[end-start+1];
    int x=0;
    int i=start;
    int j=mid+1;

    while(i<=mid && j<=end)
    {
        if(arr[i]<=arr[j])
        {
            arr1[x]=arr[i];
            i++;
        }
        else
        {
            arr1[x]=arr[j];
            j++;
        }
        x++;
    }

    while(i<=mid)
    {
        arr1[x]=arr[i];
        x++;
        i++;
    }

    while(j<=end)
    {
        arr1[x]=arr[j];
        x++;
        j++;
    }

    for(int k=0;k<x;k++)
    {
        arr[start+k]=arr1[k];
    }
}

void mergesort(int arr[],int start,int end)
{
    if(start>=end)
    {
        return;
    }

    int mid=start+(end-start)/2;

    mergesort(arr,start,mid);
    mergesort(arr,mid+1,end);

    merge(arr,start,mid,end);
}

int main()
{
    int arr[]={5,2,8,1,3,7,4,6};
    int n=sizeof(arr)/sizeof(arr[0]);

    mergesort(arr,0,n-1);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}
