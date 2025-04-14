#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
void insertf(Node*& head, int val)
{
    Node* n=new Node();
    n->data = val;
    n->next = head;
    head = n;
}
void inserte(Node*& head,int val)
{
    Node* n=new Node();
    n->data=val;
    n->next=nullptr;
    if (head == nullptr){
        head = n;
        return;
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp -> next;
    }
    temp -> next = n;
}
void insertib(Node*& head, int val,int pos){
    if(pos == 1){
        insertf(head,val);
        return;
    }
    Node* n=new Node();
    n->data=val;
    Node* temp=head;
    for(int i=1;temp!=nullptr && i<pos-1;i++){
        temp=temp->next;
    }
    if (temp==nullptr){
        cout<<"POS OUT OF BOUND"<<endl;
        return;
    }
    n->next = temp->next;
    temp->next =n;
}
int deletef(Node*& head){
    if (head==nullptr){
        cout<<"LIST EMPTY"<<endl;
        return -1;
    }
    Node* temp=head;
    int element = head -> data; 
    head = head->next;
    delete temp;
    return element;
}
int deletel(Node*& head){
    if (head==nullptr){
        cout << "LIST EMPTY" << endl;
        return -1;
    }
    if (head->next==nullptr){
        int element = head -> data;
        delete head;
        head = nullptr;
        return element;
    }
    Node* temp=head;
    while(temp->next->next != nullptr){
        temp=temp->next;
    }
    int val = temp->data;
    delete temp->next;
    temp->next=nullptr;
    return val;
}
void deleteib(Node*& head,int val){
    if (head==nullptr){
        cout<<" LIST EMPTY "<<endl;
        return;
    }
    if (head->data==val){
        cout << "Deleted element: " << deletef(head) << endl;
        return;
    }
    Node* temp = head;
    while(temp->next!=nullptr && temp->next->data != val){
        temp=temp->next;
    }
    if(temp->next == nullptr){
        cout<<"Value not found"<<endl;
        return;
    }
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    cout << "Deleted element: " << delNode->data << endl;
    delete delNode;
}
void display(Node*& head){
    if (head==nullptr){
        cout<<"List IS EMPTY"<<endl;
        return;
    }
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<< " - > ";
        temp = temp->next;
    }
    cout << "NULL"<<endl;
}
int search(Node*& head, int val){
    if (head==nullptr){
        cout<<"List is empty"<<endl;
        return -1;
    }
    Node* temp=head;
    int pos = 1;
    while(temp!=nullptr){
        if (temp->data == val){
            return pos;
        }
        temp = temp -> next;
        pos = pos+1;
    }
    return -1;
}
void remallocc(Node*& head,int key){
    if (head!=nullptr && head->data==key){
        Node* temp = head;
        head = head->next;
        cout << "Deleted element: " << temp->data << endl;
        delete temp;
    }
    if (head==nullptr){
        cout<<"List is empty";
        return;
    }
    Node* temp=head;
    while(temp->next!=nullptr){
        if(temp->next->data==key){
            temp->next=temp->next->next;
        }else{
            temp=temp->next;
        }
    }
}
int countofnodes(Node*& head){
    int count=0;
    if (head==nullptr){
        cout<<"Linked list is empty"<<endl;
        return count;
    }
    Node* temp = head;
    while(temp!=nullptr){
        temp=temp->next;
        count+=1;
    }
    return count;
}
int getMiddle(Node* head) {
    if (head == nullptr){
        cout << "List is empty" << endl;
        return -1;  // Handle empty list case
    }
    int length = countofnodes(head);
    int mid_index = length / 2;
    while (mid_index--) {
        head = head->next;
    }
    return head->data;
}
int main() {
    // Write C++ code here
    Node* head = nullptr;
    int choice,val,pos,seele;
    do {
        cout << "\nEnter your choice:\n";
        cout << "1. Inserting in the Begining\n";
        cout << "2. Inserting in the End\n";
        cout << "3. Inserting in between\n";
        cout << "4. Deletion at the Begining\n";
        cout << "5. Deletion in the End\n";
        cout << "6. Deletion in between\n";
        cout << "7. Display the linked list\n";
        cout << "8. Searching an Element\n";
        cout << "9. Deleting all occurances of an element\n";
        cout << "10. Counting number of nodes in the linked list\n";
        cout << "11. Print the middle element in the linked list\n";
        cout << "12. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the element: " << endl;
                cin >> val;
                insertf(head,val);
                break;

            case 2:
                cout << "Enter the element: " << endl;
                cin >> val;
                inserte(head,val);
                break;
            
            case 3:
                cout << "Enter element and the position to be inserted: " << endl;
                cin >> val >> pos;
                insertib(head,val,pos);
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
                cout << "Display the Linked list:"<<endl;
                display(head);
                break;
                
            case 8:
                cout << "Enter value to search" << endl;
                cin >> val;
                seele = search(head,val);
                if (seele != -1)
                    cout << "Element found at pos " << seele << " in the linked list " << endl;
                else
                    cout << "Element not found" << endl;
                break;
                
            case 9:
                cout << "Deleting all occurances of element" << endl;
                cin >> val;
                remallocc(head,val);
                break;
            
            case 10:
                cout << "Total nodes: " << countofnodes(head) << endl;
                break;
                
            case 11:
                val = getMiddle(head);
                if (val != -1)
                    cout << "Middle element: " << val << endl;
                break;

            case 12:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    } while (choice != 12);
    return 0;
}

