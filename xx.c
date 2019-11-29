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

void PrintNodeList(Node* pHead)
{
    Node* currNode = pHead;
    while (currNode != NULL)
        printf("%d\n", currNode->value.i),
            currNode = currNode->next;
}

int main(void)
{
    int a[5] = { 1, 2, 3, 4, 5 };
    Node* head = NULL;
    for (int i = 0; i < 5; i++) {
        InsertNode(&head, *(Value*)(void*)&a[i]);
    }
    PrintNodeList(head);
    ReverseNodeList(&head);
    PrintNodeList(head);
    return 0;
}