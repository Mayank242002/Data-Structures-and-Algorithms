//program for max heap similarly for min heap

#include <stdio.h>

void insert(int A[], int n)
{
    int temp = A[n];
    int i = n;
    while (i > 1 && temp > A[i / 2])
    {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int delete (int A[], int n)
{
    int x, i, j, deletedvalue;
    deletedvalue = A[1];
    x = A[n];
    A[1] = A[n];
    A[n] = deletedvalue; //condition for heap sort
    i = 1;
    j = 2 * i;
    while (j < n - 1)
    {
        if (A[j + 1] > A[j])
            j++;
        if (A[i] < A[j])
        {
            swap(&A[i], &A[j]);
            i = j;
            j = j * j;
        }
        else
            break;
    }

    return deletedvalue;
}

int main()
{
    int H[] = {0, 10, 20, 30, 25, 5, 40, 35};
    int i;
    for (i = 2; i <= 7; i++)
    {
        insert(H, i);
    }
    /*for (i = 7; i > 1; i--)
    {
        delete (H, i);
    }*/

    for (i = 1; i <= 7; i++)
    {
        printf("%d ", H[i]);
    }
}