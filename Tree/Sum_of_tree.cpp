#include <iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
            data = val;
            left = right = NULL;
    }
};

Node* buildTree(int arr[])
{
    static int index = -1;
    index++;

    if(arr[index] == -1)
    {
        return NULL;
    }

    Node* root = new Node(arr[index]);
    root->left = buildTree(arr);
    root->right = buildTree(arr);
    return root;
}


int sumTree(Node* root)
{
    if (root == NULL)
    return 0;

    int left_sum = sumTree(root->left);
    int right_sum = sumTree(root->right);

    root->data += left_sum + right_sum;
    return root->data;
}

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


int main() {
    int arr[] = {
    1,
    2, 4, -1, -1, 5, -1, -1,
    3, 6, -1, -1, 7, -1, -1
    };

    Node* root = buildTree(arr);
    sumTree(root);
    preorder(root);

    return 0;
}