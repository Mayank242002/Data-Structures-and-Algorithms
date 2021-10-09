#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "limits.h"
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;

void CreatePre(int pre[], int n)
{
    struct Stack stk;
    createstack(&stk, 50);
    struct Node *t, *p;
    int i = 0;
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = pre[i++];
    root->lchild = root->rchild = NULL;
    p = root;
    while (i < n)
    {
        if (pre[i] < p->data)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = pre[i++];
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            push(&stk, p);
            p = t;
        }
        else
        {
            int Topdata = ((stacktop(&stk)) ? stacktop(&stk)->data : INT_MAX);
            if (pre[i] > p->data && pre[i] < Topdata)
            {
                t = (struct Node *)malloc(sizeof(struct Node));
                t->data = pre[i++];
                t->lchild = t->rchild = NULL;
                p->rchild = t;
                p = t;
            }
            else
            {
                p = pop(&stk);
            }
        }
    }
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
void Preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
int main()
{
    int a[] = {30, 20, 10, 15, 25, 40, 50, 45};
    CreatePre(a, 8);
    Inorder(root);
    return 0;
}
