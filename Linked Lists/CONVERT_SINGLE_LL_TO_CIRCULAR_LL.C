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
void display(struct Node *p)
{
    struct Node *first=p;
    do{
        printf("%d ",p->data);
        p=p->next;
    }while (p!=first);
}

void convert_single_to_circular(struct Node *f,struct Node *l)
{
    l->next=f;

}


int main()
{
  struct Node *first =NULL,*last=NULL;
  

  int ch;
  do{
      printf("enter your choice 1.adding nodes at the RHS\n 2.convert to single\n 3.Display\n 4.exit\n");
      scanf("%d",&ch);

      if (ch==1)
      {
          last=create(last);
          if (first==NULL)
            first=last;
      }
      if (ch==2)
      {
          convert_single_to_circular(first,last);
      }
     
      if (ch==3)
      {
          display(last->next);
      }
       
      if (ch==4)
      {
          break;
      }


      
  }while (ch<=4);

}