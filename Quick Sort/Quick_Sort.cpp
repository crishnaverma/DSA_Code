#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int i = start-1;

    for(int j= start; j<end;j++)
    {
        if(arr[j]<pivot){
            i++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[i+1],arr[end]);
    return i+1;
}

void quicksort(int arr[], int start, int end)
{
    if(start<end)
    {
        int pvtIndex = partition(arr,start, end);
        
        quicksort(arr, start, pvtIndex-1);
        quicksort(arr, pvtIndex+1, end);
    }
}

int main()
{
    int arr[] = {5, 3, 8, 4, 2, 7, 1, 10};

    int n = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}