/*
Reverse a string using a stack.
Hint: Push every character, then pop them all. Why does LIFO give you the reverse?
INPUT "stack"
OUTPUT "kcats"
*/

#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    char data;
    Node* next;
    Node(char data)
    {
        this->data = data;
        this->next = nullptr; 
    }
};

Node* top = nullptr;

void push(char value)
{
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
}

void pop()
{
    if(top == nullptr)
    {
        cout<<"UnderFlow";
        return;
    }
    Node* temp = top;
    cout<<temp->data;
    top = top->next;
    delete temp;
}

int main()
{
    push('s');
    push('t');
    push('a');
    push('c');
    push('k');
    pop();
    pop();
    pop();
    pop();
    pop();
}