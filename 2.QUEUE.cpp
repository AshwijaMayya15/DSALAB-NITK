#include <iostream>
#define MAX 100 // Maximum size of the queue

using namespace std;

// Define the queue using a struct
struct Queue {
    int arr[MAX]; // Array to store queue elements
    int front;    // Index of the front element
    int rear;     // Index of the rear element

    // Constructor to initialize the queue
    Queue() {
        front = -1;
        rear = -1;
    }

    // Function to enqueue an element into the queue
    void enqueue(int value) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        if (front == -1) front = 0; // First element
        arr[++rear] = value;
        cout << value << " enqueued into queue." << endl;
    }

    // Function to dequeue an element from the queue (optional silent mode)
    int dequeue(bool silent = false) {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        int removed = arr[front++];

        // Reset queue when empty
        if (front > rear) {
            front = -1;
            rear = -1;
        }

        if (!silent)
            cout << removed << " dequeued from queue." << endl;

        return removed;
    }

    // Function to peek the front element of the queue
    int peek() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1 || front > rear;
    }

    // Function to display the queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Function to reverse the queue using recursion
    void reverseQueue() {
        if (isEmpty()) return;

        int data = dequeue(true); // Silent mode
        reverseQueue();
        if (front == -1)
            front =0;
        arr[++rear]=data;
    }
};

int main() {
    Queue queue;

    // Basic operations
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    cout << "Before reversing:" << endl;
    queue.display();

    queue.reverseQueue();

    cout << "After reversing:" << endl;
    queue.display();

    return 0;
}
