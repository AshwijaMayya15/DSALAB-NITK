// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};
Node* insert(Node* root,int key)
{
    if(root==nullptr)
        return new Node(key);
    if(key<root->data)
        root->left=insert(root->left,key);
    else if(key>root->data)
        root->right=insert(root->right,key);
    else
        cout<<"DUPLPICATE ELEMENT FOUND"<<endl;
    return root;
}
Node* findmin(Node* root){
    while(root->left!=nullptr)
        root=root->left;
    return root;
}
Node* deleten(Node* root,int val)
{
    if(root==nullptr)
    {
        cout<<"EMPTY"<<endl;
        return nullptr;
    }
    if(val<root->data)
        root->left=deleten(root->left,val);
    else if(val>root->data)
        root->right=deleten(root->right,val);
    else{
        if(root->left==nullptr)
        {
            Node* temp=root;
            temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right==nullptr)
        {
            Node* temp=root;
            temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node* succ = findmin(root->right);
            root->data = succ->data;
            root->right = deleten(root->right,succ->data);
        }
    }
    return root;
}
bool search(Node* root,int val)
{
    if(root==nullptr)
        return 0;
    if(root->data==val)
        return 1;
    else if(val < root->data)
        return search(root->left,val);
    else
        return search(root->right,val);
}
int max(Node* root)
{
    if(root==nullptr)
        return -1;
    while(root->right!=nullptr)
        root=root->right;
    return root->data;
}
int min(Node* root)
{
    if(root==nullptr)
        return -1;
    while(root->left!=nullptr)
        root=root->left;
    return root->data;
}
int height(Node* root)
{
    if(root==nullptr)
        return -1;
    int lr = height(root->left);
    int rl = height(root->right);
    return max(lr,rl)+1;
}
int countnodes(Node* root)
{
    if(root==nullptr)
        return 0;
    return countnodes(root->left)+countnodes(root->right)+1;
}
int countleafes(Node* root)
{
    if(root==nullptr)
        return 0;
    else if(root->left == nullptr && root->right==nullptr)
        return 1;
    else
        return countleafes(root->left)+countleafes(root->right);
}
void inorder(Node* root)
{
    if(root)
    {
        inorder(root->left);
        cout << root->data << "->";
        inorder(root->right);
    }
}
void gstconverter(Node* root,int &sum)
{
    if(root==nullptr)
        return;
    gstconverter(root->right,sum);
    sum = sum + root->data;
    root -> data = sum - root->data;
    gstconverter(root->left,sum);
    
}
void bsttogst(Node* root)
{
    int sum=0;
    gstconverter(root,sum);
}

int main() {
    Node* root = nullptr;

    // Insert elements
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 2);
    root = insert(root, 7);

    // Display Inorder Traversal
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << "NULL" << endl;
    bsttogst(root);

    cout << "Inorder after converting to GST: ";
    inorder(root);
    cout << "NULL" << endl;
    
    root = deleten(root, 10);

    // Inorder after deletion
    cout << "Inorder Traversal after deleting root: ";
    inorder(root);
    cout << "NULL" << endl;

    cout << "Height of tree: " << height(root) << endl;
    cout << "Max value: " << max(root) << endl;
    cout << "Min value: " << min(root) << endl;
    cout << "Total nodes: " << countnodes(root) << endl;
    cout << "Leaf nodes: " << countleafes(root) << endl;

    return 0;
}