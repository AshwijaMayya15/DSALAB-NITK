#include <iostream>
#define MAX 5 // Maximum size of the stack

using namespace std;

struct StackUsingQueue {
    int queue[MAX];
    int front, rear, size;
    StackUsingQueue() {
        front = rear = -1;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == MAX;
    }

    // Push an element onto the stack
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << x << "\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }
        queue[rear] = x;
        size++;

        // Rotate elements to maintain stack order
        for (int i = 0; i < size - 1; i++) {
            int temp = queue[front];
            front = (front + 1) % MAX;
            rear = (rear + 1) % MAX;
            queue[rear] = temp;
        }
        cout << x << " pushed into stack." << endl;
    }

    // Pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return -1;
        }
        int topElement = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
        size--;
        return topElement;
    }

    // Get the top element of the stack
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return queue[front];
    }
};

int main() {
    StackUsingQueue stack;
    int choice, val;
    do {
        cout << "\nEnter your choice:\n";
        cout << "1. Push an element\n";
        cout << "2. Pop an element\n";
        cout << "3. Get top element\n";
        cout << "4. Check if stack is empty\n";
        cout << "5. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element: ";
                cin >> val;
                stack.push(val);
                break;

            case 2:
                val = stack.pop();
                if (val != -1)
                    cout << val << " popped from stack." << endl;
                break;
                
            case 3:
                cout << "Top element: " << stack.top() << endl;
                break;
                
            case 4:
                cout << (stack.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
                break;

            case 5:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    } while (choice != 5);

    return 0;
}
