#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data, Node* ptr){
        this->data = data;
        this->next = ptr;
    }
};

int countNodes(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp != nullptr){
        count++;
        temp = temp->next;
    }
    return count;
}

int main(){
    Node* head = new Node(7,nullptr);
    head->next = new Node(8,nullptr);
    head->next->next = new Node(9,nullptr);
    head->next->next->next = new Node(10,nullptr);

    cout << countNodes(head);

    return 0;
}