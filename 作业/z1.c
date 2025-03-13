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
int InsertNode(NODE *, int item);
int ReturnLastk(NODE *, int k);

int main(void)
{
    // 头结点
    NODE *list = malloc(sizeof(NODE));
    if (!list) return 0;
    list->elem = 0;
    list->next = NULL;
    
    for (int i=0; i<5; i++)
    {
        AppendNode(list, 3*i+1);
    }

    PrintList(list);
    printf("-----------------------------\n");
    printf("Last k: %d", ReturnLastk(list, 2));
    FreeList(list);
    return 1;
}

int AppendNode(NODE *list, int item)
{
    NODE *q = malloc(sizeof(NODE));
    if (!q) return 0;
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
    for (p=list->next; p!=NULL; p=p->next)
    {
        printf("%d\n", p->elem);
    }
    return 1;
}

int InsertNode(NODE *list, int item)
{
    NODE *p, *q=list;
    for (p=list->next; p->elem<item && p!=NULL; q=p, p=p->next);

    NODE *r = malloc(sizeof(NODE));
    if (!r) return 0;
    r->elem = item;
    r->next = p;
    q->next = r;
    return 1;
}

int ReturnLastk(NODE *list, int k)
{
    int i = 1;
    NODE *p, *q = list;
    for (p=list; p!=NULL; p=p->next)
    {
        if (i>k) q=q->next;
        i++;
    }

    return q->elem;
}

// (elem, p) (elem, next) (elem, NULL)