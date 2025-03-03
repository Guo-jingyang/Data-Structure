#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 100

typedef struct
{
    double p; //系数
    int e; //指数
} ElemType; //定义多项式(Polynomial)中的一个元素

typedef struct 
{
    ElemType elem[INIT_SIZE];
    int length;
} SqList;

int main(void)
{

    return 0;
}