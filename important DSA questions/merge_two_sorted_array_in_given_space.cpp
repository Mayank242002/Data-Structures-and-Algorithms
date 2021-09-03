#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    int i = 0, j = 0, k = 0;

    for (i = 0; i < n; i++)
    {
        if (arr1[i] > arr2[0])
        {
            swap(arr1[i], arr2[0]);
            sort(arr2.begin(), arr2.end());
        }
    }
}

int main()
{
    vector<int> arr1 = {1, 5, 9, 10, 15, 20};
    vector<int> arr2 = {2, 3, 8, 13};

    merge(arr1, arr2, 6, 4);

    for (int i = 0; i < arr1.size(); i++)
        cout << arr1[i] << " ";
    cout << endl;

    for (int i = 0; i < arr2.size(); i++)
        cout << arr2[i] << " ";
    cout << endl;
}