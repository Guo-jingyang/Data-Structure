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





    int merged_size = -1;
    int size;

    char input[1024];
    while (fgets(input, sizeof(input), stdin) != NULL)
    {
        char *token = strtok(input, " \n");
        int n = atoi(token);


        if (merged_size == -1)
        {
            if (list->space>=n)
            {
                list->space -= n;
                printf("%d\n", list->space);
                if (list->space == 0)
                {
                    if (list->next != list)
                    {
                        NODE *temp = list;
                        list->next->prev = list->prev;
                        list->prev->next = list->next;
                        list = list->next;
                        free(temp);
                    }

                    else
                    {
                        free(list);
                        merged_size = 0;
                    }
                }

                continue;
            }


            NODE *q = list->prev;
            NODE *p = list->next;
            size = list->space;

            while (q != list) //
            {
                size += q->space; //

                if (q->space >= n)
                {
                    q->space -= n;
                    printf("%d\n", q->space);
                    if (q->space == 0)
                    {
                        q->prev->next = q->next;
                        q->next->prev = q->prev;
                        free(q);
                    }
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
                    break;
                }

                q = q->prev;
                p = p->next;
            }


            if (q == list) //
            {
                merged_size = size;
                if (merged_size >= n)
                {
                    merged_size -= n;
                    printf("%d\n", merged_size);
                }
                else printf("memory out\n");
            }
        }

        else // 已经进行过内存合并则执行 
		{
			if (merged_size >= n)
			{
				merged_size -= n;
				printf("%d\n", merged_size);
			}
			else printf("memory out\n");
		}
    }

    //
    return 0;
}