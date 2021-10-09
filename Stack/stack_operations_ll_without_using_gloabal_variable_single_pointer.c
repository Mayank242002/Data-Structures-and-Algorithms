#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node * push(struct Node *Top,int x)
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
    return Top;
}
struct Node * pop(struct Node *Top)
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
    return Top;
}
int peek(int pos,struct Node *Top)
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
int stacktop(struct Node *Top)
{
    if (Top)
        return Top->data;
    else
        return -1;
}
int isempty(struct Node *Top)
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
    struct Node *Top = NULL;  
    Top=push(Top,12);
    Top=push(Top,13);
    Top=push(Top,14);
    display(Top);
}