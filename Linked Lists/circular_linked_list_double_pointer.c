#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void create(struct Node **f1,struct Node **r1,int n)
{
    struct Node *p=NULL;
    p=(struct Node *)malloc(sizeof(struct Node));
    if (p!=NULL)
    {
        p->data=n;
        if (*f1==NULL && *r1==NULL)
        {
            *f1=*r1=p;
        }
        else
        {
          p->next=(*r1)->next;
          (*r1)->next=p;
          *r1=p;
        }
        (*r1)->next=*f1;
    }
    else
    {
        printf("not enough memory");
    }
}


void delete (struct Node **f1,struct Node **r1)
{
    int n;
    printf("enter the value of node you want to delete:");
    scanf("%d",&n);
    struct Node *t=NULL;
    struct Node *first=*f1;
    struct Node *last=*r1;

    if (n==(*f1)->data)
    {
        (last)->next=(first)->next;
        *f1=(*f1)->next;
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
            *r1=first;
        }
        free(t);
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

int main()
{
    struct Node *first=NULL,*last=NULL;
    int ch;
    printf("enter a number to insert in circular Linked List and 0 to stop inserting:");
    scanf("%d",&ch);
    do{
       
        create(&first,&last,ch);
        printf("enter a number to insert in circular Linked List and 0 to stop inserting:");
        scanf("%d",&ch);

    }while (ch!=0);
    int choice;
    do{
        printf("enter your choice\n 1.Delete\n 2.exit\n");
        scanf("%d",&choice);
      
        if (choice==1)
        {
            delete(&first,&last);
        }
        if (choice==2)
        {
            break;
        }
    }while (choice<=2);
    
    display(last->next);
    
}