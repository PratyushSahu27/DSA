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
void printLeftBoundary(Node* root){
        if(root==NULL){
            return;
        }
        if(root->left){
            cout << (root->data) << " ";
            printLeftBoundary(root->left);
        }
        else if(root->right){
            cout << (root->data) << " ";
            printLeftBoundary(root->right);
        }
        
    }
void printRightBoundary(Node* root){
    if(root==NULL){
        return;
    }
    if(root->right){
        printLeftBoundary(root->right);
        cout << (root->data) << " ";
    }
    
    else if(root->left){
        printLeftBoundary(root->left);
        cout << (root->data) << " ";
    } 
}

void printLeaves(Node* root){
    if(root==NULL){
        return;
    }
    printLeaves(root->left);
    
    if(!root->left && !root->right)
        cout << (root->data) << " ";
        
    printLeaves(root->right);
    
}

void printBoundary(Node *root)
{
    if(root==nullptr)
        return;
    cout << (root->data) << " ";
    printLeftBoundary(root->left);
    
    printLeaves(root->left);
    printLeaves(root->right);
    
    printRightBoundary(root->right);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);
    printBoundary(root);
    
    
       
}