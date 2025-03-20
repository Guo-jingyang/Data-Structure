#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int top = -1;

int push(char *stack, char item)
{
    stack[top+1] = item;
    top++;

    return 1;
}

char pop(char *stack)
{
    if (top==-1) return '\0';
    char item = stack[top];
    top--;
    return item;
}

int grade(char ch)
{
    switch(ch)
    {
        case '>':
        case '<': return 0;
        case '+':
        case '-': return 1;
        case '*':
        case '/':
        case '%': return 2;
    }
}

int main(void)
{
    char ch;
    char stack[1024];
    while ((ch=getchar())!='=')
    {
        if (isalpha(ch))  // 操作数
        {
            printf("%c", ch);
        }

        else  // 符号
        {
            if (ch == '(')
            {
                push(stack, ch);
            }

            else if (ch == ')')
            {
                char e;  // 记录栈内的元素
                while ((e=pop(stack)) != '(')
                {
                    printf("%c", e);
                }
                // '(' 出栈但不输出
            }

            else  // 其他运算符
            {
                if (top!=-1 && stack[top]!='(' && grade(ch)<=grade(stack[top]))
                {
                    char e = pop(stack);
                    printf("%c", e);
                }
                push(stack, ch);
            }
        }
    }

    while (top != -1)
    {
        printf("%c", stack[top--]);
    }

    //
    return 0;
}