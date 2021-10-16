#include<stdio.h>
#include<stdlib.h>

struct Node {
    int a;
    int data;
    struct Node *next;
};

void create(struct Node **f1,struct Node **r1,int n)
{
    struct Node *p=NULL;
    p=(struct Node *)malloc(sizeof(struct Node));
    printf("enter the process no:");
    int process;
    scanf("%d",&process);
    if (p!=NULL)
    {
        p->data=n;
        p->a=process;
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
    if (n==(*f1)->data)
    {
        (*r1)->next=(*f1)->next;
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
        if (t==*r1)
        {
            *r1=*f1;
        }
        free(t);
    }
}
void Roundrobin(struct Node **f1,struct Node **r1,int ct)
{
    int totaltime=ct;
    struct Node *p=*f1,*q=*r1,*t;
    while ((*f1)!=NULL)
    { 
        p->data-=ct;
        if (p->data<=0)
        {
            printf("\nProcess %d terminated in %dns\n",p->a,totaltime);
            if (p==*f1)
            {
                t=p;
                *f1=(*f1)->next;
                (*r1)->next=*f1;
                p=*f1;
                if (*f1==*r1 && (*f1)->data<=0)
                {
                    p=q=*f1=*r1=NULL;
                }
            }
            else if (p==*r1){
                t=p;
                q->next=p->next;
                p=p->next;
                *r1=q;
            }
            else{
                t=p;
                q->next=p->next;
                p=p->next;
            }
            free(t);
        }
        else{
            q=p;
            p=p->next;
        }
    totaltime+=ct;        
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
    Roundrobin(&first,&last,10);
    
}