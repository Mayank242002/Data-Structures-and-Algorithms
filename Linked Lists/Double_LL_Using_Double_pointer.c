#include<stdio.h>
#include<stdlib.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
};

void insert_at_RHS(struct Node **tail,struct Node **head,int n)
{
    struct Node *p=NULL;
    p=(struct Node *)malloc(sizeof(struct Node));
    p->data=n;
    if (*tail==NULL)
    {
       *tail=*head=p;
       (*tail)->prev=NULL;
    }
    else{
        (*tail)->next=p;
        p->prev=*tail;
        *tail=p;
    }
    (*tail)->next=NULL;
}

 void insert_at_LHS(struct Node **tail,struct Node **head,int n)
{
    struct Node *p=NULL;
    p=(struct Node *)malloc(sizeof(struct Node));
    p->data=n;
    if (*head==NULL)
    {
        *tail=*head=p;
       (*head)->next=NULL;
    }
    else{
       p->next=*head;
       (*head)->prev=p;
       *head=p;
    }
    (*head)->prev=NULL;
}

void Delete(struct Node **head,struct Node **tail,int n)
{
       struct Node *p;
       if (n==(*head)->data)
       {
           p=*head;
           (*head)=(*head)->next;
           (*head)->prev=NULL;
       }
       else if (n==(*tail)->data)
       {
           p=*tail;
           (*tail)=(*tail)->prev;
           (*tail)->next=NULL;
       }
       else{
           p=(*head)->next;
           while (p->data!=n && p->next!=NULL)
               p=p->next;
            if (p->next!=NULL)
            {
                p->next->prev=p->prev;
                p->prev->next=p->next;
            }
            else{
              printf("Key not found");
              return ;
            }

       }
       free(p);

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
        printf("Enter your choice\n 1.Add at RHS\n 2.ADD at LHS\n 3.Display\n 4.Delete\n 5.Exit\n");
        scanf("%d",&choice);
        if (choice==1)
        {
           printf("enter elements to add to the Double Linked list and 0 to stop inserting at RHS:");
           scanf("%d",&n);
           insert_at_RHS(&tail,&head,n);

        }
        else if (choice==2)
        {
           printf("enter elements to add to the Double Linked list and 0 to stop inserting at LHS:");
           scanf("%d",&n);
           insert_at_LHS(&tail,&head,n);
        }
        else if (choice==3)
        {
            Display(head);
        }
        else if (choice==4)
        {
            printf("enter Node value You want to delete");
            scanf("%d",&n);
            Delete(&head,&tail,n);
        }
        else
           break;

    }while (choice!=5);
}