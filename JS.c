#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data[1001];
    int top;
}Sqtack;

Sqtack* Init();
void Push(Sqtack* s, int num, int m);
void Pop(Sqtack*s);
int IsFull(Sqtack* s, int m);
int IsEmpty(Sqtack* s);

int main()
{
    Sqtack* s = Init();
    int m,n,k; //m为栈的最大存储量，n为检测的数字个数（从1开始到n），k为检测的序列个数
    int i, j;
    int t = 1;
    int num[1001];
    scanf("%d%d%d", &m,&n,&k);
    for(i = 0; i < k; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &num[j]);
        }
        j = 0;
        while(j < n)
        {
            if(s->data[s->top] == num[j])
            {
                Pop(s);
                j++;
            }
            else
            {
                if(IsFull(s, m))
                {

                    break;
                }
                Push(s, t++, m);
            }
        }
        if(!IsEmpty(s))
            printf("NO\n");
        else
            printf("YES\n");
        t = 1;
        s = Init();
    }
    return 0;
}

Sqtack* Init()
{
    Sqtack* s = (Sqtack*)malloc(sizeof(Sqtack));
    s->top = -1;
    s->data[0] = 0;
    return s;
}

int IsFull(Sqtack* s, int m)
{
    return (s->top == m - 1);
}

int IsEmpty(Sqtack* s)
{
    return (s->top == -1);
}
void Push(Sqtack* s, int num, int m)
{
    if(IsFull(s, m))
    {
        printf("NO");
        return;
    }
    s->data[++(s->top)] = num;
}

void Pop(Sqtack* s)
{
    if(IsEmpty(s))
    {
        printf("Fail");
        return;
    }
    s->top--;
}

