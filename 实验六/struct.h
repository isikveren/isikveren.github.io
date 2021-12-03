#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node
{
    ElemType value;
    struct Node *next;
} LinkList;

void CreateLinkList(LinkList *L)
{
    int num;
    L->value = 0; //链表头节点存放链表长度
    printf("请输入链表,以0为结束:");
    while (1)
    {
        scanf("%d", &num);
        if (num == 0)
        {
            break;
        }
        if (num > 0)
        {
            LinkList *p = (LinkList *)malloc(sizeof(LinkList));
            p->value = num;
            p->next = L->next;
            L->next = p;
            L->value++;
        }
    }
}

void ShowLinkList(LinkList *L)
{
    LinkList *p = L->next;
    printf("输出链表内容:\n");
    while (p)
    {
        if (p->next)
        {
            printf("%d->", p->value);
        }
        else
        {
            printf("%d\n", p->value);
        }
        p = p->next;
    }
}

void ShowNodeAverage(LinkList *L)
{
    LinkList *p = L->next;
    int sum = 0;
    float avg = 0.0;
    printf("显示各结点阈值的平均值:\n");
    while (p)
    {
        sum += p->value;
        p = p->next;
    }
    avg = (float)sum / L->value;
    printf("%.1f\n", avg);
}