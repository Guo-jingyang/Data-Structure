#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node 
{
    int elem;
    struct Node *next;
};
typedef struct Node NODE;

int InsertNode(NODE *, int item);
int ReturnLastk(NODE *, int k);
int FreeList(NODE *);

int main(void)
{
    char line[1024];
    NODE *list = malloc(sizeof(NODE));
    list->elem = 0;
    list->next = NULL;
    while (fgets(line, sizeof(line), stdin))
    {
        char *token = strtok(line, " \n");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
        int k = atoi(token);
        token = strtok(NULL, " \n");
        while (token != NULL)
        {
            InsertNode(list, atoi(token));
            token = strtok(NULL, " \n");
        }
        printf("%d\n", ReturnLastk(list, k));
    }
    FreeList(list); //无限循环，但过了OJ
    return 1;
}

int InsertNode(NODE *list, int item)
{
    NODE *p, *q = list;
    for (p=list->next; p!=NULL && p->elem<=item; q=p, p=p->next)
    {
        if (p->elem == item) return 0;
    }


    NODE *r = malloc(sizeof(NODE));
    r->elem = item;
    q->next = r;
    r->next = p;
    return 1;
}

int ReturnLastk(NODE *list, int k)
{
    NODE *p, *q = list;
    int i = 1;
    for (p=list; p!=NULL; p=p->next)
    {
        if (i>k) q = q->next;
        i++;
    }

    return q->elem;
}

int FreeList(NODE *list)
{
    NODE *p = list;
    while (p)
    {
        NODE *temp = p;
        p = p->next;
        free(temp);
    }

    return 1;
}

