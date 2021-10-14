#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node * create(struct Node *last,int n)
{
    struct Node *p=NULL;
    p=(struct Node *)malloc(sizeof(struct Node));
    if (p!=NULL)
    {
        p->data=n;
        if (last==NULL)
        {
            last=p;
            last->next=last;
        }
        else
        {
            p->next=last->next;
            last->next=p;
            last=p;
        }
        return last;
    }
    else
    {
        printf("not enough memory");
    }
}



void display(struct Node *first)
{
    struct Node *p=first;
    do{
        printf("%d ",first->data);
        first=first->next;
    }while (first!=p);
}

struct Node * insert(struct Node *last)
{
    struct Node *p=NULL,*t=NULL;
    t=last->next;
    p=(struct Node *)malloc(sizeof(struct Node));
    int pos,n;
    printf("enter the position where you want to insert and data you want to insert:");
    scanf("%d %d",&pos,&n);
    p->data=n;
    if (pos==0)
    {
        if (last==NULL)
        {
            last=p;
            last->next=last;
        }
        else
        {
            p->next=last->next;
            last->next=p;
        }
    }
    else
    {
        
        for (int i=0;i<pos-1;i++)
            t=t->next;
            
        p->next=t->next;
        t->next=p;
        if (t==last)
        {
         last=p;   
        }
    }
    return last;
}

struct Node *delete(struct Node *last)
{
    int n;
    printf("enter the value of node you want to delete:");
    scanf("%d",&n);
    struct Node* first=last->next;
    struct Node *t=NULL;
    if (n==first->data)
    {
        last->next=first->next;
        free(first);
    }
    else
    {
        while (first->next->data!=n)
        {
            first=first->next;
        }
        t=first->next;
        first->next=t->next;
        if (t==last)
        {
            last=first;
        }
        free(t);
    }
    return last;
}
int main()
{
    struct Node *last=NULL;
    int ch;
    printf("enter a number to insert in circular Linked List and 0 to stop inserting:");
    scanf("%d",&ch);
    do{
       
        last=create(last,ch);
        printf("enter a number to insert in circular Linked List and 0 to stop inserting:");
        scanf("%d",&ch);

    }while (ch!=0);
    int choice;
    do{
        printf("enter your choice\n 1.insert\n 2.Delete\n 3.exit\n");
        scanf("%d",&choice);
        if (choice==1)
        {
            last=insert(last);
        }
        if (choice==2)
        {
            last=delete(last);
        }
        if (choice==3)
        {
            break;
        }
    }while (choice<=3);
    
    display(last->next);
    
}