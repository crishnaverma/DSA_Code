#include <iostream>
#include <algorithm>

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

void kth_level(Node* root, int k)
{
    if(root == NULL)
    {
        return;
    }

    if(k==1)
    {
        cout<<root->data<<" ";
        return;
    }
    kth_level(root->left,k-1);
    kth_level(root->right,k-1);

}


int main() {
    int arr[] = {
    1,
    2, 4, -1, -1, 5, -1, -1,
    3, 6, -1, -1, 7, -1, -1
    };

    Node* root = buildTree(arr);
    kth_level(root,2);
    return 0;
}