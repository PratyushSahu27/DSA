//building tree from inorder and preorder

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
int getIndex(vector<int> v, int K)
{
    for(int i = 0; i < v.size(); i++){
        if(v[i] == K){
            return i;
        }
    }
    return -1;
}

node* buildTree(vector<int> inorder, vector<int> preorder, int start, int end){
    if(start>end){
        return nullptr;
    }
    static int idx = 0;
    int curr = preorder[idx];
    idx++;
    node* root = new node(curr);
    if(start == end){
        return root;
    }
    int pos = getIndex(inorder, curr);
    root->left = buildTree(inorder, preorder, start, pos-1);
    root->right = buildTree(inorder, preorder, pos+1, end);
    return root;
}

void inorderTree(node* root){
    if(root==nullptr){
        return;
    }
    
    inorderTree(root->left);
    cout<< root->data<<" ";
    inorderTree(root->right);
}

int main(){
    vector<int> inorder {4,2,1,5,3};
    vector<int> preorder {1,2,4,3,5};
    node* root = buildTree(inorder, preorder, 0,4);
    inorderTree(root);
    return 0;
}
