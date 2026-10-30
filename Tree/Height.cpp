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

int height(Node* root)
{
    if(root == NULL)
    return 0;

    int left_heigth = height(root->left);
    int right_heigth = height(root->right);

    return max(left_heigth,right_heigth)+1;
}


int main() {
    int arr[] = {
    1,
    2, 4, -1, -1, 5, -1, -1,
    3, 6, -1, -1, 7, -1, -1
    };

    Node* root = buildTree(arr);
    cout << height(root);
    return 0;
}