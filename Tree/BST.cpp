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

Node* insert(Node* root, int val)
{
    if(root == NULL)
    {
        return new Node(val);
    }

    if(root->data >val)
    {
        root->left = insert(root->left,val);
    }

    else()
    {
        root->rigth = insert(root->right < val);
    }

    return root;

}

Node* buildBst(int arr)
{
    Node* root = NULL;

    for(int val : arr)
    {
        root = insert(root,val);
    }
    return root;
}