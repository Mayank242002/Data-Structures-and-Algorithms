#include<stdio.h>
#include <stdlib.h>
#define MAX 100

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void quick_sort(int arr[],int lb,int ub)
{
   
    int pivot=arr[lb];
    int i=lb,j=ub;

    if (lb>=ub)
       return ;
    else{
        while (i<j)
        {
            while (pivot>=arr[i] && i<j)
                  i++;
            while (pivot<arr[j])
                  j--;
            if (i<j)
             swap(&arr[i],&arr[j]);
        }
        swap(&arr[lb],&arr[j]);
        quick_sort(arr,lb,j-1);
        quick_sort(arr,j+1,ub);
    }

}
int main()
{
    int arr[MAX];
    int n;
    printf("enter the value of the n");
    scanf("%d",&n);
    printf("enter the value of the numbers");
    for (int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    quick_sort(arr,0,n-1);

    for (int i=0;i<n;i++)
        printf("%d ",arr[i]);
}
