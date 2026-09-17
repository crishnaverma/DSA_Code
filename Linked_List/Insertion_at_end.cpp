/*
Insert a node at the end of a singly linked list.
Hint: Handle the empty-list case separately from the general case.
Input List: 1 -> 2 -> 3, Value to insert: 4
Output 1 -> 2 -> 3 -> 4
*/


#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data, Node* ptr)
    {
        this->data = data;
        this->next = ptr;
    }
};


Node* Linkedlist(vector <int> &arr)
{
    Node* head = new Node(arr[0],nullptr);
    Node* temp = head;
    for(int i = 1;i<arr.size();i++)
    {
        Node* newNode = new Node(arr[i],nullptr);
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}

Node* Insertion_end(Node* head, int value)
{
    Node* temp = head;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    Node* newNode = new Node(value, nullptr);
    temp->next = newNode;

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
    vector<int> arr = {2, 3, 4};

    Node* head = Linkedlist(arr);

    head = Insertion_end(head, 1);

    printList(head);

    return 0;
}
