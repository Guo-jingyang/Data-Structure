#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_NUMBERS 50

void arrange(int *numbers, int count);

int main(void)
{
    char input[MAX_LINE_LENGTH];
    int numbers[MAX_NUMBERS];

    while (fgets(input, sizeof(input), stdin) != NULL)
    {
        int num, count = 0;
        char *token = strtok(input, " ");
        while (token != NULL)
        {
            num = atoi(token);
            numbers[count++] = num;
            token = strtok(NULL, " ");
        }

        //排列
        arrange(numbers, count);

        //输出
        //printf("%d\n", count);
        for (int i=0; i<count; i++)
        {
            printf ("%d", numbers[i]);
            if (i < count-1){
                printf(" ");
            }
        }
        printf("\n");
        return 0;
    }

    //
    return 0;
}

void arrange(int *numbers, int count)
{
    
}

//得考虑负数，而且-1/3余数是2