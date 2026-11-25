#include <iostream>
using namespace std;

class maxHeap{

    int* arr;
    int size;
    int total_size;
    
    public:

    maxHeap(int n)
    {
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    void insert(int val)
    {
        if(size == total_size)
        {
            cout<<"Heap Overflow";
            return;
        }
        arr[size]=val;
        int index = size;
        size++;

        while(index>0 && arr[(index-1)/2]<arr[index])
        {
            swap(arr[index], arr[(index-1)/2]);
            index = (index-1)/2;
        }

        cout<<arr[index]<< " is inserted into the heap";
        cout<<endl;

    }

    void display()
    {
        for (int i =0;i<size;i++)
        {
            cout<<arr[i]<<" ";
            cout<<endl;
        }
    }

};



int main()
{
    maxHeap h(6);
    h.insert(50);
    h.insert(30);
    h.insert(40);
    h.insert(10);
    h.insert(20);
    h.insert(60);

    cout << "Max Heap: \n";
    h.display();
}