#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void insertf(Node*& head, int val) {
    Node* n = new Node();
    n->data = val;
    n->next = head;
    n->prev = nullptr;
    if (head != nullptr) {
        head->prev = n;
    }
    head = n;
}

void inserte(Node*& head, int val) {
    Node* n = new Node();
    n->data = val;
    n->next = nullptr;
    if (head == nullptr) {
        n->prev = nullptr;
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void insertib(Node*& head, int val, int pos) {
    if (pos == 1) {
        insertf(head, val);
        return;
    }
    Node* n = new Node();
    n->data = val;
    Node* temp = head;
    for (int i = 1; temp != nullptr && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "POS OUT OF BOUND" << endl;
        return;
    }
    n->next = temp->next;
    n->prev = temp;
    if (temp->next != nullptr) {
        temp->next->prev = n;
    }
    temp->next = n;
}

int deletef(Node*& head) {
    if (head == nullptr) {
        cout << "LIST EMPTY" << endl;
        return -1;
    }
    Node* temp = head;
    int element = head->data;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
    return element;
}

int deletel(Node*& head) {
    if (head == nullptr) {
        cout << "LIST EMPTY" << endl;
        return -1;
    }
    if (head->next == nullptr) {
        int element = head->data;
        delete head;
        head = nullptr;
        return element;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    int val = temp->data;
    temp->prev->next = nullptr;
    delete temp;
    return val;
}

void deleteib(Node*& head, int val) {
    if (head == nullptr) {
        cout << "LIST EMPTY" << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr && temp->data != val) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Value not found" << endl;
        return;
    }
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }
    cout << "Deleted element: " << temp->data << endl;
    delete temp;
}

void display(Node*& head) {
    if (head == nullptr) {
        cout << "List IS EMPTY" << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;
    int choice, val, pos;
    do {
        cout << "\nEnter your choice:\n";
        cout << "1. Inserting in the Beginning\n";
        cout << "2. Inserting in the End\n";
        cout << "3. Inserting in Between\n";
        cout << "4. Deletion at the Beginning\n";
        cout << "5. Deletion at the End\n";
        cout << "6. Deletion in Between\n";
        cout << "7. Display the Linked List\n";
        cout << "8. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the element: ";
                cin >> val;
                insertf(head, val);
                break;
            case 2:
                cout << "Enter the element: ";
                cin >> val;
                inserte(head, val);
                break;
            case 3:
                cout << "Enter element and the position to be inserted: ";
                cin >> val >> pos;
                insertib(head, val, pos);
                break;
            case 4:
                cout << "Deleted first element: " << deletef(head) << endl;
                break;
            case 5:
                cout << "Deleted last element: " << deletel(head) << endl;
                break;
            case 6:
                cout << "Enter value to delete: ";
                cin >> val;
                deleteib(head, val);
                break;
            case 7:
                cout << "Display the Linked list:" << endl;
                display(head);
                break;
            case 8:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    } while (choice != 8);
    return 0;
}
