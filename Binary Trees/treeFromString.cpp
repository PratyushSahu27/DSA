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

void preOrder(node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}
int getIndex(string s, int start, int end){
    stack<char> st;
    for(int i = start; i <= end; i++){
        if(s[i] == '(')
            st.push('(');
        else if(s[i] == ')'){
            if(st.top() == '('){
                st.pop();
                if(st.empty())
                    return i;
            }
        }
    }
    return -1;
}

node* buildTreeFromString(string s,int start, int end){
    if(start > end)
        return NULL;
    
    node* root = new node(s[start] - '0');
    int index = -1;
    if(start+1 <=end && s[start+1] == '('){
        index = getIndex(s,start+1,end);
    }
    if(index!=-1){
        root->left = buildTreeFromString(s,start+2,index);
        root->right = buildTreeFromString(s,index+2,end);
    }
    return root;
}
int main()
{
    string s = "4(2(3)(1))(6(5))";
    int n = s.size();
    node* root = buildTreeFromString(s,0,n-1);

    preOrder(root);
return 0;
}