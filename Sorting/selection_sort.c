#include <stdio.h>
#include <stdlib.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void SelectionSort_old(int A[], int n)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        for (j = k = i; j < n; j++)
        {
            if (A[j] < A[k])
                k = j;
        }
        swap(&A[i], &A[k]);
    }
}

void SelectionSort_new(int arr[],int n){

    int i,j,pos=0,min=0;
    for (i=0;i<n-1;i++)
    {
        min=arr[i];
        pos=i;
        for (j=i+1;j<n;j++)
        {
            if (min>arr[j])
            {
                min=arr[j];
                pos=j;
            }
        }

        if (pos!=i)
        swap(&arr[pos],&arr[i]);
    } 
}
int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10, i;
    SelectionSort_new(A, n);
    for (i = 0; i < 10; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}