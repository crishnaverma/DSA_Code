#include <iostream>
using namespace std;

class Node {

public:

    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

Node* buildTree(int arr[])
{
    static int index = -1;

    index++;

    if(arr[index] == -1)
    {
        return nullptr;
    }

    Node* root = new Node(arr[index]);
    root->left = buildTree(arr);
    root->right = buildTree(arr);

    return root;
}

int main() {
    int arr[] = {1, 2, -1, -1, 3, -1, -1};

    Node* root = buildTree(arr);
    return 0;
}