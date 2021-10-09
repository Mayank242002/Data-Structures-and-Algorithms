#include <iostream>
using namespace std;

int subset_sum(int arr[], int n, int sum)
{
    int t[n + 1][sum + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0) // when array(i) is empty than there is no meaning of sum of elements so return false
                t[i][j] = 0;
            if (j == 0) // when sum(j) is zero and there is always a chance of empty subset so return it as true;
                t[i][j] = 1;
        }
    }

    // start from 1 since 1st row and column is already considerd
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
                // after taking and element substract from the (sum) i.e -> in {3,8} 3 is taken then we want 11-3=8in the array
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j]; // either take or(||) do not take
            else                                                  // if sum is less than array size just leave and increment
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][sum];
}

int coutNumberOfSubsetWithGivenDiffernce(int arr[], int n, int diff)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int sumOfSubset1 = (diff + sum) / 2;
    return subset_sum(arr, n, sumOfSubset1);
}

int main()
{
    int n, diff;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> diff;
    cout << coutNumberOfSubsetWithGivenDiffernce(arr, n, diff) << endl;
}