/*******************************
 * function:最大子列和
 * date:2021-3-9
 * author:国家一级学术废物
 * 
 * *****************************/

#include <stdio.h>
int online_dealing(int K, int num[]);
int foolcal(int K, int num[]);
int littlefoolcal(int K, int num[]);
int dividedeal(int K);
int maxsubarray(int num[], int left, int right);
int max(int a, int b, int c);

int main()
{
    int K; //数列中元素数量
    int maxsum;
    int i;
    scanf("%d", &K);
    int num[K];
    for(i = 0; i < K; i++)
        scanf("%d", &num[i]);
    maxsum = maxsubarray(num, 0, K - 1);
    printf("%d", maxsum);
    return 0;
}

int online_dealing(int K, int num[])
{
    int i;
    int maxsum = 0; //最大子列和
    int cursum = 0; //当前子列和
    for(i = 0; i < K; i++)
    {
        cursum += num[i];
        if(cursum > maxsum) //若在添加元素后子列和大于原来最大子列和则进行更换
            maxsum = cursum; //若当前子列和小于0，则不管下一个是什么数，只会让他变得更小，直接将其抛弃，重新开始计算
        else if(cursum < 0)
            cursum = 0;
    }
    return maxsum;
}

int foolcal(int K, int num[])
{
    int i, j ,k;
    int sum = 0;
    int maxsum = 0;
    for(i = 0; i < K; i++) //用i表示数列左端
    {
        for(j = i; j < K; j++) //用j表示数列右端
        {
            sum = 0; //每求出一串子列和，将其重置
            for(k = i; k <= j; k++) //实现相加
            {
                sum += num[k];
                if(sum > maxsum)
                    maxsum = sum;
            }
        }
    }
    return maxsum;
}

int littlefoolcal(int K, int num[])
{
    int i, j ,k;
    int sum = 0;
    int maxsum = 0;
    for(i = 0; i < K; i++) //用i表示数列左端
    {
        sum = 0; //每求出一串子列和，将其重置
        for(j = i; j < K; j++) //用j表示数列右端
        {
            sum += num[j];
            if(sum > maxsum)
            maxsum = sum;
        }
    }
    return maxsum;
}

int dividedeal(int K)
{
    int i;
    int num[K];
    for(i = 0; i < K; i++)
        scanf("%d", &num[i]);
    
}

int maxsubarray(int num[], int left, int right)
{
    int i;
    int mid; //中间值
    int leftsum, rightsum; //左右子列和
    int maxleftsum, maxrightsum; //左右最大子列和
    int leftboardsum, rightboardsum; //左跨列值，右跨列值
    int maxleftboardsum, maxrightboardsum;
    if(right == left) //终止条件：拆分到子列中仅有一个元素为止
        return num[left];
    mid = (left + right) / 2;
    maxleftsum = maxsubarray(num, left, mid);
    maxrightsum = maxsubarray(num, mid + 1, right);
    //求跨界子列和
    leftboardsum = 0;
    rightboardsum = 0;
    maxleftboardsum = 0;
    maxrightboardsum = 0;
    for(i = mid; i >= left; i--)
    {
        leftboardsum += num[i];
        if(leftboardsum > maxleftboardsum)
            maxleftboardsum = leftboardsum;
    }
    for(i = mid + 1; i <= right; i++)
    {
        rightboardsum += num[i];
        if(rightboardsum > maxrightboardsum)
            maxrightboardsum = rightboardsum;
    }
    return max(maxleftsum, maxrightsum, maxleftboardsum + maxrightboardsum);
}

int max(int a, int b, int c)
{
    return (a > b) ? (a > c ? a : c) : (b > c ? b : c); 
}