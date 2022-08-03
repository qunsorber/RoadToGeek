// 25：合并两个排序的链表
// 题目：输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按
// 照递增排序的。例如输入图3.11中的链表1和链表2，则合并之后的升序链表如链
// 表3所示。

#include <iostream>

struct ListNode
{
    int m_value;
    ListNode *next = nullptr;
    ListNode(int value):m_value(value){};
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    if (pHead1 == nullptr) return pHead2;
    if (pHead2 == nullptr) return pHead1;

    ListNode *pNewHead = nullptr;
    pNewHead = pHead1->m_value < pHead2->m_value ? pHead1 : pHead2;

    if (pNewHead == pHead1) pHead1 = pHead1->next;
    else pHead2 = pHead2->next;


    ListNode *pCurNode = pNewHead;
    ListNode *pNode = nullptr;
    while (pHead1 != nullptr || pHead2 != nullptr){
        
        if (pHead1 == nullptr) {
            pCurNode->next = pHead2;
            break;
        }
        if (pHead2 == nullptr) {
            pCurNode->next = pHead1;
            break;
        }

        if (pHead1->m_value < pHead2->m_value){
            pNode = pHead1;
            pHead1 = pHead1->next;
        }
        else{
            pNode = pHead2;
            pHead2 = pHead2->next;
        }
        pCurNode->next = pNode;
        pCurNode = pCurNode->next;
    }
    return pNewHead;
}

ListNode* MyMerge(ListNode* pHead1, ListNode* pHead2)
{
    if (pHead1 == nullptr) return pHead2;
    if (pHead2 == nullptr) return pHead1;

    ListNode *pNewNode = nullptr;
    if (pHead1->m_value < pHead2->m_value){
        pNewNode = pHead1;
        pNewNode->next = MyMerge(pHead1->next, pHead2);
        //pHead1->next = MyMerge(pHead1->next, pHead2);
    }
    else {
        pNewNode = pHead2;
        pNewNode->next = MyMerge(pHead1, pHead2->next);
        //pHead2->next = MyMerge(pHead1, pHead2->next);
    }
    return pNewNode;
}

void PrintListNode(ListNode *head)
{
    if (head == nullptr) return;
    ListNode *pListNode = head;
    while (pListNode){
        printf("--%d--",pListNode->m_value); 
        pListNode = pListNode->next;
    }
    printf("\n");
}

void DeleteListNode(ListNode *head)
{
    if (head == nullptr) return;
    ListNode *pListNode = head;
    ListNode *pTemp = nullptr;
    while (pListNode) {
        pTemp = pListNode->next;
        delete pListNode;
        pListNode = pTemp; 
    }
}

void test1()
{
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(3);
    ListNode *node3 = new ListNode(5);
    ListNode *node4 = new ListNode(2);
    ListNode *node5 = new ListNode(4);
    ListNode *node6 = new ListNode(6);
    //first list of node;
    node1->next = node2;
    node2->next = node3;
    //second list of node;
    node4->next = node5;
    node5->next = node6;
    //ListNode *newList = Merge(node1,node4);
    ListNode *newList = MyMerge(node1,node4);

    PrintListNode(newList);
    DeleteListNode(newList);
}


int main()
{
    test1();
}
