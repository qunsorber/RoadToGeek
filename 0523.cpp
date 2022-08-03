// 22：链表中倒数第k个结点
// 题目：输入一个链表，输出该链表中倒数第k个结点。为了符合大多数人的习惯，
// 本题从1开始计数，即链表的尾结点是倒数第1个结点。例如一个链表有6个结点，
// 从头结点开始它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个结点是
// 值为4的结点。

#include <iostream>

struct ListNode{
    int m_value;
    ListNode *next = nullptr;
    ListNode(int m):m_value(m){}
};

ListNode *getBKNode(ListNode *head, int k)
{
    if (head == nullptr || k <= 0) return nullptr;

    ListNode *bgn = head;
    ListNode *end = nullptr;
    int i = 0;
    while(bgn != nullptr){
        bgn = bgn->next;
        i++;
        if (i == k) 
            end = head;
        else if(i > k)
            end = end->next;
    }
    return end;
}

void printListNode(ListNode *head)
{
    while(head != nullptr){
        printf("%d-->",head->m_value);
        head = head->next;
    }
    printf("nullptr\n");
}

void deleteListNode(ListNode *head)
{
    if (head == nullptr) return;
    deleteListNode(head->next);
    delete head;
}

void test1()
{
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    node1->next = node2;
    node2->next = node3;
    printListNode(node1);
    ListNode *res = getBKNode(node1,4);
    if (res) 
        printf("result node :%d\n",res->m_value);
    else
        printf("result node :nullptr\n");
    deleteListNode(node1);
}

int main()
{
    test1();
}
