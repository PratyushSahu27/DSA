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

void rightViewOfTree(node* root){
     
     queue<node*> q;
     q.push(root);

     while(!q.empty()){
         if(root == NULL){
             return;
         }
         int n = q.size();
         for (int i = 0; i < n; i++)
         {
             node* temp = q.front();
             q.pop();
             if(i == n-1){
                 cout<<temp->data<<"  ";
             }
             if(temp->left){
                 q.push(temp->left);
             }
            if(temp->right){
                 q.push(temp->right);
             }

         }
         
     }
}
int main(){
     node* root = new node(1);
        root->left = new node(2);
        root->right = new node(3);
        root->left->left = new node(4);
        root->left->right = new node(5);
        root->right->left = new node(6);
        root->right->right = new node(7);
        rightViewOfTree(root);
        return 0;
}