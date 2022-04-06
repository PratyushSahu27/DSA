#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdint.h>

int *hash;
struct node{
    int data;
    struct node *next;
}*head=NULL;
void insert(struct node *first,int x)
{
    struct node *p=first,*q;
    if(hash[x]==0)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data=x;
        temp->next=NULL;
        hash[x]=1;
        if(head==NULL)
        {
            head=temp;
            return;
        }
        while(p && temp->data>p->data)
        {
            q=p;
            p=p->next;
        }
        if(p==head)
        {
            temp->next=head;
            head=temp;
            return;
        }
        temp->next=q->next;
        q->next=temp;
    }
    else{
       printf("Value Aldready Exist can not be inserted\n");
       return;
    }
}
int size(struct node *first)
{
    int count = 0;
    struct node *p=first;
    while(p)
    {
        p=p->next;
        count++;
    }
    return count;
}
void delete(struct node *first)
{
    struct node*p=first,*q;
    int count= size(first);
    if(count==0)
    {
        printf("Set is Empty\n");
        return;
    }
    for(int i=0;p && i<(count/2);i++)
    {
        q=p;
        p=p->next;
        hash[q->data]=0;
        q->next=NULL;
        free(q);
    }
    head=p;
}
void display(struct node *first)
{
    struct node *p=first;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main()
{
    hash=(int *)malloc(1001*sizeof(int));
    for(int i=0;i<1001;i++)
    {
        hash[i]=0;   
    }
    int mood=1,n,x;
    while(mood)
    {
        printf("Options:-\n");
        printf("1.Insert An Item in Set\n");
        printf("2.Remove n/2 Smallest Items from Set\n");
        printf("3.Display Set\n");
        printf("4.Exit\n");
        printf("\nEnter Your Choice:- ");
        scanf("%d",&n);
        switch(n){
            case 1:
                printf("Enter Item to be inserted in Set between 0 and 1000: ");
                scanf("%d",&x);
                insert(head,x);
                break;
            
            case 2:
                delete(head);
                printf("After removing Elements Set:- \n");
                display(head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                mood=0;
                break;
            default:
                printf("Invalid Input Please Try Again\n");
                break;
        }
    }
    free(hash);
    return 0;
}