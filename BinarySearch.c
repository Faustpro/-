#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct
{
    ElemType data[10];
    int length;
}Array;

int BinarySearch(const Array* a, ElemType num);

int main()
{
    Array* a = (Array*)malloc(sizeof(Array));
    a->data[0] = 0; //第一个位置用于存放哨兵
    a->length = 0;
    int i, j;
    for(i = 1; i < 5; i++)
    {
        a->data[i] = i;
        a->length++;
    }

    printf("%d", BinarySearch(a,3));
    return 0;
}

int BinarySearch(const Array* a, ElemType num)
{
    int left, mid, right;
    left = 1;
    right = a->length;

    while(left <= right)
    {
        mid = (left + right) / 2;
        if(a->data[mid] > num)
            right = mid - 1;
        else if(a->data[mid] < num)
            left = mid + 1;
        else
            return mid;
    }
    return 0;
}

