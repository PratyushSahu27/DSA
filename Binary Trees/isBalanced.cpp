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

int max(int a,int b){
    return (a>=b?a:b);
}
int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh,rh)+1;
}
bool isBalanced(Node *root)
{
    if(root==NULL){
        return true;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    
    if(abs(lh-rh)<=1 && isBalanced(root->left)&& isBalanced(root->right))
        return true;
    return false;
    
}