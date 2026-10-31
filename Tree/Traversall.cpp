#include <iostream>
#include <queue>
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


//Level order

void levelorder(Node* root)
{
    queue<Node*> q;

    q.push(root);

    while(q.size()>0)
    {
        Node* curr = q.front();
        q.pop();

        cout<<curr->data<<endl;

        if(curr->left != nullptr)
        {
            q.push(curr->left);
        }

        if(curr->right != nullptr)
        {
            q.push(curr->right);
        }
    }
}


//Level order (print node in level)

void levelorder_in_new_line(Node* root)
{
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while(q.size()>0)
    {
        Node* curr = q.front();
        q.pop();

        if(curr == NULL)
        {
            if(q.size()>0)
            {
                cout<<endl;
                q.push(NULL);
                continue;
            }
            else
            break;
        }

        cout<<curr->data<<" ";

        if(curr->left != nullptr)
        {
            q.push(curr->left);
        }

        if(curr->right != nullptr)
        {
            q.push(curr->right);
        }
    }
}

int main() {
    int arr[] = {1, 2, -1, -1, 3, -1, -1};

    Node* root = buildTree(arr);
    preorder(root);
    cout<<"Inorder"<<endl;
    inorder(root);
    cout<<"Postorder"<<endl;
    postorder(root);
    cout<<"Levelorder"<<endl;
    levelorder(root);
    cout<<"Levelorder"<<endl;
    levelorder_in_new_line(root);
    return 0;
}