#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

struct Node * insert_at_LHS(struct Node *last,int n)
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
        else{
            p->next=last->next;
            last->next=p;
        }
        return last;
     }
     else{
         printf("memory not allocated");
     }
     
}

void display(struct Node *p)
{
    struct Node *first=p;
    do{
        printf("%d ",p->data);
        p=p->next;
    }while (p!=first);
}

int main()
{
    struct Node *last=NULL;
    int ch;
    printf("enter a number to insert in circular Linked List and 0 to stop inserting:");
    scanf("%d",&ch);
    do{
       
        last=insert_at_LHS(last,ch);
        printf("enter a number to insert in circular Linked List and 0 to stop inserting:");
        scanf("%d",&ch);

    }while (ch!=0);

    display(last->next);

}