#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int findMax(int A[], int n)
{
    int max = INT_MIN;
    int i;
    for (i = 0; i < n; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}
void insert(int *p, int data)
{
}

int Delete(struct Node *p)
{
    return (p->data);
}

void BucketSort(int A[], int n)
{
    int max, i, j;
    max = findMax(A, n);
    struct Node **Bins;
    Bins = (struct Node **)malloc(sizeof(struct Node) * max + 1);
    for (i = 0; i < max + 1; i++)
    {
        Bins[i] = NULL;
    }
    for (i = 0; i < n; i++)
    {
        insert(Bins[A[i]], A[i]);
    }
    i == 0, j = 0;
    while (i < max + 1)
    {
        while (Bins[i] != NULL)
        {
            A[j++] = Delete(Bins[i]);
        }
        i++;
    }
}
int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10, i;
    BucketSort(A, n);
    for (i = 0; i < 10; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}