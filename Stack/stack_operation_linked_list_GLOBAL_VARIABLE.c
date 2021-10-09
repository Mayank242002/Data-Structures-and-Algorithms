#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *Top = NULL;  //USING GLOBAL POINTERS

void push(int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("not enough memory");
    else
    {
        t->data = x;
        t->next = Top;
        Top = t;
    }
}
int pop()
{
    int x = 1;
    struct Node *t;
    if (Top == NULL)
        printf("stack is empty");
    else
    {
        t = Top;
        Top = Top->next;
        x = t->data;
        free(t);
    }
    return x;
}
int peek(int pos)
{
    int i;
    struct Node *p = Top;
    for (i = 0; i < pos - 1 && p != NULL; i++)
    {
        p = p->next;
    }
    if (p)
        return p->data;
    else
        return -1;
}
int stacktop()
{
    if (Top)
        return Top->data;
    else
        return -1;
}
int isempty()
{
    if (Top == NULL)
        return 1;
    else
        return 0;
}
int isfull()
{
    struct Node *t = (struct Node *)malloc(sizeof(sizeof(struct Node)));
    if (t == NULL)
        return 1;
    else
        return 0;
}
void display(struct Node *p)
{
    while (p)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}
int main()
{
    push(12);
    push(13);
    pop();

    display(Top);
}