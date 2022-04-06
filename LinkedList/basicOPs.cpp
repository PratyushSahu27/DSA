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

bool search(node* head, int key){
    node* temp = head;
    while(temp != NULL){
        if(temp->data == key){
            return true;
        }
        temp = temp->next;
        
    }
    return false;

}

void deletion(node* &head, int key){
    if(head == NULL){
        return;
    }
    node* temp = head;

    if(temp->data==key){
        head = head->next;
        delete temp;
        return;
    }

    while(temp->next->data != key){
        temp = temp->next;
    }

    node* keyNode = temp->next;

    temp->next = temp->next->next;

    delete keyNode;
    
}

node* reverseIterative(node* &head){
    
    node* prev = NULL;
    node* curr = head;
    node* nextptr;

    


    while(curr != NULL){
        nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
        
    }

    return prev;
}

node* reverseRecursive(node* &head){

    if( head == NULL || head->next== NULL){
        return head;
    }
    node* newhead = reverseRecursive(head->next);
    head->next->next= head;
    head->next = NULL;

    return newhead;
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

    cout<<"Search of 78 : "<<search(head,78)<<endl;

    deletion(head,33);

    display(head);

    node* newHead = reverseRecursive(head);

    display(newHead);
}