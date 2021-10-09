#include <stdio.h> //row-major
#include <stdlib.h>

void main()
{
    int *A, n, ch, x, i, j;
    printf("enter dimensions");
    scanf("%d", &n);
    A = (int *)malloc((n * (n + 1)) / 2 * sizeof(int));
    do
    {
        printf("1.create\n");
        printf("2.get\n");
        printf("3.set\n");
        printf("4.display\n");
        printf("enter choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter elements of whole matrix:\n");
            for (i = 1; i <= n; i++)
            {
                for (j = 1; j <= n; j++)
                {

                    scanf("%d", &x);
                    if (i >= j)
                    {
                        A[(i * (i - 1)) / 2 + j - 1] = x;
                    }
                }
            }
            break;

        case 2:
            printf("enter indices:");
            scanf("%d %d", &i, &j);
            if (i >= j)
                printf("%d", A[(i * (i - 1)) / 2 + j - 1]);
            else
                printf("%d", A[(j * (j - 1)) / 2 + i - 1]);

            break;
        case 3:
            printf("enter row,column and element");
            scanf("%d%d%d", &i, &j, &x);
            if (i >= j)
                A[(i * (i - 1)) / 2 + j - 1] = x;
            else
                A[(j * (j - 1)) / 2 + i - 1] = x;
            break;
        case 4:
            for (i = 1; i <= n; i++)
            {
                for (j = 1; j <= n; j++)
                {
                    if (i >= j)
                        printf("%d ", A[(i * (i - 1)) / 2 + j - 1]);
                    else
                        printf("%d ", A[(j * (j - 1)) / 2 + i - 1]);
                }
                printf("\n");
            }
            break;
        }

    } while (ch >= 1 && ch <= 4);
}