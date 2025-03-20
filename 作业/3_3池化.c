#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int max(int n, int matrix[][n], int x, int y, int k1, int k2)
{
    int item = matrix[x][y];
    for (int i=x; i<x+k1; i++)
    {
        for (int j=y; j<y+k2; j++)
        {
            if (matrix[i][j] > item)
            {
                item = matrix[i][j];
            }
        }
    }

    return item;
}

int main(void)
{
    int n,k1,k2,t1,t2;
    scanf("%d %d %d %d %d", &n,&k1,&k2,&t1,&t2);
    int matrix[2][n];
    for (int i=0; i<2; i++)
    {
        for (int j=0; j<n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    int r1 = 0, c1 = 0, c2 = k2-1; // 索引
    if (k1 == 2)
    {
        while (c2 <= n-1)
        {
            printf("%d ", max(n, matrix, r1, c1, k1, k2));
            c1 += t2;
            c2 += t2;
        }
    }

    else
    {
        while (c2 <= n-1)
        {
            printf("%d ", max(n, matrix, r1, c1, k1, k2));
            c1 += t2;
            c2 += t2;
        }

        if (t2 == 1)
        {
            r1 = 1, c1 = n-k2;
            while (c1 >= 0)
            {
                printf("%d ", max(n, matrix, r1, c1, k1, k2));
                c1 -= t2;
            }
        }
    }


    //
    return 0;
}