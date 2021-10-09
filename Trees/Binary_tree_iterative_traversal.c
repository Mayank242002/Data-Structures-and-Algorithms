#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"

struct Node *root = NULL;

void TreeCreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);
    printf("enter root value");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);
    while (!isEmpty(q))
    {
        p = dequeue(&q);
        printf("enter left child of %d", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("enter right child of %d", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void Preorderit(struct Node *t)
{
    struct Stack st;
    createstack(&st, 100);
    while (t != NULL || (!isEmptystack(st)))
    {
        if (t != NULL)
        {
            printf("%d ", t->data);
            push(&st, t);
            t = t->lchild;
        }
        else
        {
            t = pop(&st);
            t = t->rchild;
        }
    }
}
void Inorderit(struct Node *t)
{
    struct Stack st;
    createstack(&st, 100);
    while (t != NULL || (!isEmptystack(st)))
    {
        if (t != NULL)
        {
            push(&st, t);
            t = t->lchild;
        }
        else
        {
            t = pop(&st);
            printf("%d ", t->data);
            t = t->rchild;
        }
    }
}
void Postorderit(struct Node *t)
{
    struct Stack st;
    struct Node *temp;
    createstack(&st, 100);
    while (t != NULL || (!isEmptystack(st)))
    {
        if (t != NULL)
        {
            push(&st, t);
            t = t->lchild;
        }
        else
        {
            temp = pop(&st);
            if (temp > 0)
            {
                push(&st, temp);
                t = ((struct Node *)temp)->rchild;
            }
            else
            {
                printf("%d ", ((struct Node *)temp)->rchild->data);
                t = NULL;
            }
        }
    }
}

void Levelorder(struct Node *p)
{
    struct Queue q;
    create(&q, 100);
    printf("%d ", p->data);
    enqueue(&q, p);
    while (!isEmpty(q))
    {
        p = dequeue(&q);
        if (p->lchild)
        {
            printf("%d ", p->lchild->data);
            enqueue(&q, p->lchild);
        }
        if (p->rchild)
        {
            printf("%d ", p->rchild->data);
            enqueue(&q, p->rchild);
        }
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
void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}
void Postorder(struct Node *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}

int main()
{

    TreeCreate();
    Levelorder(root);

    return 0;
}