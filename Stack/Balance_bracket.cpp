/*
Check whether an expression has balanced brackets: (), [], {}.
Hint: Push openers; on a closer, the top must be its matching opener. Check emptiness at the end too.
INPUT "{[()]}" and "{[(])}"
OUTPUT true, false
*/

#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    char data;
    Node* next;

    Node(char value)
    {
        data = value;
        next = nullptr;
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
    if (top == nullptr)
        return;

    Node* temp = top;
    top = top->next;
    delete temp;
}

bool isEmpty()
{
    return top == nullptr;
}
