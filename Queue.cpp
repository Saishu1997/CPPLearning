/*

A Queue follows the FIFO (First In, First Out) principle. The oldest element is removed first.

Queue Operations

enqueue(value) → Insert element at the rear.
dequeue() → Remove element from the front.
front() → Get the first element without removing it.
isEmpty() → Check if queue is empty.

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
    

class Queue
{
private:
    Node* front;
    Node* rear;

public:
    Queue()
    {
        front = rear = nullptr;
    }

    void enqueue(int value)
    {
        Node* newNode = new Node(value);
        if(!rear)
        {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue()
    {
        if(!front)
        {
            cout << "Queue Underflow!" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if(!front)
        {
            rear = nullptr;
        }
        delete temp;
    }

    int getFront()
    {
        if(!front)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    void display()
    {
        Node* temp = front;
        cout << "Queue (Front to Rear): ";
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
    Queue myQueue;
    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.display();

    cout << "Front Element: " << myQueue.getFront() << endl;
    myQueue.dequeue();
    myQueue.display();

    return 0;
}