/*

A Tree is a hierarchical data structure where each node has a parent and 
children (except the root). It is widely used in:

Binary Search Trees (BST)
Heaps
Tries
Segment Trees
Balanced Trees (AVL, Red-Black Tree)

Basic Terminology

Root → The top node of the tree.
Parent & Child → Nodes connected directly above and below.
Siblings → Nodes sharing the same parent.
Leaf → Node with no children.
Depth → Distance from root to node.
Height → Longest path from a node to a leaf.
Binary Tree → Each node has at most two children.
Binary Search Tree (BST) → Left child < Parent < Right child.

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

void preOrder(Node* root)
{
    if(!root) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root)
{
    if(!root) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node* root)
{
    if(!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Preorder: ";
    preOrder(root);
    cout << "\n InOrder: ";
    inOrder(root);
    cout << "\n PostOrder: ";
    postOrder(root);

    return 0;
}