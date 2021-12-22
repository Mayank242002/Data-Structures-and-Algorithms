#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include "Queue.h"

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

int countoftotalnodes(struct Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = countoftotalnodes(p->lchild);
        y = countoftotalnodes(p->rchild);
        return x + y + 1;
    }
    return 0;
}

int height(struct Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = height(p->lchild);
        y = height(p->rchild);
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }
    return 0;
}

int countof2degreenodes(struct Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = countof2degreenodes(p->lchild);
        y = countof2degreenodes(p->rchild);
        if (p->lchild && p->rchild)
            return x + y + 1;
        else
            return x + y;
    }
    return 0;
}
int sumofallnodes(struct Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = sumofallnodes(p->lchild);
        y = sumofallnodes(p->rchild);
        return x + y + p->data;
    }
    return 0;
}

int countof1degreenodes(struct Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = countof1degreenodes(p->lchild);
        y = countof1degreenodes(p->rchild);
        if ((p->lchild && !p->rchild) || (!p->lchild && p->rchild)) //or p->lchild ^ p->rchild
            return x + y + 1;
        else
            return x + y;
    }
    return 0;
}
int countof0degreenodes(struct Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = countof0degreenodes(p->lchild);
        y = countof0degreenodes(p->rchild);
        if (p->lchild == NULL && p->rchild == NULL)
            return x + y + 1;
        else
            return x + y;
    }
    return 0;
}
int countof_1_or_2_degreenodes(struct Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = countof0degreenodes(p->lchild);
        y = countof0degreenodes(p->rchild);
        if (p->lchild != NULL || p->rchild != NULL)
            return x + y + 1;
        else
            return x + y;
    }
    return 0;
}
int countof_2_or_0_degreenodes(struct Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = countof0degreenodes(p->lchild);
        y = countof0degreenodes(p->rchild);
        if ((p->lchild == NULL && p->rchild == NULL)||(p->lchild&& p->rchild))
            return x + y + 1;
        else
            return x + y;
    }
    return 0;
}

int countof_1_or_0_degreenodes(struct Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = countof0degreenodes(p->lchild);
        y = countof0degreenodes(p->rchild);
        if ((p->lchild == NULL && p->rchild == NULL)||(p->lchild && !p->rchild) || (!p->lchild && p->rchild))
            return x + y + 1;
        else
            return x + y;
    }
    return 0;
}

int max(int x,int y,int z)
{
    if (x>=y && x>=z)
      return x;
    else if (y>=x && y>=z)
      return y;
    else
      return z;
}

int min(int x,int y,int z)
{
    if (x<=y && x<=z)
      return x;
    else if (y<=x && y<=z)
      return y;
    else
      return z;
}

int max_in_BT(struct Node *p)
{
    if (p==NULL)
       return INT_MIN;
    else{
        int x=max_in_BT(p->lchild);
        int y=max_in_BT(p->rchild);
        return max(x,y,p->data);

    }
}

int min_in_BT(struct Node *p)
{
    if (p==NULL)
       return INT_MAX;
    else{
        int x=min_in_BT(p->lchild);
        int y=min_in_BT(p->rchild);
        return min(x,y,p->data);

    }
}

int main()
{

    TreeCreate();

    printf("%d is the number of nodes in the tree\n", countoftotalnodes(root));
    printf("%d is the height of the tree\n", height(root));

    printf("%d is the number of nodes with degree 2 in the tree\n", countof2degreenodes(root));
    printf("%d is the sum of the tree\n", sumofallnodes(root));
    printf("%d is the number of nodes with degree 1 in the tree\n", countof1degreenodes(root));
    printf("%d is the number of nodes with degree 0 in the tree\n", countof0degreenodes(root));
    printf("%d is the number of nodes with degree 1 or 2 in the tree\n", countof_1_or_2_degreenodes(root));
    printf("%d is the minimum in BT",min_in_BT(root));
}