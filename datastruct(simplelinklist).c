#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int num;
    int exp;
    struct _node * next;
}Node;

Node * Read(); //读取
Node * Add(Node * head1, Node * head2); //相加
Node * Mult(Node * head1, Node * head2); //相乘
Node * MultNode(Node * head1, Node * t2); //链表2中的单个结点与链表1中每个结点数据相乘所得结果
void print(Node * head); //打印

int main()
{
    Node * head1, *head2, *res1, *res2;
    head1 = Read();
    head2 = Read();
    res1 = Mult(head1, head2);
    res2 = Add(head1, head2);
    print(res1);
    printf("\n");
    print(res2);
    return 0;
}

Node * Read()
{
    Node * p = (Node *)malloc(sizeof(Node));
    Node * head; //头指针，用于输出0 0
    int n;
    scanf("%d", &n); //输入非零项个数
    p->num = p->exp = 0; 
    p->next = NULL;
    head = p;
    int i;
    if(n > 0) //若无非零项则让链表带着俩蛋直接退出
    {
        for(i = 0; i < n; i++)
        {
            Node * temp = (Node *)malloc(sizeof(Node));
            scanf("%d %d", &(temp->num), &(temp->exp));
            temp->next = NULL;
            p->next = temp;
            p = temp;
        }
    }
    return head;
}

void print(Node * head)
{
    Node * p = head->next;
    if(!p) //链表中只有蛋
    {
        printf("0 0");
        return;
    }
    while(p)
    {
        if(p->next != NULL)
        {
            printf("%d %d ", p->num, p->exp);
        }
        else
            printf("%d %d", p->num, p->exp);
        p = p->next;
    }
}

Node * Add(Node * head1, Node * head2)
{
    Node * p = (Node *)malloc(sizeof(Node));
    p->num = 0;
    p->exp = 0;
    p->next = NULL;
    Node * t1, *t2, *head;
    head = p;
    t1 = head1->next; //临时指针，暂存结点位置
    t2 = head2->next;
    while(NULL != t1 && NULL != t2)
    {
        Node * temp = (Node *)malloc(sizeof(Node)); //申请临时结点
        temp->next = NULL; //下一指向置空
        if(t1->exp == t2->exp) //幂相同，考虑抵消
        {
            if(0 == t1->num + t2->num) //抵消，判断语句中字面值放前面，方便报错
            {
                t1 = t1->next;
                t2 = t2->next;
                continue;
            }
            temp->num = t1->num + t2->num;
            temp->exp = t1->exp;
            t1 = t1->next;
            t2 = t2->next;
        }
        else if(t1->exp > t2->exp)
        {
            temp->num = t1->num;
            temp->exp = t1->exp;
            t1 = t1->next;
        }
        else if(t1->exp < t2->exp)
        {
            temp->num = t2->num;
            temp->exp = t2->exp;
            t2 = t2->next;
        }
        p->next = temp;
        p = temp;
    }
    if(NULL != t1)
        p->next = t1; //未尽的直接整个链接上去
    if(NULL != t2)
        p->next = t2;
    return head;
}

Node * Mult(Node * head1, Node * head2)
{
    Node *p, *head, *t1, *t2, *temp;
    p = (Node *)malloc(sizeof(Node));
    Node *n;
    p->num = 0;
    p->exp = 0;
    p->next = NULL;
    head = p;
    t1 = head1->next;
    t2 = head2->next;
    if(NULL != t1 && NULL != t2)
    {
        temp = MultNode(head1, t2); //计算链表2中单个结点数据与链表1中数据全部相乘所得结果
        t2 = t2->next;
        while(t2)
        {
            Node * temp2 = MultNode(head1, t2); //计算链表2下一节点结果
            temp = Add(temp, temp2); //因此刻链表temp与temp2均降幂排列，可以直接用加法
            t2 = t2->next; 
        }
        p->next = temp->next; //当前结果挂上
    }
    return head;
}

Node * MultNode(Node * head1, Node * t2)
{
    Node * p, * head, *t1;
    p = (Node *)malloc(sizeof(Node));
    p->num = 0;
    p->exp = 0;
    p->next = NULL;
    head = p;
    t1 = head1->next;
    while(t1)
    {
        Node * temp = (Node *)malloc(sizeof(Node));
        temp->next = NULL;
        temp->num = t1->num * t2->num;
        temp->exp = t1->exp + t2->exp;
        p->next = temp;
        p = temp;
        t1 = t1->next;
    }
    return head;
}