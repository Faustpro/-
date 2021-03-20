#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct _node
{
    int value;
    struct _node * next;
}Node;

typedef struct _list
{
    Node * head;
    Node * tail;
    int length;
}List;


List * Initlist() //链表初始化
{
    List * m = (List *)malloc(sizeof(List));
    m->head = m->tail = NULL;
    return m;
}

void Add(List * m, int num); //添加元素
Node* Find(List * m, int num); //查找元素(按值)
Node * FindKth(List * m, int index); //按序号查找
void insert(List * m, int num, int index); //插入元素
void delete(List * m, int index); //删除元素
int Length(List * m); //求表长
int Jempty(List * m); //判断队列是否为空
void Display(List * m); //打印元素

int main()
{
    List * m = Initlist();
    int num, K; //K为FindKth中所用的查找序号
    int num1, index; //插入元素用的元素内容与位置
    scanf("%d", &num);
    while(num != -1)
    {
        Add(m, num);
        scanf("%d", &num);
    }
    Display(m);
    m->length = Length(m);
    printf("%d\n", m->length);
    index = 3;
    delete(m, index);
    Display(m);

    /*printf("Please input the num and the index\n");
    scanf("%d %d", &num1, &index);
    insert(m, num1, index);*/

    /*scanf("%d", &num);
    t = Find(m, num);
    if(t)
        printf("%d", t->value);*/
    /*scanf("%d", &K);
    t = FindKth(m, K - 1);
    if(t)
        printf("%d\n", t->value);
    */
    return 0;
}

void Add(List * m, int num)
{
    Node * p;
    p = (Node *)malloc(sizeof(Node));
    p->value = num;
    p->next = NULL;
    if(m->head == NULL) //头指针为空代表链表中没有数据
    {
        m->head = m->tail = p;
    }
    else
    {
        m->tail->next = p; //链接
        m->tail = p; //更新尾指针中信息
    }
}

Node* Find(List * m, int num)
{
    Node *p;
    for(p = m->head; p; p = p->next)
    {
        if(p->value == num)
        {
            printf("Find\n");
            return p;
        }
    }
    if(!p)
    {
        printf("There is no such number");
        return NULL;
    }
}

void insert(List * m , int num, int index) //s表示插入位置前一个
{
    Node * p;
    Node * s = (Node *)malloc(sizeof(Node));
    int i;
    if(index < 0 || index > m->length)
    {
        printf("Invalid input\n");
        return ;
    }
    if(index == 1)
    {
        s->value = num;
        s->next = m->head;
        m->head = s;
        m->length++;
        return ;
    }
    for(i = 0, p = m->head; i < index - 2; p = p->next, i++); //将p指向插入位置前一个结点
    s->value = num;
    s->next = p->next;
    p->next = s;
    m->length++;
}

int Length(List * m)
{
    int j = 0;
    Node * p;
    for(p = m->head;p; p = p->next)
        j++;
    return j;
}

Node * FindKth(List * m, int K)
{
    if(K < 0 || K > m->length - 1)
    {
        printf("illegal input\n");
        return NULL;
    }
    Node * p = m->head;
    int cnt = 0;
    while(p && cnt < K)
    {
        p = p->next;
        cnt++;
    }
    return p;
}

int Jempty(List * m)
{
    if(m->head = NULL)
        return 1;
    else
        return 0;
}

void Display(List * m)
{
    Node * p;
    for(p = m->head; p; p = p->next)
        printf("%d  ", p->value);
    printf("\n");
}

void delete(List * m, int index)
{
    int i;
    Node * p;
    Node * s;
    if(index < 0 || index > m->length)
    {
        printf("Invalid input");
        return ;
    }
    if(index == 1)
    {
        m->head = m->head->next;
        m->length--;
        return ;
    }
    for(i = 0, p = m->head; i < index - 2; i++) //遍历寻找第i-1个结点
    {
        p = p->next;
    }
    s = p->next;
    p->next = s->next;
    free(s);
    m->length--;
}
