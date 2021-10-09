#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int col;
    int val;
    struct Node *next;
};

void create(struct Node *A[], int m)
{
    int i, j, k;

    struct Node *t, *last = NULL;
    for (i = 0; i < m; i++)
    {

        t = A[i];
        printf("enter no of elements in %d row", i);
        scanf("%d", &k);
        for (j = 0; j < k; j++)
        {
            if (j != 0)
                t = (struct Node *)malloc(sizeof(struct Node));
            printf("enter column no. and element");
            scanf("%d%d", &t->col, &t->val);

            t->next = NULL;
            if (j == 0)
                last = t;
            else
            {
                last->next = t;
                last = t;
            }
        }
    }
}
void display(struct Node *A[], int m, int n)
{
    int i = 0, j = 0;
    struct Node *p;
    for (i = 0; i < m; i++)
    {
        p = A[i];
        for (j = 0; j < n; j++)
        {
            if (j == p->col)
            {
                printf("%d ", p->val);
                p = p->next;
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
}
int main()
{

    int m, n;
    printf("enter no of rows and columns");
    scanf("%d%d", &m, &n);
    struct Node *A[m];
    create(A, m);
    display(A, m, n);
    return 0;
}