#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *lchild, *rchild;
};
typedef struct Node NODE;

NODE *buildtree(int *inorder, int *preorder, int n)
{
    if (n == 0) return NULL;

    NODE *t = malloc(sizeof(NODE));
    t->val = preorder[0];
    t->lchild = t->rchild = NULL;

    int index;
    for (index=0; index<n; index++)
    {
        if (inorder[index]==t->val) break;
    }

    int leftlen = index;
    int rightlen = n - index - 1;

    int *leftinorder = inorder;
    int *leftpreorder = preorder + 1;

    int *rightinorder = inorder + index + 1;
    int *rightpreorder = preorder + 1 + index;

    t->lchild = buildtree(leftinorder, leftpreorder, leftlen);
    t->rchild = buildtree(rightinorder, rightpreorder, rightlen);

    return t;
}

void posttraversal(NODE *t)
{
    if (t == NULL) return;

    posttraversal(t->lchild);
    posttraversal(t->rchild);
    printf("%d ", t->val);
}

void freetree(NODE *t)
{
    if (t == NULL) return;
    freetree(t->lchild);
    freetree(t->rchild);
    free(t);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int inorder[n], preorder[n];
    for (int i=0; i<n; i++)
    {
        scanf("%d", &inorder[i]);
    }
    for (int i=0; i<n; i++)
    {
        scanf("%d", &preorder[i]);
    }
    NODE *t = buildtree(inorder, preorder, n);
    posttraversal(t);
    freetree(t);
    return 0;
}
