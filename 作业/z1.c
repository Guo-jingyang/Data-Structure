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
    NODE *r = malloc(sizeof(NODE));
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

    NODE *list = malloc(sizeof(NODE));
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

    int flag = 0;
    int is_merged = 0;
    int count = 0;

    char input[1024];
    while (fgets(input, sizeof(input), stdin)!=NULL)
    {
        char *token = strtok(input, " \n");
        int n = atoi(token);
        flag = 0;

        if (is_merged == 0)
        {
            if (list->space >= n) //先检测头空白区
            {
                list->space -= n;
                printf("%d\n", list->space);
                if (list->space == 0)
                {
                    NODE *temp = list;
                    list->prev->next = list->next;
                    list->next->prev = list->prev;
                    list = list->next;
                    free(temp);
                }
                flag = 1;
                continue;
            }

            NODE *q = list->prev, *p = list->next;
            while (q!=list && p!=list)
            {
                if (q->space>=n)
                {
                    q->space -= n;
                    printf("%d\n", q->space);
                    if (q->space == 0)
                    {
                        q->prev->next = q->next;
                        q->next->prev = q->prev;
                        free(q);
                    }
                    flag = 1;
                    break;
                }

                else if (p->space>=n)
                {
                    p->space -= n;
                    printf("%d\n", p->space);
                    if (p->space == 0)
                    {
                        p->prev->next = p->next;
                        p->next->prev = p->prev;
                        free(p);
                    }
                    flag = 1;
                    break;
                }

                q = q->prev;
                p = p->next;
            }
        }

        if (flag == 0)
        {
            if (is_merged == 0)
            {
                NODE *p;
                for (p=list; p->next!=list; p=p->next)
                {
                    count += p->space;
                }
                count += p->space;
                is_merged = 1;
            }

            if (count>=n)
            {
                count -= n;
                printf("%d\n", count);
            }
            else
            {
                printf("memory out\n");
            }
        }
    }

    //
    return 0;
}