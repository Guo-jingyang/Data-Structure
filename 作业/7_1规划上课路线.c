#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    char map[n][m];
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            scanf("%c", &map[i][j]);
        }
    }
    



    return 0;
}