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

int sum_of_Nodes(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int left_sum = sum_of_Nodes(root->left);
    int right_sum = sum_of_Nodes(root->right);

    return left_sum+right_sum +root->data;
}

int main() {
    int arr[] = {
    1,
    2, 4, -1, -1, 5, -1, -1,
    3, 6, -1, -1, 7, -1, -1
    };

    Node* root = buildTree(arr);
    cout << sum_of_Nodes(root);
    return 0;
}