#include <stdio.h>
#include <stdlib.h>

typedef union {
    int i;
    float f;
    char c;
} Value;

typedef struct NODE {
    struct NODE* next;
    Value value;
} Node;

typedef enum {
    TRUE = 1,
    FALSE = 0
} Status;

//插入新节点到末尾
Status InsertNode(Node** ppHead, Value value)
{
    Node *currNode, *preNode;
    currNode = *ppHead;
    preNode = NULL;

    //遍历到末尾
    while (currNode != NULL) {
        preNode = currNode;
        currNode = currNode->next;
    }

    //申请新节点
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    //插入新节点
    if (preNode == NULL)
        *ppHead = newNode;
    else
        preNode->next = newNode;

    return TRUE;
}

//反转链表：要想改变指针指向只有传指针的指针
void ReverseNodeList(Node** ppHead)
{
    //边界判断
    if (*ppHead == NULL || (*ppHead)->next == NULL)
        return;
    //将链表分为两部分，[1]和[2-n]
    Node* curNode = *ppHead;
    *ppHead = (*ppHead)->next;
    curNode->next = NULL;
    //将[2-n]逆转
    ReverseNodeList(ppHead);
    //将[1]放到逆转后的[2-n]的后面
    Node* nextNode = *ppHead;
    while (nextNode->next != NULL)
        nextNode = nextNode->next;
    nextNode->next = curNode;
    return;
}

//合并链表
Node* MergeNodeList(Node* pHead1, Node* pHead2)
{
    //边界判断
    if (pHead1 == NULL)
        return pHead2;
    else if (pHead2 == NULL)
        return pHead1;
    //将两链表中较小值取出放入新链表，并将剩下两个链表进行合并后接入新链表后面
    Node* mergeNode = NULL;
    if (pHead1->value.i < pHead2->value.i) {
        mergeNode = pHead1;
        mergeNode->next = MergeNodeList(pHead1->next, pHead2);
    } else {
        mergeNode = pHead2;
        mergeNode->next = MergeNodeList(pHead1, pHead2->next);
    }
    return mergeNode;
}



void PrintNodeList(Node* pHead)
{
    Node* currNode = pHead;
    while (currNode != NULL)
        printf("%d\n", currNode->value.i),
            currNode = currNode->next;
}

int main(void)
{
    int a[5] = { 1, 3, 5, 7, 9 };
    Node* head = NULL;
    for (int i = 0; i < 5; i++)
        InsertNode(&head, *(Value*)(void*)&a[i]);
    int b[5] = { 2, 4, 6, 8, 10 };
    Node* head2 = NULL;
    for (int i = 0; i < 5; i++)
        InsertNode(&head2, *(Value*)(void*)&b[i]);
    Node* mergeNode = MergeNodeList(head, head2);
    PrintNodeList(mergeNode);
    return 0;
}