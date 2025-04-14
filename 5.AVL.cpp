// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    int height;
   
    Node(int val)
    {
        data = val;
        left = right = nullptr;
        height = 0;
    }
};
int getheight(Node* root)
{
    if(root == nullptr)
        return -1;
    int lr = getheight(root->left);
    int rl = getheight(root->right);
    return max(lr,rl)+1;
}
int balancefactor(Node* root)
{
    if(root == nullptr)
        return 0;
    else
        return getheight(root->left) - getheight(root->right);
}
Node* leftrotate(Node* z)
{
    Node* y = z->right;
    Node* t2 = y->left;
   
    y->left = z;
    z->right = t2;
   
    z->height = getheight(z);
    y->height = getheight(y);
    return y;
}
Node* rightrotate(Node* z)
{
    Node* y = z->left;
    Node* t2 = y->right;
   
    y->right = z;
    z->left = t2;
   
    z->height = getheight(z);
    y->height = getheight(y);
    return y;
}
Node* rebalance(Node* root)
{
    if (root==nullptr)
        return 0;
    root->height = getheight(root);
    int bf = balancefactor(root);
    if (bf > 1 && balancefactor(root->left)>=0)
        return rightrotate(root);
    if (bf < -1 && balancefactor(root->right)<=0)
        return leftrotate(root);
    if (bf > 1 && balancefactor(root->left)<=0)
    {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    if (bf < -1 && balancefactor(root->right)>=0)
    {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
}
Node* insert(Node* root,int val)
{
    if(root==nullptr)
        return new Node(val);
    if (val < root->data)
        root->left = insert(root->left,val);
    else if(val > root->data)
        root->right = insert(root->right,val);
    else
        return root;
    return rebalance(root);
}
Node* findmin(Node* z)
{
    while(z->left!=nullptr)
        z = z->left;
    return z;
}
Node* deletenode(Node* root,int val)
{
    if (root==nullptr)
        return root;
    if (val < root->data)
        root->left = deletenode(root->left,val);
    else if(val > root->data)
        root->right = deletenode(root->right,val);
    else
        if(root->left==nullptr)
        {
            Node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==nullptr)
        {
            Node* temp=root->left;
            delete root;
            return temp;
        }
        else
        {
            Node* successor = findmin(root->right);
            root->data = successor->data;
            root->right = deletenode(root->right,successor->data);
        }
        return rebalance(root);
}
void preorder(Node* root)
{
    if(root==nullptr)
        return;
    if(root)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
int count(Node* root)
{
    if(root == nullptr)
        return 0;
    return 1 + count(root->left) + count(root->right);
}
int countleaves(Node* root)
{
    if(root==nullptr)
        return 0;
    else if(root->left==nullptr && root->right == nullptr)
        return 1;
    else
        return countleaves(root->left) + countleaves(root->right);
}
int findmaximumvalue(Node* root){
    if (root==nullptr)
        return -1;
    while (root->right!=nullptr)
        root=root->right;
    return root->data;
}
int findminimumvalue(Node* root){
    if (root==nullptr)
        return -1;
    while (root->left!=nullptr)
        root=root->left;
    return root->data;
}
int main()
{
    Node* root = nullptr;
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 6);
    root = insert(root, 9);
    root = insert(root, 16);
    root = insert(root, 15);
   
    cout<<"Preorder Traversal"<<endl;
    preorder(root);
    cout<<endl;
    cout << "\n";
   
    root = deletenode(root,7);
   
    cout<<"Preorder Traversal after deletion"<<endl;
    preorder(root);
    cout<<endl;
    cout << "\n";
   
    cout<<"Total number of Nodes: "<< count(root) << endl;
    cout << "\n";
    cout<<"Total number of leaves: "<< countleaves(root) << endl;
    cout << "\n";
    cout<<"Total number of internal nodes: " << count(root) - countleaves(root) <<endl;
    cout << "\n";
    cout<<"Minimum value in the avl tree: " << findminimumvalue(root) << endl;
    cout << "\n";
    cout<<"Maximum value in the avl tree: " << findmaximumvalue(root) << endl;
    cout << "\n";
    
    return 0;
}