#include<bits/stdc++.h>
using namespace std;

class node{
     public:
    int data;
    node* next;

   
    node(int d){
        data = d;
        next = NULL;
    }
};

void insert(node* &head, int data){

    node* n = new node(data);

    if(head == NULL){
        head = n;
        return;
    }
    
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = n;

}

void display(node* head){
    node* temp = head;

    while(temp != NULL){
        cout<< temp->data<<", ";
        temp = temp->next;
    }
    cout<<endl<<endl;
}

node* revKNodes(node* &head, int k){

    node* prevptr = NULL;
    node*currptr = head;
    node* nextptr;

    int count = 0;

    while(currptr != NULL && count < k){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }
    
    if(nextptr != NULL){
    head->next = revKNodes(nextptr,k);
    }
    return prevptr;
}

int main(){
    node* head = NULL;

    insert(head,3);
    insert(head,39);
    insert(head,33);
    insert(head,38);
    insert(head,20);
    insert(head,5);
    insert(head,90);

    display(head);

    node* newHead = revKNodes(head,2);

    display(newHead); 
}