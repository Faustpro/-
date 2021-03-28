#include <stdio.h>

void  quicksort(int left, int right);

int a[101], n;

int main()
{
    int i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    quicksort(0, n - 1);
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}

void quicksort(int left, int right)
{
    int i, j, temp;
    int t;
    if(left > right)
        return ;
    temp = a[left]; //存储基准值
    i = left;  //i负责寻找比基准值大的数
    j = right; //j负责寻找比基准值小的数
    while(i != j)
    {
        while(a[j] >= a[temp] && j > i) //先从右往左找
            j--;
        while(a[i] <= a[temp] && i < j)
            i++;
        if(i < j)
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    a[left] = a[i];
    a[i] = temp;
    quicksort(left, i - 1);
    quicksort(i + 1, right);
}