// 按照课件的形式：单纯用数组实现顺序表，不使用malloc()，顺序表的size固定不变
// 引入全局变量来记录顺序表的长度（顺序表中的元素个数）
// i表示索引位置

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MAX_SIZE 100
int n; //记录顺序表长度，即顺序表中元素的个数

// 1.查找：确定元素item在长度为n的顺序表list中的位置
int SearchElem_1(int list[], int item); //顺序查找法
int SearchElem_2(int list[], int item); //折半查找法，一定要先明确数据元素是否按从小到大排列！！！

// 2.插入：在长度为n的顺序表list的第i个位置上插入一个新的数据元素item
int InsertElem(int list[], int i, int item);

// 3.删除：删除长度为n的顺序表list中索引位置为i的数据元素
int DeleteElem(int list[], int i);

int main(void)
{
    int list[MAX_SIZE];

    return 0;
}

int SearchElem_1(int list[], int item)
{
    for (int i=0; i<n; i++)
    {
        if (list[i] == item)
        return i;
    }
    return ERROR;
}

int SearchElem_2(int list[], int item)
{
    int low = 0, high = n-1, mid;
    while (low <= high) //循环边界的确定是难点
    {
        mid = (low + high)/2;
        if (item < list[mid])
        {
            high = mid-1;
        }
        
        else if (item > list[mid])
        {   
            low = mid+1;
        }
            
        else
            return mid;
    }

    return ERROR;
}

int InsertElem(int list[], int i, int item)
{
    if (i<0 || i>n || n==MAX_SIZE) return ERROR;
    for (int k=n; k>i; k--)
    {
        list[k] = list[k-1];
    }
    list[i] = item;
    n++; //更新顺序表长度！
    return OK;
}

int DeleteElem(int list[], int i)
{
    if (i<0 || i>n-1) return ERROR;
    for (int k=i; k<n-1; k++)
    {
        list[k] = list[k+1];
    }
    n--; //更新顺序表长度！
    return OK;
}



