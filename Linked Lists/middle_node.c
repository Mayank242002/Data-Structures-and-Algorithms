#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;
void create(int A[], int n)
{
    int i;
    struct Node *last, *t;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
int count(struct Node *p)
{
    int l = 0;
    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
}
void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
int middle(struct Node *p)
{
    struct Node *q = (struct Node *)malloc(sizeof(struct Node));
    q = first;
    while (q)
    {
        q = q->next;
        if (q)
            q = q->next;
        if (q)
            p = p->next;
    }
    return p->data;
}
int middle2(struct Node *p)
{
    int middle = ceil((count(p)) / 2), i;
    for (i = 0; i < middle - 1; i++)
    {
        p = p->next;
    }
    return p->data;
}
int main()
{
    int A[] = {1, 2, 3, 4, 5};
    create(A, 5);
    Display(first);
    printf("\nMiddle Number %d", middle(first));
}