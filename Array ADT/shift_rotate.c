#include <stdio.h>
struct Array
{
    int A[10];
    int size;
    int length;
};
void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void rotate(struct Array *arr)
{
    int temp = arr->A[0];
    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i - 1] = arr->A[i];
    }
    arr->A[arr->length - 1] = temp;
}

int main()
{
    struct Array arr1 = {{2, 3, 9, 16, 18, 21, 28, 32, 35}, 10, 9};
    rotate(&arr1);
    Display(arr1);
    return 0;
}