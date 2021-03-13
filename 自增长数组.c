#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define BLOCK 20
typedef struct{
    int *array;
    int size;
}Array;

Array Array_creat(); //结构体初始化
int* Array_at(const Array *a, int index);//元素查询
void Array_free(Array *a);
int Array_size(const Array *a);
void Array_inflact(Array *a, int more_size);

int main()
{
    Array a = Array_creat(100);
    int cnt = 0;
    int number = 0;
    int i;
    while(number != -1)
    {
        scanf("%d", &number);
            if(number != -1)
            *Array_at(&a, cnt++) = number;
    }
    for(i = 0; i < cnt; i++)
        printf("%d ", a.array[i]);
    return 0;
}

Array Array_creat(int init_size)
{
    Array a;
    a.size = init_size;
    a.array = (int *)malloc(sizeof(int) * init_size);
    return a;
}

void Array_free(Array *a)
{
    free(a->array);
    a->array = NULL;
    a->size = 0;
}

int Array_size(const Array *a)
{
    return a->size;
}

int* Array_at(const Array *a, int index)
{
    if(index > a->size)
        Array_inflact(a, ((index / BLOCK) + 1) * BLOCK - a->size);
    return &(a->array[index]);
}

void Array_inflact(Array *a, int more_size)
{
    int *p = (int *)malloc(sizeof(int) * (a->size + more_size)); //申请新的空间
    int i;
    for(i = 0; i < a->size; i++) //拷贝数组
        p[i] = a->array[i];
    free(a->array);
    a->array = NULL;
    a->array = p;
    a->size += more_size;
}
