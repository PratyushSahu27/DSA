#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* right;
    node* left;

    node(int a){
        data = a;
        right = nullptr;
        left =nullptr;  
    }
};
void inorderTree(node* root){
    if(root==nullptr){
        return;
    }
    
    inorderTree(root->left);
    cout<< root->data<<" ";
    inorderTree(root->right);
}

void printLvlOrder(node* root){
    if(root==nullptr){
        return;
    }

    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp != nullptr){
            cout<<temp->data<<" ";
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
        } 
        else if(!q.empty())
            q.push(NULL);  
    }

}

int32_t main(){
        node* root = new node(1);
        root->left = new node(2);
        root->right = new node(3);
        root->left->left = new node(4);
        root->left->right = new node(5);
        root->right->left = new node(6);
        root->right->right = new node(7);
        printLvlOrder(root);
        return 0;
}