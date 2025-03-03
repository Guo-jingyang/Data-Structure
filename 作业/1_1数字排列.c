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
        //读入数据
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
    int low = 0, mid = 0, high = count - 1;
    while (mid <= high)
    {
        int mod = numbers[mid] % 3;
        if (mod == 2 || numbers[mid] == -1)
        {
            int temp = numbers[low];
            numbers[low] = numbers[mid];
            numbers[mid] = temp;
            low++;
            mid++;
        }

        else if (mod == 0)
        {
            mid++;
        }

        else if (mod == 1 || numbers[mid] == -2)
        {
            int temp = numbers[mid];
            numbers[mid] = numbers[high];
            numbers[high] = temp;
            high--;
        }
    }
}

// 注意负数的情况
// 算法：三路划分算法
// 母题：荷兰国旗问题