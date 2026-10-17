/*
Traverse a stack and print all elements from top to bottom.
Hint: Traversal must not destroy the stack. Walk the index (or pointer) instead of popping.
INPUT push(1), push(2), push(3)
OUTPUT 3 2 1

*/


#include <iostream>
using namespace std;

#define max 4
class Stack
{
    int arr[max];
    int top;

public:
    Stack()
    {
        top= -1;
    }

    void push(int value)
    {
        if(top == max-1)
        {
            cout<<"over flow"<<endl;
            return;
        }

        top++;
        arr[top]= value;
    }

    void pop()
    {
        if(top == -1)
        {
            cout<<"Under Flow";
            return;
        }

        top--;
    }

    void peek()
    {
        if(top == -1)
        {
            cout<<"empty";
            return;
        }
        cout<<arr[top];
    }
    void display()
    {
        for(int i = 0;i<=top;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.display();
}