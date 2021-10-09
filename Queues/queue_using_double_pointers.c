#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void enqueue(struct Node **front,struct Node **rear,int n)
{
    struct Node *t=(struct Node*)malloc(sizeof(struct Node));
    t->data=n;
    t->next=NULL;
    if (*rear==NULL)
    *rear=*front=t;
    else{
        (*rear)->next=t;
        *rear=t;
    }
}

void dequeue(struct Node **front,struct Node **rear)
{
    struct Node *temp=NULL;
    if (front==NULL)
         printf("nothing to delete");
    else{
    temp=*front;
    *front=(*front)->next;
    free(temp);
    }
    if (*front==NULL)
    {
        *rear=NULL;
    }   
}

void display(struct Node *p)
{
    while (p)
    {
      printf("%d ",p->data);
      p=p->next;
    }
}
int main()
{
    struct Node *front=NULL,*rear=NULL;
    int n,ch;
    do
    {
        printf("\n1.insert\n2.delete\n3.Display\n4.exit\n");
        scanf("%d",&ch);
        if (ch==1)
        {
            printf("enter a number to enqueue");
            scanf("%d",&n);
            enqueue(&front,&rear,n);
        }
        if (ch==2)
        {
            dequeue(&front,&rear);
        }
        if (ch==3)
        {
            display(front); 
        }
        
        
    }while (ch<=3);
    

}