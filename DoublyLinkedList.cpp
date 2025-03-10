/*

Doubly Linked List (DLL) Implementation in C++
A Doubly Linked List (DLL) is a linear data structure where each node contains:

Data
Pointer to the next node (next)
Pointer to the previous node (prev)
This allows traversal in both directions (forward and backward).

Doubly Linked List Advantages:

Bidirectional traversal (forward & backward).
Efficient deletion as nodes store previous pointers.
Better for complex data structures like LRU Cache.

*/


#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value)
    {
        data = value;
        next = prev = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList()
    {
        head = tail = nullptr;
    }

    void insertAtHead(int value)
    {
        Node* newNode = new Node(value);
        if(!head)
        {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtTail(int value)
    {
        Node* newNode = new Node(value);
        if(!tail)
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void deleteNode(int value)
    {
        if(!head) return;

        Node* temp = head;
        while (temp && temp->data != value)
            temp = temp->next;

        if(!temp) return;

        if(temp == head) head = temp->next;
        if(temp == tail) tail = temp->prev;

        if (temp->prev) temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;

        delete temp;
    }

    void displayForward()
    {
        Node* temp = head; 
        cout << "DLL Forward:";
        while (temp)
        {
            cout <<temp->data << "->";
            temp = temp->next;
        }
        cout << "nullptr" <<endl;
    }

    void displayBackward()
    {
        Node* temp = tail;
        cout << "DLL Backward: ";
        while (temp)
        {
            cout << temp->data << "->";
            temp = temp->prev;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    // Insert elements
    dll.insertAtHead(10);
    dll.insertAtHead(20);
    dll.insertAtTail(30);
    dll.insertAtTail(40);

    dll.displayForward();
    dll.displayBackward();

    // Delete a node
    dll.deleteNode(30);
    dll.displayForward();

    return 0;
}