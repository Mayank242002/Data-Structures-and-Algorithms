#include <stdio.h> //row-major
#include <stdlib.h>

void main()
{
    int *A, n, ch, x, i, j;
    printf("enter dimensions");
    scanf("%d", &n);
    A = (int *)malloc((3 * n - 2) * sizeof(int));
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
                    if (i - j == 0)
                        A[n + i - 2] = x;
                    else if (i - j == 1)
                        A[i - 2] = x;
                    else if (i - j == -1)
                        A[2 * n + i - 2] = x;
                }
            }
            break;

        case 2:
            printf("enter indices:");
            scanf("%d %d", &i, &j);
            if (i - j == 0)
                printf("%d ", A[n + i - 2]);
            else if (i - j == 1)
                printf("%d ", A[i - 2]);
            else if (i - j == -1)
                printf("%d ", A[2 * n + i - 2]);
            else
                printf("0 ");
            break;
        case 3:
            printf("enter row,column and element");
            scanf("%d%d%d", &i, &j, &x);
            if (i - j == 0)
                A[n + i - 2] = x;
            else if (i - j == 1)
                A[i - 2] = x;
            else if (i - j == -1)
                A[2 * n + i - 2] = x;

            break;
        case 4:
            for (i = 1; i <= n; i++)
            {
                for (j = 1; j <= n; j++)
                {
                    if (i - j == 0)
                        printf("%d ", A[n + i - 2]);
                    else if (i - j == 1)
                        printf("%d ", A[i - 2]);
                    else if (i - j == -1)
                        printf("%d ", A[2 * n + i - 2]);
                    else
                        printf("0 ");
                }
                printf("\n");
            }
            break;
        }

    } while (ch >= 1 && ch <= 4);
}