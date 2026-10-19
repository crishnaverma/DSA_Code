#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

};

Node* top = nullptr;

void push(int value)
{
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;

    cout<<value<<" Pushed"<<endl;
}

void pop()
{
    if (top == NULL) {
        cout << "Stack Underflow\n";
        return;
    }

    Node* temp = top;
    cout<<"Poped "<<top->data<<endl;
    top = temp->next;
    delete temp;
}

void peek()
{
     if (top == NULL) {
        cout << "Stack is empty\n";
    } else {
        cout << "Top element: " << top->data << endl;
    }
}

int main()
{
    push(1);
    push(2);
    push(3);
    pop();

}