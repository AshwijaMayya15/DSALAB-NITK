#include <iostream>
#define MAX 5 // Maximum size of the stack

using namespace std;

// Define the stack using a struct
struct CircularQueue {
    int arr[MAX]; // Array to store queue elements
    int front;
    int rear;// Index of the top element

    // Constructor to initialize the queue
    CircularQueue() {
        front = -1;
        rear = -1;
    }
    
    bool isEmpty() {
        if (front== -1 && rear == -1)
            return true;
        else
            return false;
    }
    
    bool isFull(){
        if ((rear+1) % MAX == front)
            return true;
        else
            return false;
    }

    // Function to push an element into the queue
    void push(int value) {
        if (isFull()){
            cout << "Queue Overflow! Cannot insert " << value << "\n";
            return;
        }
        else if (isEmpty())
            rear = front = 0;
        else
            rear = (rear + 1) % MAX;
        arr[rear]=value;
        cout << value << " Pushed into queue." << endl;
    }

    // Function to pop an element from the queue
    int pop() {
        int x;
        if(isEmpty()){
            cout << "Queue Underflow! Cannot pop.\n";
            return -1;
        }
        else if(front==rear)
        {
            x=arr[front];
            front=rear=-1;
        }
        else
        {
            x=arr[front];
            front = (front + 1) % MAX;
        }
        return x;
    }
    
    void PrintQueue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        int i = front;
        cout << "Queue elements: ";
        do {
            cout << arr[i] << " ";
            i = (i + 1) % MAX;
        } while (i != (rear + 1) % MAX);
        cout << endl;
    }
    
    void ReverseQueue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        int i = rear;
        cout << "Reversed queue elements: ";
        do {
            cout << arr[i] << " ";
            i = (i - 1 + MAX) % MAX;
        } while (i != (front - 1 + MAX) % MAX);
        cout << endl;
    }
    
    void WithoutDuplicates() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        int unique[MAX]; // To track unique elements
        int i=front,uniqueSize = 0; // No of unique elements found 
        cout << "Queue elements (without duplicates): ";
        do {
            // Check if arr[i] is already in unique array
            bool isDuplicate = false;
            for (int j = 0; j < uniqueSize; j++) {
                if (unique[j] == arr[i]) {
                    isDuplicate = true;
                    break;
                }
            }
            // If not found in unique array, print and add it
            if (!isDuplicate) {
                cout << arr[i] << " ";
                unique[uniqueSize++] = arr[i];
            }
            i = (i + 1) % MAX;
        } while (i != (rear + 1) % MAX);
        cout << endl;
    }
};

int main() {
    CircularQueue queue;
    int choice,val;
    // Basic operations
    do {
        cout << "\nEnter your choice:\n";
        cout << "1. Push an element\n";
        cout << "2. Pop an element\n";
        cout << "3. Print Queue\n";
        cout << "4. Reversing the Queue\n";
        cout << "5. Printing queue without duplicates\n";
        cout << "6. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element: ";
                cin >> val;
                queue.push(val);
                break;

            case 2:
                val = queue.pop();
                if (val != -1)
                    cout << val << " popped from queue." << endl;
                break;
                
            case 3:
                queue.PrintQueue();
                break;
                
            case 4:
                queue.ReverseQueue();
                break;
                
            case 5:
                queue.WithoutDuplicates();
                break;

            case 6:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    } while (choice != 6);

    return 0;
}