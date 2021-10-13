#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

struct Node * create(struct Node *first)
{

      int n; 
      printf("enter the value of number");
      scanf("%d",&n);
      struct Node *t=(struct Node*)malloc(sizeof(struct Node));
      t->data=n;
      t->next=NULL;

      if (first==NULL)
      first=t;
      else{
          t->next=first;
          first=t;
      }
      return first;
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

void Delete(struct Node **f,struct Node **l)
{

   int choice;
   printf("enter the element you want to delete");
   scanf("%d",&choice);
   struct Node *p=NULL,*temp=NULL;
   
   if (choice==(*f)->data)
   {
       p=*f;
       *f=(*f)->next;
   }
   else{
       temp=*f;
       while (choice!=temp->next->data && temp!=NULL)
       {
           temp=temp->next;
       }
       if (temp->next->data==choice)
       {
           p=temp->next;
           temp->next=temp->next->next;
           *l=temp->next;
       }
       
   }

   free(p);


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
      printf("enter your choice 1.adding nodes at the LHS\n 2.search\n 3.count\n 4.delete nodes\n 5.Display\n 6.Display from right to left 7.exit ");
      scanf("%d",&ch);

      if (ch==1)
      {
          first=create(first);
          if (last==NULL)
            last=first;
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
          Delete(&first,&last);
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