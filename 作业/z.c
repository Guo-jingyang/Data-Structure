#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int elem;
    struct Node *next;
};
typedef struct Node NODE;

int AppendNode(NODE *, int item);
int FreeList(NODE *);
int PrintList(NODE *);

int main(void)
{
    // 头结点
    NODE *list = malloc(sizeof(NODE));
    if (!list) return 0;
    list->elem = 0;
    list->next = NULL;
    
    for (int i=0; i<5; i++)
    {
        AppendNode(list, i+1);
    }

    PrintList(list->next);
    FreeList(list);
    return 1;
}

int AppendNode(NODE *list, int item)
{
    NODE *q = malloc(sizeof(NODE));
    q->elem = item;
    q->next = NULL;

    NODE *p;
    for (p=list; p->next!=NULL; p=p->next);
    p->next = q;
    return 1;
}

int FreeList(NODE *list)
{
    NODE *p = list;
    while (p)
    {
        NODE *temp = p->next;
        free(p);
        p = temp;
    }
    return 1;
}

int PrintList(NODE *list)
{
    NODE *p;
    for (p=list; p!=NULL; p=p->next)
    {
        printf("%d\n", p->elem);
    }
    return 1;
}