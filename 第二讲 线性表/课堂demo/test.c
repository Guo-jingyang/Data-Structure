#include <stdio.h>
#include <string.h>

int main()
{
    char str1[] = "Hello World!";
    char str2[20];
    strcpy(str2, str1);
    printf("str1=%s\n", str1);
    printf("str2=%s\n", str2);


    return 0;
}