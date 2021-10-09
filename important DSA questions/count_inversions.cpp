#include <iostream>
using namespace std;

int merge(int A[], int temp[], int l, int mid, int h)
{
    int i, j, k;
    int inv_count = 0;

    i = l;
    j = mid + 1;
    k = l;
    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
            temp[k++] = A[i++];
        else
        {
            temp[k++] = A[j++];
            inv_count += mid - i + 1;
        }
    }
    for (; i <= mid; i++)
        temp[k++] = A[i];
    for (; j <= h; j++)
        temp[k++] = A[j];
    for (i = l; i <= h; i++)
        A[i] = temp[i];

    return inv_count;
}

int mergeSort(int arr[], int temp[], int l, int h)
{
    int mid, incount = 0;

    if (h > l)
    {
        mid = (l + h) / 2;

        incount += mergeSort(arr, temp, l, mid);
        incount += mergeSort(arr, temp, mid + 1, h);
        incount += merge(arr, temp, l, mid, h);
    }

    return incount;
}

int main()
{
    int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp[n];
    int ans = mergeSort(arr, temp, 0, n - 1);
    cout << " Number of inversions are " << ans;
    return 0;
}
