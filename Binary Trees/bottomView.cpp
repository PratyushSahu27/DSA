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

void bottomView(Node* root){
    vector<int> ans;
    queue<Node*> q;
    map<int,int> m;
    int hd = 0;
    root->hd = hd;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        hd = temp->hd;
        if(m.count(hd) == 0)
            m.insert({hd,temp->data});
        else
            m[hd] = temp->data;
        
        if(temp->left){
            temp->left->hd = hd-1;
            q.push(temp->left);
        }
        if(temp->right){
            temp->right->hd = hd+1;
            q.push(temp->right);
        }
    }
    for(auto itr : m){
        cout << itr.second<< " ";
    }
}

int main(){
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right->right = new Node(25);
    bottomView(root);
    cout<<endl;
}
