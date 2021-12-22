#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

void insert(struct Node **rt,int x)
{
    struct Node *p=NULL;
    if (*rt==NULL)
    {
       p=(struct Node *)malloc(sizeof(struct Node));
       p->data=x;
       p->lchild=p->rchild=NULL;
       *rt=p;
       return;
    }
    else if ((*rt)->data>x)
         insert(&(*rt)->lchild,x);
    else if ((*rt)->data<x)
         insert(&(*rt)->rchild,x);
    else
        printf("not allowed");

}
void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}
int main()
{
   struct Node *root=NULL;
   int choice;
  
   do{
        printf("1.insert\n2.Inorder\n3.exit");
        scanf("%d",&choice);
        if (choice==1)
         {
             int x;
             printf("enter the element to insert:");
             scanf("%d",&x);
             insert(&root,x);
         }
         else if (choice==2)
            Inorder(root);
         else if (choice==3)
            break;

   }while(choice<=3);

}