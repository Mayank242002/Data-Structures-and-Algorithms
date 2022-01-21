#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Node
{
    int coeff;
    int exp;
    struct Node *next;
} *poly = NULL, *poly2 = NULL;
void create()
{
    struct Node *t, *last = NULL;
    int num, i;
    printf("Enter number of terms");
    scanf("%d", &num);
    printf("Enter each term with coeff and exp\n");
    for (i = 0; i < num; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d%d", &t->coeff, &t->exp);
        t->next = NULL;
        if (poly == NULL)
        {
            poly = last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
}
void create2()
{
    struct Node *t, *last = NULL;
    int num, i;
    printf("Enter number of terms");
    scanf("%d", &num);
    printf("Enter each term with coeff and exp\n");
    for (i = 0; i < num; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d%d", &t->coeff, &t->exp);
        t->next = NULL;
        if (poly2 == NULL)
        {
            poly2 = last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
}

void Display(struct Node *p)
{
    while (p)
    {
        printf("%dx%d +", p->coeff, p->exp);
        p = p->next;
    }
    printf("\n");
}
long Eval(struct Node *p, int x)
{
    long val = 0;
    while (p)
    {
        val += p->coeff * pow(x, p->exp);
        p = p->next;
    }
    return val;
}
void add(struct Node *p, struct Node *q)
{
    struct Node *sum = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = sum;
    while (p && q)
    {
        if (p->exp > q->exp)
        {
            temp->exp = p->exp;
            temp->coeff = p->coeff;
            p = p->next;
            if (p)
            {
                temp->next = (struct Node *)malloc(sizeof(struct Node));
                temp = temp->next;
            }
        }
        else if (p->exp < q->exp)
        {
            temp->exp = q->exp;
            temp->coeff = q->coeff;
            q = q->next;
            if (q)
            {
                temp->next = (struct Node *)malloc(sizeof(struct Node));
                temp = temp->next;
            }
        }
        else
        {
            temp->exp = p->exp;
            temp->coeff = p->coeff + q->coeff;
            q = q->next;
            p = p->next;
            if (p && q)
            {
                temp->next = (struct Node *)malloc(sizeof(struct Node));
                temp = temp->next;
            }
        }
    }
    while (p)
    {
        temp->next = (struct Node *)malloc(sizeof(struct Node));
        temp = temp->next;
        temp->exp = p->exp;
        temp->coeff = p->coeff;
        p = p->next;
    }
    while (q)
    {
        temp->next = (struct Node *)malloc(sizeof(struct Node));
        temp = temp->next;
        temp->exp = q->exp;
        temp->coeff = q->coeff;
        q = q->next;
    }
    temp->next = NULL;
    Display(sum);
}
int main()
{

    create();
    create2();
    printf("Polynomial 1:");
    Display(poly);
    printf("\n");
    printf("Polynomial 2:");
    Display(poly2);
    printf("\n");
    add(poly, poly2);

    return 0;
}