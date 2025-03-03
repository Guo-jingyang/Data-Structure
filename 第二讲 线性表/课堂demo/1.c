#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR -1

#define MAX_SIZE 100

typedef struct 
{
    int num;
} ElemType; //定义元素类型

//1.查找
int SearchElem_1(ElemType list[], int n, int item); //确定元素item在长度为n的 “无序” 顺序表list中的位置
int SearchElem_2(ElemType list[], int n, int item); //确定元素item在长度为n的 “有序” 顺序表list中的位置

//2.插入， 0 <= i <= n
int InsertElem(ElemType list[], int n, int i, int item); //在第i个索引位置插入元素item

//3.删除
int DeleteElem(ElemType list[], int n, int i); //删除长度为n的顺序表list的某个数据元素

int main(void)
{
    ElemType list[MAX_SIZE]; //定义顺序表
    int n; //实时记录顺序表中的元素 “个数”

    return 0;
}

int SearchElem_1(ElemType list[], int n, int item)
{
    for (int i=0; i<n; i++)
    {
        if (list[i].num == item)
        {
            return i;
        }
    }
    return ERROR;
}

int SearchElem_2(ElemType list[], int n, int item) //顺序表升序排列
{
    int low = 0, high = n-1, mid; //n-1
    while(low <= high)
    {
        mid = (low + high) / 2;
        if (item < list[mid].num)
        {
            high = mid - 1;
        }
        else if (item > list[mid].num)
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return ERROR;
}

int InsertElem(ElemType list[], int n, int i, int item)
{
    if (n==MAX_SIZE || i<0 || i>n)
    return ERROR;
    for (int k=n; k>i; k--)
    {
        list[k].num = list[k-1].num;
    }
    list[i].num = item;
    n++;
    return OK;
}

int DeleteElem(ElemType list[], int n, int i)
{
    if (i<0 || i>n-1)
    return ERROR;
    for (int k=i; k<n-1; k++) //n-1
    {
        list[k].num = list[k+1].num;
    }
    n--;
    return OK;
}

