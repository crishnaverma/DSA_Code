/*
Find the middle node of a linked list in a single pass.
Hint: Two pointers moving at different speeds solve this without counting nodes first.
Input List: 1 -> 2 -> 3 -> 4 -> 5
Output 3 (for even length, e.g. 1->2->3->4, output 3 — the second middle)
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

int middle_node(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}



int main()
{
    vector<int> arr = {2, 3, 4};

    Node* head = Linkedlist(arr);

    int middle = middle_node(head);

    cout<<middle;

    return 0;
}