#include <iostream>
#include <algorithm>

using namespace std;

int knapsack(int wt[], int val[], int W, int n)
{
    int t[n + 1][W + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0 || j == 0) // base case // filling 1st row and 1st column of the matrix with zero as per the base condition of the recursive solution
                t[i][j] = 0;
            else if (wt[i - 1] <= j)
            {
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][W]);
            }
            else if (wt[i - 1] > j)
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][W];
}

int main()
{
    int n;
    cin >> n;          // number of items
    int val[n], wt[n]; // values and wts array
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    for (int i = 0; i < n; i++)
        cin >> val[i];
    int W;
    cin >> W; // capacity

    cout << knapsack(wt, val, W, n) << endl;
    return 0;
}

/* Complexity Analysis: 
Time Complexity: O(N*W). 
where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
Auxiliary Space: O(N*W). 
The use of 2-D array of size ‘N*W’.
*/