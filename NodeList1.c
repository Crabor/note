#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    struct NODE* next;
    int value;
} Node;

typedef enum {
    TRUE = 1,
    FALSE = 0
} Status;

//插入新节点到末尾
Status InsertNode(Node** ppHead, int value)
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

void PrintNodeList(Node* pHead)
{
    Node* currNode = pHead;
    while (currNode != NULL)
        printf("%d\n", currNode->value),
            currNode = currNode->next;
}

//查找节点
Node *SearchNode(Node *pHead,void const *pValue,int (*compare)(void const *,void const *)){
    Node *currNode=pHead;
    while(currNode!=NULL){
        if(compare(&currNode->value,pValue))
            break;
        currNode=currNode->next;
    }
    return currNode;
}

//比较函数
int compare_int(void const *a,void const *b){
    return *(int*)a==*(int*)b;
}

int main(void)
{
    int a[5] = { 1, 3, 5, 7, 9 };
    Node* head = NULL;
    for (int i = 0; i < 5; i++)
        InsertNode(&head, a[i]);
        int value=5;
    Node *temp=SearchNode(head,(void const *)&value,compare_int);
    PrintNodeList(temp);
    return 0;
}