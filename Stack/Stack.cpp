#include <iostream>
using namespace std;

#define MAX 3

class Stack
{
    int arr[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int value)
    {
        // Overflow check
        if (top == MAX - 1)
        {
            cout << "push(" << value << ") rejected with Stack Overflow" << endl;
            return;
        }

        top++;
        arr[top] = value;
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

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    s.display();

    return 0;
}