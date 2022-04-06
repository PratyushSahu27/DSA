
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

vector <int> zigZagTraversal(Node* root)
{
	vector <int> ans;
	stack<Node*> currlvl, nextlvl;
	bool leftToRight = true;
	currlvl.push(root);
	while(!currlvl.empty()){
	    Node* temp = currlvl.top();
	    currlvl.pop();
	    if(temp!=NULL){
	        ans.push_back(temp->data);
	        if(leftToRight){
	            if(temp->left)
	                nextlvl.push(temp->left);
	            if(temp->right)
	                nextlvl.push(temp->right);
            }
	         else{
	            if(temp->right)
	                nextlvl.push(temp->right);
                if(temp->left)
	                nextlvl.push(temp->left);
            }   
	    }
	    if(currlvl.empty()){
	        leftToRight = !leftToRight;
	        swap(currlvl, nextlvl);
	    }
    }
	return ans;
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
    vector<int> ans = zigZagTraversal(root);
    for(auto i: ans)
        cout << i << " ";
    cout<<endl;
}