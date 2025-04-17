#include <iostream>
#define MAX 100

using namespace std;

struct Queue {
    int arr[MAX];
    int front;
    int rear;

    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = value;
        cout << value << " enqueued into queue." << endl;
    }

    int dequeue(bool silent = false) {
        if (isEmpty()) {
            if (!silent) cout << "Queue Underflow!" << endl;
            return -1;
        }
        int removed = arr[front++];
        if (front > rear) {
            front = -1;
            rear = -1;
        }
        if (!silent) cout << removed << " dequeued from queue." << endl;
        return removed;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

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

    void displayReverse() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements in reverse: ";
        for (int i = rear; i >= front; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void reverseQueue() {
        if (isEmpty()) return;

        int data = dequeue(true); // Dequeue silently
        reverseQueue();
        enqueue(data); // Reuse enqueue to maintain consistency
    }

    void displayWithoutDuplicates() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements (without duplicates): ";
        int unique[MAX];
        int uniqueSize = 0;

        for (int i = front; i <= rear; i++) {
            bool isDuplicate = false;
            for (int j = 0; j < uniqueSize; j++) {
                if (arr[i] == unique[j]) {
                    isDuplicate = true;
                    break;
                }
            }
            if (!isDuplicate) {
                cout << arr[i] << " ";
                unique[uniqueSize++] = arr[i];
            }
        }
        cout << endl;
    }
};

int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(20);
    queue.enqueue(10);
    queue.enqueue(40);

    cout << "\nBefore reversing:" << endl;
    queue.display();
    queue.displayReverse();

    cout << "\nQueue without duplicates:" << endl;
    queue.displayWithoutDuplicates();

    queue.reverseQueue();

    cout << "\nAfter reversing:" << endl;
    queue.display();
}

