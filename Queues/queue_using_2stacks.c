#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *Top = NULL, *Top2 = NULL;

void push1(int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("stack overflow");
    else
    {
        t->data = x;
        t->next = Top;
        Top = t;
    }
}
void push2(int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("stack overflow");
    else
    {
        t->data = x;
        t->next = Top2;
        Top2 = t;
    }
}
int pop1()
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
int pop2()
{
    int x = 1;
    struct Node *t;
    if (Top2 == NULL)
        printf("stack is empty");
    else
    {
        t = Top2;
        Top2 = Top2->next;
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
int isempty1()
{
    if (Top == NULL)
        return 1;
    else
        return 0;
}
int isempty2()
{
    if (Top2 == NULL)
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

void enqueue(int x)
{
    push1(x);
}

int dequeue()
{
    int x = -1;
    if (isempty2())
    {
        if (isempty1())
        {
            printf("queue id empty");
            return x;
        }
        else
        {
            while (!isempty1())
            {
                push2(pop1());
            }
        }
    }
    return pop2();
}
int main()
{
    enqueue(12);
    enqueue(13);
    enqueue(14);
    enqueue(15);
    dequeue();
    dequeue();

    display(Top2);
}