#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Adjnode
{
    int vex;
    struct Adjnode *next;
} ADJNODE;

typedef struct Node
{
    ADJNODE *list;
} NODE;

ADJNODE *insert(ADJNODE *list, int v)
{
    ADJNODE *q = malloc(sizeof(ADJNODE));
    q->vex = v;
    q->next = NULL;

    if (list == NULL) return q;

    ADJNODE *p;
    for (p=list; p->next!=NULL; p=p->next);
    p->next = q;

    return list;
}

void freelist(NODE *graph, int n)
{
    ADJNODE *list;
    for (int i=0; i<n; i++)
    {
        list = graph[i].list;
        ADJNODE *p = list;
        while (p)
        {
            ADJNODE *temp = p;
            p=p->next;
            free(temp);
        }
    }
}

void DFS(NODE *graph, int start, int end, int **res, int *row, int *cols, int *c, int *path, int *visited)
{
    if (visited[start] == 1) return;

    if (start == end)
    {
        res[*row] = malloc(sizeof(int)*(*c));
        memcpy(res[*row], path, sizeof(int)*(*c));
        cols[*row] = *c;
        (*row) ++;
        return;
    }

    visited[start] = 1;
    path[*c] = start;
    (*c) ++;

    ADJNODE *p;
    for (p=graph[start].list; p!=NULL; p=p->next)
    {
        DFS(graph, p->vex, end, res, row, cols, c, path, visited);
    }

    (*c) --;
    visited[start] = 0;
}

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);

    NODE graph[n+1];
    memset(graph, 0, sizeof(graph));

    for (int i=0; i<m; i++)
    {
        int s, t;
        scanf("%d %d", &s, &t);
        graph[s].list = insert(graph[s].list, t);
    }

    // 函数参数
    int start = 1, end = n;
    int **res = malloc(sizeof(int*)*2000), row = 0, *cols = malloc(sizeof(int)*n);
    int c = 0, *path = malloc(sizeof(int)*n);
    int *visited = calloc(n+1, sizeof(int));

    DFS(graph, start, end, res, &row, cols, &c, path, visited);

    if (row == 0)
    {
        printf("%d", -1);
        return 0;
    }

    for (int i=0; i<row; i++)
    {
        for (int j=0; j<cols[i]; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("%d\n", end);
    }

    for (int i=0; i<row; i++) free(res[i]);
    free(cols);
    free(path);
    freelist(graph, n+1);
    return 0;
}