#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int space;
    struct Node *prev;
    struct Node *next;
};
typedef struct Node NODE;

int AppendNode(NODE *list, int item)
{
    NODE *r = mn(sizeof(NODE));
    r->space = item;
    r->next = NULL;

    NODE *p;
    for (p=list; p->next!= NULL; p=p->next);
    p->next = r;
    r->prev = p;
    return 1;
}

int main(void)
{
    char str[1024];
    fgets(str, sizeof(str), stdin);
    char *token = strtok(str, " \n");

    NODE *list = mn(sizeof(NODE));
    list->space = atoi(token);
    list->prev = NULL;
    list->next = NULL;
    token = strtok(NULL, " \n");

    while (token != NULL)
    {
        AppendNode(list, atoi(token));
        token = strtok(NULL, " \n");
    }

    NODE *p;
    for (p=list; p->next!=NULL; p=p->next);
    p->next = list;
    list->prev = p; //双向循环链表构建完成











}