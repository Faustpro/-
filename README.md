#include <stdio.h>
#include <malloc.h>
//完数判断
int main()
{
    int i, j;  //i用于找完数， j用于找因子
    int num[100] = {0};
    int *p = num;
    int n;     //求n以内的完数
    scanf("%d", &n);
    for(i = 6; i < n; i++) //从最小的完数开始
    {
      for(j = 1; j < i; j++)
      {
        if(i % j == 0)
        {
           p++; //移动指针
           *p = j; //存储因子
           num[0] += j; //数组第一位用于存储因子和
        }
      }
      if(num[0] == i) //判断完数
      {
        printf("%d its factors are", i);
        for(p = &num[1]; *p != 0; p++)
        {
          printf("%d ", *p);
        }
      }
      printf("\n");
      sum = 0;
      free(p);
      p = NULL;
    }

    return 0;
}
