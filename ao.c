#include <stdio.h>

struct data
{
    int num; //系数
    int ex; //指数
}typedef Data;



int main()
{
    Data data1[3] = {
        {2, 12},
        {4, 6},
        {9, 3}
    };
    Data data2[2] = {
        {7, 9},
        {22, 3},
    };
    int i = 0;
    int j = 0;
    while(i != 3 || j != 2)
    {
        if(data1[i].ex == data2[j].ex)
        {
            printf("%d %d\n", data1[i].num + data2[j].num, data1[i].ex);
            i++;
            j++;
        }
        else if(data1[i].ex > data2[j].ex)
        {
            printf("%d %d\n", data1[i].num, data1[i].ex);
            i++;
        }
        else if(data1[i].ex < data2[j].ex)
        {
            printf("%d %d\n", data2[j].num, data2[j].ex);
            j++;
        }

    }
    return 0;
}