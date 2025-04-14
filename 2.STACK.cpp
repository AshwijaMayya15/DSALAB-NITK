#include <iostream>
#define MAX 100
using namespace std;

struct Stack {
    int arr[MAX];
    int top;

    Stack() {
        top = -1;
    }

    void push(int val) {
        if (top == MAX - 1) {
            cout << "STACK OVERFLOW" << endl;
            return;
        }
        arr[++top] = val;
    }

    bool isempty() {
        return top == -1;
    }

    int pop() {
        if (isempty()) {
            cout << "STACK UNDERFLOW" << endl;
            return -1;
        }
        return arr[top--];
    }

    void printStack() {
        if (isempty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >=0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }

    void insertAtBottom(int val) {
        if (isempty()) {
            push(val);
        } else {
            int temp = pop();
            insertAtBottom(val);
            push(temp);
        }
    }

    // Recursive reverse
    void reverse() {
        if (!isempty()) {
            int temp = pop();
            reverse();
            insertAtBottom(temp);
        }
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);

    cout << "Original Stack:" << endl;
    stack.printStack();

    stack.reverse();  // Reversing the stack using the method inside the struct

    cout << "Reversed Stack:" << endl;
    stack.printStack();

    return 0;
}

