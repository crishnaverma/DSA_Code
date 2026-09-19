/*
Question:-
Delete the last node of a linked list.
Hint: You'll need to track the second-to-last node too.
Input List: 1 -> 2 -> 3 -> 4
Output 1 -> 2 -> 3
*/


#include <iostream>
#include <vector>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data,Node*ptr)
    {
        this->data = data;
        this->next = ptr;
    }
};

Node* Linkedlist(vector<int>& arr)
{
    Node* head = new Node(arr[0],nullptr);
    Node* temp = head;
    for(int i =1;i<arr.size();i++)
    {
        Node* newNode = new Node(arr[i], nullptr);
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}

Node*  delete_last_node(Node* head,int value)
{
    if (head == nullptr) return nullptr;

    if(head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    Node* temp = head;
    while(temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    
    delete temp->next;
    temp->next = nullptr;
    return head;
    
}

void printList(Node* head)
{
while(head != nullptr)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};

    Node* head = Linkedlist(arr);

    head = delete_last_node(head, 1);

    printList(head);

    return 0;
}