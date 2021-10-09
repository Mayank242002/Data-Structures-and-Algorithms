#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

vector<int> subsetposses(int arr[], int n, int sum)
{
    bool t[n + 1][sum + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                t[i][j] = false;
            if (j == 0)
                t[i][j] = true;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            }
            else if (arr[i - 1] > j)
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    vector<int> v;

    for (int i = 0; i <= sum / 2; i++)
    // contains all subset sums possible with n elements // creating a vector varible to store all the element of the last row upto sum/2
    // from the range we need to exclude the element which is not there in the existing problem
    {
        if (t[n][i] == true) // keep true to only those place whose subset sum exist
            v.push_back(i);  // store in the vector
    }

    return v;
}

int MinSubsetSumDiff(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    vector<int> v = subsetposses(arr, n, sum);
    int mn = INT_MAX;
    for (int i = 0; i < v.size(); i++)
    {
        mn = min(mn, abs(sum - 2 * v[i]));
    }
    return mn;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << MinSubsetSumDiff(arr, n) << endl;
    return 0;
}