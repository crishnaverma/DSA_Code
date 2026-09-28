#include <iostream>
using namespace std;

#define MAX 100

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    // Push element
    void push(int value) {
        if (top == MAX - 1) {
            cout << "Stack Overflow\n";
            return;
        }

        top++;
        arr[top] = value;
        cout << value << " pushed into stack\n";
    }

    // Pop element
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }

        cout << arr[top] << " popped from stack\n";
        top--;
    }

    // Peek / Top element
    void peek() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Top element: " << arr[top] << endl;
    }

    // Display stack
    void display() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Stack: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.peek();

    s.pop();
    s.display();

    return 0;
}