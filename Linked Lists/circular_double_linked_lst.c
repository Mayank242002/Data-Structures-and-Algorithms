/* THIS PROGRAM TAKES ME 4 DAYS TO THINK AND CODE AND AFTER LOT OF DEBUGGING ,FINALLY I GOT SUCCESSED  */

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *Head = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head->prev = Head;
    last = Head;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        Head->prev = t;
        t->prev = last;
        last->next = t;
        last = t;
    }
}
int Length(struct Node *p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;
    } while (p != Head);
    return len;
}
void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if (index < 0 || index > Length(p))
        return;
    if (index == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        if (p == NULL)
        {
            p = t;
            p->next = p;
            p->prev = p;
        }
        else
        {
            t->next = p;
            p->prev->next = t;
            t->prev = p->prev;
            p->prev = t;
            Head = t;
        }
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;

        t->prev = p;
        t->next = p->next;
        if (p->next)
            p->next->prev = t;
        p->next = t;
    }
}
int Delete(struct Node *p, int index)
{

    int x = -1, i;
    if (index < 1 || index > Length(p))
        return -1;
    else if (index == 1)
    {
        x = p->data;
        p->next->prev = p->prev;
        p->prev->next = p->next;
        Head = p->next;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;
        x = p->data;
        free(p);
    }
    return x;
}

void Display(struct Node *h)
{
    do
    {
        printf("%d ", h->data);
        h = h->next;
    } while (h != Head);

    printf("\n");
}

int main()
{
    int A[] = {20, 30, 40, 50};
    create(A, 4);
    Insert(Head, 4, 1);

    Display(Head);
    return 0;
}