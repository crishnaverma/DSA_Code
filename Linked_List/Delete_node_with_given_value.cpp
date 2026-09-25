/*
Delete a node with a given value.
Hint: Consider what happens if the value is in the head node.
Input List: 5 -> 3 -> 9 -> 1, Value: 9
Output 5 -> 3 -> 1
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

Node* Delete_node_with_given_value(Node* head, int target)
{
    if (head == nullptr) return head;

    if(head->data == target)
        {
            Node* del = head;
            head = head->next;
            delete del;
            return head;
        }
    Node* temp = head;
    while(temp != nullptr)
    {
        if (temp->next->data == target)
        {
            delete temp->next;
            temp->next = temp->next->next;
            //delete nodeToDelete;
            return head;
        }   
        temp = temp->next;
    }
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

    head = Delete_node_with_given_value(head, 3);

    printList(head);

    return 0;
}