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

//========================================================================================================================================================

// Traversal

//========================================================================================================================================================

//PREORDER

void preorder(Node* root)
{
    if(root == nullptr)
    {
        return;
    }

    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);
}

//Inorder

void inorder(Node* root)
{
    if(root == nullptr)
    {
        return;
    }

    preorder(root->left);
    cout<<root->data<<endl;
    preorder(root->right);
}

//Postorder

void postorder(Node* root)
{

    if(root == nullptr)
    return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<endl;
}


int main() {
    int arr[] = {1, 2, -1, -1, 3, -1, -1};

    Node* root = buildTree(arr);
    preorder(root);
    cout<<"Inorder"<<endl;
    inorder(root);
    cout<<"Postorder"<<endl;
    postorder(root);
    return 0;
}