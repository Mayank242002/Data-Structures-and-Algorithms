#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}


int main()
{
  struct Node *first =NULL,*t=NULL;
  

  int n,ch;
  do{
      printf("enter the value of number");
      scanf("%d",&n);
      t=(struct Node*)malloc(sizeof(struct Node));
      t->data=n;

      if (first==NULL)
      {
          first=t;
          first->next=NULL;
      }
      
      else{
          t->next=first;
          first=t;
      }

      printf("enter 1 to continue adding values and 0 for exit");
      scanf("%d",&ch);
      
  }while (ch==1);


  Display(first);


}