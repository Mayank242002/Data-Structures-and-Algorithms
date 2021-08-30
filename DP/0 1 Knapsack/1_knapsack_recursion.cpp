#include <iostream>
#include <algorithm>

using namespace std;

int knapsack(int wt[], int val[], int w, int n)
{

    // every recursive solution will have a base condition
    // for base condition we need to think of the smallest valid input that we can pass
    // array size can be atleast 0 || min weight can be 0 but not negetive;
    if (n == 0 || w == 0)
        return 0;

    // these are the choices we are having
    if (wt[n - 1] <= w)
        return max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1), knapsack(wt, val, w, n - 1));

    else if (wt[n - 1] > w)                 // if the weight is greater then the required weight there is no sence for taking that value.
        return knapsack(wt, val, w, n - 1); // return as it is by redusing the size of array
    else
        return -1;
}

int main()
{
    int n, w;
    cin >> n;
    int wt[n], val[n];
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    for (int i = 0; i < n; i++)
        cin >> val[i];
    cin >> w;

    cout << "maximum profit:" << knapsack(wt, val, w, n) << endl;
}