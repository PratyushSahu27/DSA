#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    int hd;
    Node* left;
    Node* right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};
bool searchKey(Node* root, int key){
    if(root==NULL){
        return false;
    }
    if(root->data == key)
        return true;
    
    else if(root->data > key)
        return searchKey(root->left,key);
    return searchKey(root->right,key);
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(7);
    root->right = new Node(14);
    root->left->left = new Node(6);
    root->left->right = new Node(8);
    root->right->left = new Node(11);
    root->right->right = new Node(16);
    bool search = searchKey(root,6);
    if(search)
        cout << "6 is present in tree" << endl;
    else
        cout << "6 is absent from tree" << endl;
    search = searchKey(root,9);
    if(search)
        cout << "9 is present in tree" << endl;
    else
        cout << "9 is absent from tree" << endl;
return 0;
}