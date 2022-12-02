#include <bits/stdc++.h>
using namespace std;

//TC-O(logn)
void insert(int A[], int n)
{
    int temp = A[n];
    int i = n;
    while (i > 0 && temp > A[(i-1)/ 2])
    {
        A[i] = A[(i-1)/2];
        i = (i-1) / 2;
    }
    A[i] = temp;
}

//TC-O(n)
void heapify(int arr[], int N, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < N && arr[l] > arr[largest])
        largest = l;
    if (r < N && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}
 
//extract_max also works like Delete function on heap
//TC-O(logn)
int extract_max(int arr[],int last_index)
{
    int root=arr[0];
    swap(arr[0],arr[last_index]);
    heapify(arr,last_index,0); //last_index is the new size of Heap beacuse we are not considering that last index to heapify
    return root;
}

//TC-O(n)
void Build_heap(int arr[],int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
}

//TC-O(nlogn)
void heapSort(int arr[], int N)
{
    for (int i = N - 1; i > 0; i--) {
       extract_max(arr,i);
    }
}
 
void printArray(int arr[], int N)
{
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
 
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7,15 };
    int N = 6;
 
    Build_heap(arr, N);
    insert(arr,N);
    heapSort(arr,N+1);
    printArray(arr, N+1);
}