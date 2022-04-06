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

void topView(Node* root){
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
        
        if(m.count(hd) == 0){
            m.insert({hd,temp->data});
        }
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
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    topView(root);
    cout<<endl;
}
