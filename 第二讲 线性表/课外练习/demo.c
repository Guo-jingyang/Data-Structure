#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
typedef int Status; // 感觉不是很有必要啊

#define INIT_SIZE 10
#define INCREMENT_SIZE 5

//
typedef int Elemtype;
typedef struct
{
    Elemtype *elem;
    int length; // 线性表中元素个数
    int size; // 感觉用size表述不是很准确, 应该理解为pre_length
    //为了防止空间不足, 提前索要多余空间
} SqList;


Status InitList(SqList *);
Status DestroyList(SqList *);
Status ClearList(SqList *);

Status ListEmpty(SqList);
Status ListLength(SqList);

Status GetElem(const SqList, int, Elemtype *);
Status LocateElem(const SqList, Elemtype , int *());

Status PriorElem(SqList L, Elemtype, Elemtype *);
Status NextElem(SqList L, Elemtype, Elemtype *);

Status InsertElem(SqList *, int, Elemtype);
Status DeleteElem(SqList *, int, Elemtype *);


int main(void)
{
    SqList L;
    if (InitList(&L))
    {
        printf("Init_success\n");
        for (int i=0; i<10; i++)
        {
            InsertElem(&L, i+1, i);
        }
        printf("Length is %d\n", getLength(L));
    
        Elemtype e;
        if (GetElem(L, 1, &e))
        {
            printf("The first element is %d\n", e);
        }
        else
        {
            printf("element is not exist\n");
        }

        if (DestroyList(&L)) printf("\nDestroy_success\n");

    }
    //
    return 0;
}


Status InitList(SqList *L)
{
    L->elem = malloc(sizeof(Elemtype) * INIT_SIZE);
    if (!L->elem) return ERROR;

    L->length = 0;
    L->size = INIT_SIZE;
    return OK;
}
Status DestroyList(SqList *L)
{
    free(L->elem);
    L->length = 0;
    L->size = 0;
    return OK;
}
Status ClearList(SqList *L)
{

}

Status ListEmpty(SqList L)
{

}
Status ListLength(SqList L)
{

}

Status GetElem(const SqList L, int i, Elemtype *e)
{
    if (i < 1 || i > L.length) return ERROR;

    *e = L.elem[i - 1]; // 无需再取地址, []已包含
    return OK;
}
Status LocateElem(const SqList, Elemtype , int *())
{

}

Status PriorElem(SqList L, Elemtype, Elemtype *)
{

}
Status NextElem(SqList L, Elemtype, Elemtype *)
{

}

Status InsertElem(SqList *L, int i, Elemtype e) //i指序号
{
    Elemtype *new;
    if (i < 1 || i > L->length + 1) return ERROR;
    // i=1时, 所有元素向后移动; i=length+1时, 在线性表末尾添加元素, 元素无需移动
    if (L->length >= L->size)
    {
        new = realloc(L->elem, (L->size + INCREMENT_SIZE) * sizeof(Elemtype));
        if (!new) return ERROR;
        L->elem = new;
        L->size += INCREMENT_SIZE;
    }

    Elemtype *p = &L->elem[i - 1]; // 索引
    Elemtype *q = &L->elem[L->length - 1]; // 最后一个元素的索引
    for (; q>=p; q--)
    {
        *(q + 1) = *q; //总是有多余的空间, 所以q+1是合理的
    }
    *p = e;
    ++L->length;
    return OK;
}
Status DeleteElem(SqList *L, int i, Elemtype *e)
{
    if (i < 1 || i > L->length) return ERROR;

    Elemtype *p = &L->elem[i - 1];
    Elemtype *q = &L->elem[L->length - 1];
    /* *e = *p */
    for (; p<=q; p++)
    {
        *p = *(p+1);
    }
    --L->length;
    return OK;
}
Status TraverseList(SqList L)
{

}
