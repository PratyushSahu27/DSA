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

void diagonalPrint(Node* root, int d, map<int, vector<int>> &diagonal){
    if(root == NULL){
        return;
    }
    diagonal[d].push_back(root->data);
    diagonalPrint(root->left,d+1,diagonal);
    diagonalPrint(root->right,d,diagonal);

}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    map<int,vector<int>>diagonal;
    diagonalPrint(root,0,diagonal);
    for(auto i:diagonal){
        vector<int>ans = i.second;
        for(auto j : ans){
            cout << j << " ";
        }
        cout << endl;
    }
    cout<<endl;
}
