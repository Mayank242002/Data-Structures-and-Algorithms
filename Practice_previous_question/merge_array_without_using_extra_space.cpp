
#include <bits/stdc++.h>
using namespace std;

int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}

void merge(int a1[], int a2[], int n, int m)
{
    int gap = ((n + m) / 2) + ((n + m) % 2);
    int i = 0, j = 0;

    for (gap = gap; gap > 0; gap = nextGap(gap))
    {
        for (i = 0; i + gap < n; i++)
        {
            if (a1[i] > a1[i + gap])
            {
                swap(a1[i], a1[i + gap]);
            }
        }

        for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++)
        {
            if (a1[i] > a2[j])
            {
                swap(a1[i], a2[j]);
            }
        }

        if (j < m)
        {
            for (j = 0; j + gap < m; j++)
            {
                if (a2[j] > a2[j + gap])
                {
                    swap(a2[j], a2[j + gap]);
                }
            }
        }
    }
}

int main()
{
    int a1[] = {2, 6};
    int a2[] = {3, 7, 12, 15};
    int n = sizeof(a1) / sizeof(int);
    int m = sizeof(a2) / sizeof(int);

    // Function Call
    merge(a1, a2, n, m);

    printf("First Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a1[i]);

    printf("\nSecond Array: ");
    for (int i = 0; i < m; i++)
        printf("%d ", a2[i]);
    printf("\n");
    return 0;
}