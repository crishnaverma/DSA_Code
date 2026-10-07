#include <iostream>
using namespace std;

#define max 5

class Queue
{
    int arr[max];
    int currsize, start,end;

public:
    Queue()
    {
        currsize = 0;
        start = -1;
        end = -1;
    }

    void push(int value)
    {
        if(currsize == max)
        {
            cout<<"over flow";
            return;
        }

        if(currsize == 0)
        {
            start = 0;
            end = 0;
        }
        else
        {
            end = (end+1)%max;
        }
        arr[end] = value;
        currsize++;
    }

    void pop()
    {
        if(currsize == 0)
        {
            cout<<"Empty Queue";
            return;
        }
        
        if(currsize == 1)
        {
            start = end = -1;
        }
        else
        {
            start++;
            currsize--;
        }
    }

    void display()
    {
        if (start == -1)
        {
            cout << "Queue is Empty" << endl;
            return;
        }

        int i = start;
        for (int count = 0; count < currsize; count++)
        {
            cout << arr[i] << " ";
            i = (i + 1) % max;
        }
        cout << endl;
    }

};

int main()
{
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.pop();

    q.display();

    return 0;
}