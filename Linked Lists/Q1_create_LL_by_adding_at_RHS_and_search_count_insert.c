#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

struct Node * create(struct Node *last)
{

      int n; 
      printf("enter the value of number");
      scanf("%d",&n);
      struct Node *t=(struct Node*)malloc(sizeof(struct Node));
      t->data=n;
      t->next=NULL;

      if (last==NULL)
      last=t;
      else{
          last->next=t;
          last=t;
      }
      last->next=NULL;

      return last;
}
void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}


void search(struct Node *p)
{
    int ch;
    printf("enter the value to be searched:");
    scanf("%d",&ch);
    int flag=0;
    while (p)
    {
        if (ch==p->data)
        {
            flag=1;
            break;
        }
        p=p->next;
    }
    if (flag==0)
      printf("value is not present in Linked list\n");
    else
      printf("value is present in Linked list\n");
}

void count(struct Node *p)
{
    int count=0,ce=0,co=0;
    while (p)
    {
        count++;
        if ((p->data)%2==0)
        ce++;
        else
        co++;
    }

    printf("Total count=%d,even values count= %d,odd values count= %d",count,ce,co);
}
struct Node * insert_at_front_of_node(struct Node *p)
{
      int n,ch;
      printf("enter the value of number to be inserted and the value of node where you want to add node ");
      scanf("%d %d",&n,&ch);
      struct Node *t,*temp;
      t=(struct Node*)malloc(sizeof(struct Node));
      t->data=n;
      t->next=NULL;

      if (ch==p->data)
      {
          t->next=p;
          p=t;
      }
      else{
         temp=p;
          while (ch!=temp->next->data && temp!=NULL)
          {
              temp=temp->next;
          }
          if (temp!=NULL)
          {
              t->next=temp->next;
              temp->next=t;
          }
      }
      return p;
}
struct Node * insert_at_end_of_node(struct Node *p)
{
      int n,ch;
      printf("enter the value of number to be inserted and the value of node where you want to add node ");
      scanf("%d %d",&n,&ch);
      struct Node *t,*temp;
      t=(struct Node*)malloc(sizeof(struct Node));
      t->data=n;
      t->next=NULL;

      
         temp=p;
          while (ch!=temp->data && temp!=NULL)
          {
              temp=temp->next;
          }
          if (temp!=NULL)
          {
              t->next=temp->next;   
              temp->next=t;
              temp=t;
          }
          if (temp->next==NULL)
              return temp;
          else
              return p;

      
}
void insert(struct Node **first,struct Node **last)
{
    printf("enter your choice 1.insert at the front of node\n 2.insert at the end of node\n");
    int choice;
    scanf("%d",&choice);
    if (choice==1)
    {
        *first=insert_at_front_of_node(*first);
    }
    if (choice==2)
    {
        *last=insert_at_end_of_node(*first);
    }
}
void Displayreverse(struct Node *p)
{
    if (p==NULL)
    return;
    else{
        Displayreverse(p->next);
        printf("%d ",p->data);
    }
}

int main()
{
  struct Node *first =NULL,*last=NULL;
  

  int ch;
  do{
      printf("enter your choice 1.adding nodes at the RHS\n 2.search\n 3.count\n 4.insert nodes\n 5.Display\n 6.Display from right to left\n 7.exit ");
      scanf("%d",&ch);

      if (ch==1)
      {
          last=create(last);
          if (first==NULL)
            first=last;
      }
      if (ch==2)
      {
          search(first);
      }
      if (ch==3)
      {
          count(first);
      }
      if (ch==4)
      {
          insert(&first,&last);
      }
      if (ch==5)
      {
          Display(first);
      }
       if (ch==6)
      {
          Displayreverse(first);
      }
      if (ch==7)
      {
          break;
      }


      
  }while (ch<=7);

}