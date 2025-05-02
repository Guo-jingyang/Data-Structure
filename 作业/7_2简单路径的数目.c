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

void DFS(NODE *graph, int start, int M, int *visited, int *count, int length)
{
    if (visited[start] == 1) return;

    if (length == M)
    {
        (*count) ++;
        return;
    }

    visited[start] = 1;

    ADJNODE *p;
    for (p=graph[start].list; p!=NULL; p=p->next)
    {
        DFS(graph, p->vex, M, visited, count, length+1);
    }

    visited[start] = 0;  // 回溯
}

int main(void)
{
    int n, m, start, M;
    scanf("%d %d %d %d", &n, &m, &start, &M);

    NODE graph[n+1];
    memset(graph, 0, sizeof(graph));

    for (int i=0; i<m; i++)
    {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph[v1].list = insert(graph[v1].list, v2);
    }

    int *visited = calloc(n+1, sizeof(int));
    int count = 0;
    int length = 0;

    DFS(graph, start, M, visited, &count, length);
    printf("%d", count);
    
    free(visited);
    return 0;
}