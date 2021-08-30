#include <iostream>
#include <vector>
using namespace std;

vector<int> repeatedNumber(const vector<int> &A)
{
    int n = A.size();
    int sum1 = (n * (n + 1)) / 2;
    int sum2 = (n * (n + 1) * (2 * n + 1)) / 6;
    int missing = 0, repeating = 0;

    for (int i = 0; i < n; i++)
    {
        sum1 = sum1 - A[i];
        sum2 = sum2 - A[i] * A[i];
    }

    missing = (sum1 + (sum2 / sum1)) / 2;
    repeating = (sum2 / sum1) - missing;
    vector<int> ans;
    ans.push_back(repeating);
    ans.push_back(missing);
    return ans;
}

int main(void)
{
    vector<int> v = {4, 3, 6, 2, 1, 6, 7};
    vector<int> res = repeatedNumber(v);
    for (int x : res)
    {
        cout << x << "  ";
    }
    cout << endl;
}
