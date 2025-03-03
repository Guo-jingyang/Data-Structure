#include <stdio.h>
#include <stdlib.h>

int n = 1;

void change(void)
{
    n++;
}

int main(void)
{
    change();
    printf("%d", n);

    return 0;
}