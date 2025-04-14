#include <iostream>
using namespace std;

// Node structure for stack
struct Node {
    int data;
    Node* next;
};

// Stack structure using linked list
struct Stack {
    Node* top;
    
    Stack() { top = nullptr; }
    
    // Push operation
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << "Pushed " << value << " onto the stack.\n";
    }
    
    // Pop operation
    void pop() {
        if (top == nullptr) {
            cout << "Stack underflow! Cannot pop from an empty stack.\n";
            return;
        }
        Node* temp = top;
        cout << "Popped " << temp->data << " from the stack.\n";
        top = top->next;
        delete temp;
    }
    
    // Display stack
    void display() {
        if (top == nullptr) {
            cout << "Stack is empty.\n";
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    Stack stack;
    int choice, value;
    do {
        cout << "\nStack Operations:\n";
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
                stack.push(value);
                break;
            case 2:
                stack.pop(); break;
            case 3:
                stack.display(); break;
            case 4:
                cout << "Exiting...\n"; break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);
    return 0;
}
