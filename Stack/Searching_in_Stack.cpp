/*
Search for a value in a stack and return its distance from the top.
Hint: Return -1 if not found. The top element has distance 0
*/

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

void search(int target)
{
    Node* temp = top;
    int count = 0;
    while(temp !=nullptr)
    {
        if(temp->data == target)
        {
            cout<<"Found at: "<<count<<endl;
            return;
        }
        
        temp= temp->next;
        count++;
    }
}

int main()
{
    push(1);
    push(2);
    push(3);
    search(1);

}