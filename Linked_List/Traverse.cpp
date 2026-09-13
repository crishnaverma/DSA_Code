#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int data,Node* ptr)
    {
        this->data = data;
        this->next = ptr;
    }
};


Node* linkedlist(vector <int> &arr)
{
    Node* head = new Node(arr[0], nullptr);
    Node* temp = head;

    for(int i=1;i<arr.size();i++)
    {
        Node* newNode = new Node(arr[i],nullptr);
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout<<"Enter the element you want to insert";
    int y;
    cin>>y;

    
    Node* head = linkedlist(arr);
    Node* temp = head;

    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

}