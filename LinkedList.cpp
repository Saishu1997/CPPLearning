/*

A Linked List is a dynamic data structure where elements (nodes) are linked together using pointers. Unlike arrays, linked lists do not require contiguous memory and can grow or shrink dynamically.

Key Concepts of a Singly Linked List

Node → The fundamental unit containing data and a pointer to the next node.
Head → The starting node of the list.
Tail → The last node, which points to nullptr.

Operations:
Insert at the beginning.
Insert at the end.
Delete a node.
Traverse and display the list.

*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node* head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void insertAtBeginning(int value)
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value)
    {
        Node* newNode = new Node(value);
        if(!head)
        {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteNode(int value)
    {
        if(!head) return;

        if(head->data == value)
        {
            if(head->data == value)
            {
                Node* temp = head;
                head = head->next;
                delete temp;
                return;
            }

            Node* temp = head;
            while (temp->next && temp->next->data != value)
            {
                temp = temp->next;
            }

            if(temp->next)
            {
                Node* nodeToDelete = temp->next;
                temp->next = temp->next->next;
                delete nodeToDelete;
            }
        }
    }

    void display()
    {
        Node* temp = head;
        while(temp)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};

int main()
{
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtBeginning(5);
    
    cout << "Linked List after insertions: ";
    list.display();

    list.deleteNode(20);

    cout << "Linked List after deletion: ";
    list.display();

    return 0;
}