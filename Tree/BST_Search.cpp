
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

// Insert into BST
Node* insert(Node* root, int val)
{
    if(root == NULL)
    {
        return new Node(val);
    }

    if(root->data > val)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }

    return root;
}

// Build BST
Node* buildBST(int arr[], int n)
{
    Node* root = NULL;

    for(int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }

    return root;
}

// Inorder Traversal
void inorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

bool BST_Search(Node* root, int tar)
{
    if (root == NULL)
    return false;

    if(root->data == tar)
    {
        return true;
    }
    
    else if(root->data>tar)
    {
        return BST_Search(root->left,tar);
    }
    else
    {
        return BST_Search(root->right,tar);
    }
}

int main()
{
    int arr[] = {1, 2, 4, 5, 3, 6, 7};

    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = buildBST(arr, n);

    cout << "Inorder Traversal: ";
    inorder(root);

    if(BST_Search(root, 6))
    {
        cout << "\nElement Found";
    }
    else
    {
        cout << "\nElement Not Found";
    }

    return 0;
}
