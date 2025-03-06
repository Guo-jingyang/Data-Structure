/*问题：编写程序统计一个文件中每个单词的出现
次数（词频统计），并按字典序输出每个单词及
出现次数。*/

//函数之间的嵌套关系要搞清楚

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1024
#define MAX_WORD 32
int n = 0;
typedef struct
{
    char word[MAX_WORD];
    int count;
} ElemType;

int GetWord(FILE *fp, char *w);
int SearchWord(ElemType list[], char *w);
int InsertWord(ElemType list[], char *w);

int main(void)
{
    ElemType list[MAX_SIZE];
    FILE *fp = fopen("test.txt", "r+");
    if (fp == NULL) {
        fprintf(stderr, "Error: Cannot open file.\n");
        return 0;
    }
    char w[MAX_WORD]; //副本,传参时w始终指向数组第一个元素
    while (GetWord(fp, w)!=EOF) {
        InsertWord(list, w);
    }

    for (int i=0; i<n; i++) {
        printf("%s %d\n", list[i].word, list[i].count);
    }
    fclose(fp);
    return 0;
}

int GetWord(FILE *fp, char *w)
{
    int ch;
    while (!isalpha(ch=fgetc(fp))) {
        if (ch == EOF) return ch;
        else continue;
    }
    int i = 0;
    do {
        if (i<MAX_WORD - 1) { //'\0'
            w[i] = tolower(ch);
            i++; //单词可能会过长造成溢出
        }
        else {
            fprintf(stderr, "Warning: Word overflow.\n");
        }
    } while (isalpha(ch=fgetc(fp)));
    w[i] = '\0'; //注意

    return 1;
}

int SearchWord(ElemType list[], char *w)
{
    int low = 0, high = n-1, mid;
    while (low<=high) {
        mid = (low+high)/2;
        if (strcmp(w, list[mid].word)<0) {
            high = mid -1;
        }
        else if (strcmp(w, list[mid].word)>0) {
            low = mid +1;
        }
        else {
            return mid;
        }
    }

    return low;
}

int InsertWord(ElemType list[], char *w)
{
    if (n == MAX_SIZE) {
        fprintf(stderr, "Error: List is full.\n");
        return 0;
    }
    int i = SearchWord(list, w);
    if (strcmp(list[i].word, w)==0) {
        list[i].count++;
    }
    else {
        for (int k=n; k>i; k--)
        {
            list[k] = list[k-1];
        }
        strcpy(list[i].word, w);
        list[i].count = 1;
        n++;
    }

    return 1;
}

