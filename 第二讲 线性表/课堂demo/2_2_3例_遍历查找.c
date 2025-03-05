/*已知长度为 n 的非空线性表 list 采用顺序存
储结构,并且数据元素按值的大小非递减排列(有
序)，写一算法,在该线性表中插入一个数据元素
item,使得线性表仍然保持按值非递减排列。*/

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MAX_SIZE 100
int n;

int SearchSite(int list[], int item);
int InsertElem(int list[], int item);

int main(void)
{
    int list[MAX_SIZE];
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &list[i]);
    }
    int item;
    scanf("%d", &item);

    if (InsertElem(list, item))
    {
        for (int i=0; i<n; i++)
        {
            printf("%d ", list[i]);
        }
    }
    else
        printf("Fail\n");
    //
    return 0;
}

int SearchSite(int list[], int item)
{
    for (int i=0; i<n; i++)
    {
        if (item < list[i])
        {
            return i;
        }
    }
    return n;
}

int InsertElem(int list[], int item)
{
    if (n == MAX_SIZE) return ERROR;
    int i = SearchSite(list, item);

    for (int k=n; k>i; k--)
    {
        list[k] = list[k-1];
    }
    list[i] = item;
    n++;
    return OK;
}