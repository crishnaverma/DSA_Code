#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

Node* Linkedlist(vector<int>& arr)
{
    Node* head = new Node(arr[0]);
    Node* temp = head;

    for(int i = 1; i < arr.size(); i++)
    {
        Node* newNode = new Node(arr[i]);

        temp->next = newNode;
        newNode->prev = temp;

        temp = newNode;
    }

    // Create cycle: last node -> second node
    temp->next = head->next;
    head->next->prev = temp;

    return head;
}

bool hasCycle(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};

    Node* head = Linkedlist(arr);
    if(hasCycle)
    cout<<"True";

    return 0;
}