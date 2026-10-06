/*
Implement peek, isEmpty and isFull.
Hint: None of these should modify the stack.
INPUT push(4), push(8), peek()
OUTPUT 8
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
};

int main()
{
    Stack s;
    s.push(4);
    s.push(6);
    s.peek();
}