#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
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
void create2(int A[], int n)
{
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));

    second->data = A[0];
    second->next = NULL;
    last = second;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int length(struct Node *head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}
//finds the intersection of the given linked lists version1
//Brute force approach
struct Node *findMergePoint1(struct Node *A, struct Node *B)
{
    int m = length(A); //O(m)
    int n = length(B); //O(n)
    struct Node *head2 = B;
    for (int i = 0; i < m; i++)
    {
        B = head2;
        for (int j = 0; j < n; j++)
        {
            if (A == B)
            {
                return A;
            }
            B = B->next;
        }
        A = A->next;
    }
    return NULL;
}

//finds the intersection of the given linked lists version3
//The best approach to solve
struct Node *findMergePoint3(struct Node *A, struct Node *B)
{
    int m = length(A);
    int n = length(B);
    int d = n - m;
    if (m > n)
    {
        struct Node *temp = A;
        A = B;
        B = temp;
        d = m - n;
    }
    int i;
    for (i = 0; i < d; i++)
    {
        B = B->next;
    }
    while (A != NULL && B != NULL)
    {
        if (A == B)
        {
            return A;
        }
        A = A->next;
        B = B->next;
    }
    return NULL;
}

int main()
{
    struct Node *t1, *t2, *t3;
    int A[] = {10, 20, 40, 50, 60};
    int B[] = {15, 18};
    create(A, 5);
    create2(B, 2);
    t1 = first->next->next->next;
    t2 = second->next;
    t2->next = t1;
    t3 = findMergePoint3(first, second);
    printf("%d ", t3->data);

    return 0;
}