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

bool isBalanced(string expression)
{
    while(!isEmpty())
    pop();
    for(char ch : expression)
    {
        if(ch == '(' ||ch == '{' || ch == '[')
        {
            push(ch);
        }
        else if(ch == ')' ||ch == '}' || ch == ']')
        {
            if(isEmpty())
            return false;

            char opening = top->data;

            if((ch == ')' && opening != '(')
             ||(ch == '}' && opening != '{')
             ||(ch == ']' && opening != '['))
             {
                return false;
             }
             pop();
        }
        
       
    }
    return isEmpty();
}

int main()
{
    cout << boolalpha;
    cout << isBalanced("{[()]}") << endl;
    cout << isBalanced("{[(])}") << endl;

    return 0;
}