/*
Reverse a singly linked list iteratively.
Hint: Track three pointers: previous, current, and next — in that order.
Input List: 1 -> 2 -> 3 -> 4 -> 5
Output 5 -> 4 -> 3 -> 2 -> 1
*/

#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data, Node* ptr){
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


Node* reverse(Node* head)
{
    Node* temp = head;
    Node* next = nullptr;
    Node* prev = nullptr;
    while(temp != nullptr)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    return prev;

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
    vector<int> arr = {1, 2, 3, 4, 5};

    Node* head = Linkedlist(arr);

    cout << "Original List: ";
    printList(head);

    head = reverse(head);

    cout << "\nReversed List: ";
    printList(head);

    return 0;
}