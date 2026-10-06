/*
Implement pop with an underflow check.
Hint: Read the element first, then decrement top. What should pop return on an empty stack?
INPUT Stack (bottom -> top): 5 6, then pop(), pop(), pop()
OUTPUT 6, 5, Stack Underflow
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
        top = -1;
    }

    void push(int value)
    {
        if(top == max-1)
        {
            cout << "push(" << value << ") rejected with Stack Overflow" << endl;
            return;
        }

        top++;
        arr[top] = value;
        
    }

    void pop()
    {
        if(top == -1)
        {
            cout<<"Stack Underflow";
        }

        top--;
    }

    void display()
    {
        cout << "stack (bottom -> top): ";

        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
}; 

int main()
{
    Stack s;
    s.push(5);
    s.push(4);
    s.display();
    s.push(6);
    s.pop();
    s.pop();
    s.display();
}
