class Solution
{
public:
    void swap(long long *a, long long *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        int i = 0, j = 0, k = 0;

        for (i = 0; i < n; i++)
        {
            if (arr1[i] > arr2[0])
            {
                swap(&arr1[i], &arr2[0]);
                for (j = 1; j < m; j++)
                {
                    if (j != m - 1 && arr2[0] > arr2[j] && arr2[0] < arr2[j + 1])
                    {
                        int temp2 = arr2[0];
                        for (k = 1; k <= j; k++)
                        {
                            arr2[k - 1] = arr2[k];
                        }
                        arr2[j] = temp2;
                    }
                    else if (j == m - 1 && arr2[0] > arr2[m - 1])
                    {
                        int temp2 = arr2[0];
                        for (k = 1; k <= j; k++)
                        {
                            arr2[k - 1] = arr2[k];
                        }
                        arr2[j] = temp2;
                    }
                }
            }
        }
    }
};