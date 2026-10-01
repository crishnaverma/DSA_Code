#include <iostream>
using namespace std;

#define max 3

class Stack
{
    int arr[max];
    int top;

public:
    stack()
    {
        top  = -1;
    }

    void push()
    {
        if(top==max-1)
        {
            cout<<"Stack Overflow";
            return;
        }
        top++;
        arr[top] = value;
    }

    void peek()
    {

    }

    void pop()
    {

    }
}

