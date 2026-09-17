/*
 Search for a given value in a linked list and return its position.
Hint: Return -1 (or similar) if not found.
Input List: 4 -> 9 -> 2 -> 6, Target: 2
Output 2 (0-indexed position)
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

int searching(Node* head, int target)
{
    int cout = -1;
    while(head != nullptr)
    {
        cout++;
        if(head->data == target)
        {
            return cout;
        }
        head = head->next;
    }
    return -1;
}

int main()
{
    vector<int> arr = {4, 9, 2, 6};

    Node* head = Linkedlist(arr);

    int index = searching(head,2);
    cout<<index;
    return 0;
}