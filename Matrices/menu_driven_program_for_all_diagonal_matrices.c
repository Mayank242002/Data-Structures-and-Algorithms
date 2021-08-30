#include <stdio.h>
#include <stdlib.h>

void main()
{
    int *A, n, ch, x, i, j;
    printf("enter dimensions");
    scanf("%d", &n);
    A = (int *)malloc(n * sizeof(int));
    do
    {
        printf("1.create");
        printf("2.get");
        printf("3.set");
        printf("4.display");
        printf("enter choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            for (i = 1; i <= n; i++)
                scanf("%d", &A[i - 1]);
            break;

        case 2:
            printf("enter indices:");
            scanf("%d %d", &i, &j);
            if (i == j)
                printf("%d", A[i - 1]);
            else
                printf("0");
            break;
        case 3:
            printf("enter row,column and element");
            scanf("%d%d%d", &i, &j, &x);
            if (i == j)
                A[i - 1] = x;
            break;
        case 4:
            for (i = 1; i <= n; i++)
            {
                for (j = 1; j <= n; j++)
                {
                    if (i == j)
                        printf("%d ", A[i - 1]);
                    else
                        printf("0 ");
                }
                printf("\n");
            }
        }

    } while (ch >= 1 && ch <= 4);
}