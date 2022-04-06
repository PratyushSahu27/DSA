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

node* LCA(node* root,int n1 ,int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    node* leftLCA = LCA(root->left,n1,n2);
    node* rightLCA = LCA(root->right,n1,n2);

    if(leftLCA && rightLCA){
        return root;
    }
    if(leftLCA){
        return leftLCA;
    }
    return rightLCA;
}

int main(){
    node* root = new node(1);
        root->left = new node(2);
        root->right = new node(3);
        root->left->left = new node(4);
        root->right->left = new node(5);
        root->right->right = new node(6);
        root->right->left->left = new node(7);
        node* lca = LCA(root, 7, 6);
        cout<<"LCA = "<<lca->data<<endl;
        return 0;
}
