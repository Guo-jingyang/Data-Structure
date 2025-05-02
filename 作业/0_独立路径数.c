#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Adjnode
{
    int vex;
    int edge;
    struct Adjnode *next;
} ADJNODE;

typedef struct Node
{
    ADJNODE *list;
} NODE;



int main(void)
{
    int n, e;
    scanf("%d %d", &n, &e);
    for (int i=0; i<e; i++)
    {
        
    }

    //
    return 0;
}