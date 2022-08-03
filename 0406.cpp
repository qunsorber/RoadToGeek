// 18（一）：在O(1)时间删除链表结点
// 题目：给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间删除该
// 结点
//
//
#include <iostream>

struct node
{
    int value;
    struct node *next;
};

void deleteNode(node **pList, node *pNode)
{
    if (*pList == nullptr || pNode == nullptr)  return ;

    if ((*pList)->next == nullptr && *pList == pNode) {
        delete *pList;
        *pList = nullptr;
    }

    if (pNode->next == nullptr) {
        node *pToDel = *pList;
        while (pToDel != pNode){
            pToDel = pToDel->next;
        }
        if (pToDel == pNode) {
            delete pToDel;
            pToDel = nullptr;
        }
    }

    node *pTemp = pNode->next;
    pNode->value = pTemp->value;
    pNode->next = pTemp->next;
    delete pTemp;
    pTemp = nullptr;

}


void test1()
{
    node *node1 = new node;
    node *node2 = new node;
    node *node3 = new node;
    node *node4 = new node;
    node *node5 = new node;

    node1->value = 1;
    node2->value = 2;
    node3->value = 3;
    node4->value = 4;
    node5->value = 5;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    
    node *pHead = node1;

    deleteNode(&pHead, node2);
}


int main()
{
    test1();
}

