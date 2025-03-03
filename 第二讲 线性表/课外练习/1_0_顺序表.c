#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define INIT_SIZE 100
#define INCREMENT 50

typedef int Status;
typedef int ElemType;
typedef struct{
    ElemType *elem;
    int length;
    int size;
} SqList;

Status InitList(SqList *);
Status DestoryList(SqList *);
Status InsertElem(SqList *, int, ElemType);
Status DeleteElem(SqList *, int i);

int main(void)
{
    SqList L;
    InitList(&L);
    //
    DestroyList(&L);
    return 0;
}

Status InitList(SqList *pL)
{
    pL->elem = malloc(sizeof(ElemType)*INIT_SIZE);
    if (pL->elem == NULL) return OVERFLOW;
    pL->length = 0;
    pL->size = INIT_SIZE;
    return OK;
}

Status DestroyList(SqList *pL)
{
    free(pL->elem);
    pL->elem = NULL;
    pL->length = pL->size = 0;
    return OK;
}

Status InsertElem(SqList *pL, int i, ElemType e) //定义i为第几个位置
{
    if (i<1 || i>pL->length+1) return ERROR;
    if (pL->length>=pL->size){
        SqList *temp = realloc(pL->elem, sizeof(ElemType)*(pL->size+INCREMENT));
        if (temp == NULL) return OVERFLOW;
        pL->elem = temp;
        pL->size += INCREMENT;
        }
    for (int k=pL->length; k>=i; k--){
        pL->elem[k] = pL->elem[k-1];
    }
    pL->elem[i-1] = e;
    pL->length++;
    return OK;
}

Status DeleteElem(SqList *pL, int i) //定义i为第几个位置
{
    if (i<1 || i>pL->length) return ERROR;
    for (int k=i-1; k<pL->length-1; k++) {
        pL->elem[k] = pL->elem[k+1];
    }
    pL->length -= 1;
    return OK;
}