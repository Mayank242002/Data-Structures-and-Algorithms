#include <stdio.h>
#include <limits.h>
#define I INT_MAX

int edge[3][9] = {{1, 1, 2, 2, 3, 4, 4, 5, 5}, {2, 6, 3, 7, 4, 5, 7, 6, 7}, {25, 5, 12, 10, 8, 16, 14, 20, 18}};
int set[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
int included[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

int t[2][7];

void Myunion(int u, int v)
{
    if (set[u] < set[v])
    {
        set[u] += set[v];
        set[v] = u;
    }
    else
    {
        set[v] += set[u];
        set[u] = v;
    }
}
int find(int u)
{
    int x = u, v = 0;
    while (set[x] > 0)
    {
        x = set[x];
    }
    while (u != x)
    {
        v = set[u];
        set[u] = x;
        u = v;
    }
    return x;
}

int main()
{
    int i = 0, j, k, u, v, min = I, n = 7, e = 9;
    while (i < n - 1)
    {
        min = I;
        for (j = 0; j < e; j++)
        {
            if (included[j] == 0 && edge[2][j] < min)
            {
                min = edge[2][j];
                k = j;
                u = edge[0][j];
                v = edge[1][j];
            }
        }

        if (find(u) != find(v))
        {
            t[0][i] = u;
            t[1][i] = v;
            Myunion(find(u), find(v));
            i++;
        }

        included[k] = 1;
    }

    printf("Spanning Tree\n");
    for (i = 0; i < n - 1; i++)
    {
        printf("(%d,%d)\n", t[0][i], t[1][i]);
    }
    return 0;
}