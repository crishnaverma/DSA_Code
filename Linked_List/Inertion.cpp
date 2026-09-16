/*
Question:-
Insert a node at the beginning of a singly linked list.
Hint: Think about which pointer needs to change first so you don't lose the rest of the list.
Input List: 2 -> 3 -> 4, Value to insert: 1
Output 1 -> 2 -> 3 -> 4
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

Node*  Insertion_at_first(Node* head,int value)
{
    Node* node1 = new Node(value,head);
    head = node1;
    return head;
    
}

Node* printList(Node* head)
{
while(head != nullptr)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main()
{
    vector<int> arr = {2, 3, 4};

    Node* head = Linkedlist(arr);

    head = Insertion_at_first(head, 1);

    printList(head);

    return 0;
}