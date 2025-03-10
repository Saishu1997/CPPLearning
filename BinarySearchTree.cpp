/*

A BST is a binary tree where:

Left subtree contains smaller values.
Right subtree contains greater values.

*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int value)
{
    if(!root) return new Node(value);

    if(value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

bool search(Node* root, int key)
{
    if(!root) return false;
    if(root->data == key) return true;
    return key < root->data ? search(root->left, key) : search(root->right, key);
}

void inOrder(Node* root)
{
    if(!root) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main()
{
    Node* root = nullptr;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);

    cout << "BST InOrder Traversal: ";
    inOrder(root);
    cout<<"\n Search 7: "<< (search(root, 7) ? "Found" : "Not Found") << endl;

    return 0;
}