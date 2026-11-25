#include <iostream>
using namespace std;

class Heap{
    int * arr;
    int size;
    int total_size;

    public:

    Heap(int n)
    {
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    void insert(int val)
    {
        if(size==total_size)
        {
            cout<<"OverFlow";
            return;
        }
        arr[size] = val;
        int index = size;
        size++;

        while(index>0 && arr[(index-1)/2]<arr[index])
        {
            swap(arr[(index-1)/2],arr[index]);
            index = (index-1)/2;
        }
        cout<<arr[index]<<" is inserted into heap";
        cout<<endl;
    }
    
    void Heapify(int index)
    {

        int largest = index;
        int left = 2*index+1;
        int right = 2*index+2;
        if(left < size && arr[2*index+1]>arr[2*index+2])
        largest = left;
        
        if(right < size && arr[2*index+1]<arr[2*index+2])
        largest = right;

        if(largest != index)
        {
            swap(arr[index],arr[largest]);
            Heapify(largest);
        }
    }
    
    
    void deleteheap(){
        if(size == 0)
        {
            cout<<"UnderFlow\n";
            return;
        }
        
        cout<<arr[0]<<" Delete from heap\n";
        arr[0]=arr[size-1];
        size--;
        if(size==0)
        return;
        
        Heapify(0);

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
    Heap h(6);
    h.insert(50);
    h.insert(30);
    h.insert(40);
    h.deleteheap();
    h.insert(10);
    h.insert(20);
    h.deleteheap();
    h.insert(60);
    h.display();
    h.deleteheap();
    h.deleteheap();
    h.deleteheap();
    h.display();
    h.deleteheap();
    h.display();
    h.deleteheap();
    


}