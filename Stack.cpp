/*

A Stack follows the LIFO (Last In, First Out) principle. 
The most recently added element is removed first.

Stack Operations

push(value) → Insert element at the top.
pop() → Remove element from the top.
peek() → Get the top element without removing it.
isEmpty() → Check if stack is empty.

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

class Stack
{
private:
    Node* top;

public:
    Stack() { top = nullptr; }

    void push(int value)
    {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if(!top)
        {
            cout << "Stack undeflow \n" << endl;
            return;
        }
        
        Node* temp = top;
        top - top->next;
        delete temp;
    }

    int peek()
    {
        if(!top)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty()
    {
        return top = nullptr;
    }

    void display()
    {
        Node* temp = top;
        cout << "Stack (Top to Bottom): ";
        while (temp)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }

        cout << "nullptr" << endl;
    }
};


int main() 
{
    Stack myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.display();

    cout << "Top Element: " << myStack.peek() << endl;
    myStack.pop();
    myStack.display();

    return 0;
}