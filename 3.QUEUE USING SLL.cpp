#include <iostream>
using namespace std;

// Node structure for stack
struct Node {
    int data;
    Node* next;
};

// Stack structure using linked list
struct Queue {
    Node* front;
    Node* rear;
    
    Queue() { 
        front = nullptr;
        rear = nullptr; 
    }
    
    // Push operation
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        if(rear == nullptr)
            front=rear=newNode;
        rear->next = newNode;
        rear = newNode;
        cout << "Pushed " << value << " onto the queue.\n";
    }
    
    // Pop operation
    void pop() {
        if (front == nullptr) {
            cout << "Queue underflow! Cannot pop from an empty queue.\n";
            return;
        }
        Node* temp = front;
        cout << "Popped " << temp->data << " from the queue.\n";
        front = front->next;
        if(front==nullptr) rear=nullptr;
        delete temp;
    }
    
    // Display stack
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }
        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    Queue queue;
    int choice, value;
    do {
        cout << "\nQueue Operations:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                queue.push(value);
                break;
            case 2:
                queue.pop(); break;
            case 3:
                queue.display(); break;
            case 4:
                cout << "Exiting...\n"; break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);
    return 0;
}