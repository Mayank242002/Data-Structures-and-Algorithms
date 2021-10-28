#include<stdio.h>
#include<stdlib.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
};


struct Node * insert_at_RHS(struct Node *tail,int n)
{
    struct Node *p=NULL;
    p=(struct Node *)malloc(sizeof(struct Node));
    p->data=n;
    if (tail==NULL)
    {
       tail=p;
       tail->prev=NULL;
    }
    else{
        tail->next=p;
        p->prev=tail;
        tail=p;
    }
    tail->next=NULL;
    return tail;
}

struct Node * insert_at_LHS(struct Node *head,int n)
{
    struct Node *p=NULL;
    p=(struct Node *)malloc(sizeof(struct Node));
    p->data=n;
    if (head==NULL)
    {
       head=p;
       head->next=NULL;
    }
    else{
       p->next=head;
       head->prev=p;
       head=p;
    }
    head->prev=NULL;
    return head;
}

void Display(struct Node *p)
{
    while (p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

int main()
{
    struct Node *head=NULL,*tail=NULL;
    int n;
    int choice;
    do{
        printf("Enter your choice\n 1.Add at RHS\n 2.ADD at LHS\n 3.Display\n 4.Exit\n");
        scanf("%d",&choice);
        if (choice==1)
        {
           printf("enter elements to add to the Double Linked list and 0 to stop inserting at RHS:");
           scanf("%d",&n);
           tail=insert_at_RHS(tail,n);
          if (head==NULL)
                head=tail;
        }
        else if (choice==2)
        {
           printf("enter elements to add to the Double Linked list and 0 to stop inserting at LHS:");
           scanf("%d",&n);
           head=insert_at_LHS(head,n);
           if (tail==NULL)
                tail=head;
        }
        else if (choice==3)
        {
            Display(head);
        }
        else
           break;

    }while (choice!=4);
}