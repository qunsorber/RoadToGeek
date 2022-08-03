// 24：反转链表
// 题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的
// 头结点。
//
#include <iostream>

struct ListNode 
{
    int m_value;
    ListNode *next = nullptr;
    ListNode(int value):m_value(value){};
};

ListNode * ReverseList(ListNode *head){
    if (head == nullptr) return nullptr;
#if 0
    ReverseList(head->next);

    if (head->next->next == nullptr){
        head->next->next = head;
        head->next = nullptr;
    }
#else
    ListNode *pre = nullptr;
    ListNode *cur = head;
    while(cur != nullptr){
        ListNode *tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    } 

#endif
    return pre;
}

void printListNode(ListNode *head){
    while(head !=nullptr){
        printf("--%d--",head->m_value); 
        head = head->next;
    }
    printf("\n");
}

void deleteListNode(ListNode *head){
    if (head == nullptr) {
        return;
    }
    deleteListNode(head->next);
    delete head;
    head = nullptr;
}

void test1()
{
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    printListNode(node1);
    ListNode *newHead = ReverseList(node1);
    printListNode(newHead);
    deleteListNode(node1);
}

void test2()
{
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    node1->next = node2;
    printListNode(node1);
    ListNode *newHead = ReverseList(node1);
    printListNode(newHead);
    deleteListNode(node1);
}

void test3()
{
    ListNode *node1 = new ListNode(1);
    printListNode(node1);
    ListNode *newHead = ReverseList(node1);
    printListNode(newHead);
    deleteListNode(node1);
}

void test4()
{
    ListNode *node1 = nullptr;
    printListNode(node1);
    ListNode *newHead = ReverseList(node1);
    printListNode(newHead);
    deleteListNode(node1);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
}
