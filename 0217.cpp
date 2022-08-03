// 从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。
#include <iostream>
#include <stack>

struct ListNode{
    int m_value;
    ListNode *m_node;
}; 

void PrintListNodeReverse(ListNode *pHead){
#if 0
    if(pHead == nullptr) 
        return;
    
    if(pHead->m_node != nullptr){
        PrintListNodeReverse(pHead->m_node);
    }
    printf("%d\n",pHead->m_value);
#else
    std::stack<int> nodes;
    if(pHead == nullptr) return;

    while(pHead != nullptr){
        nodes.push(pHead->m_value);
        pHead = pHead->m_node;
    }

    while(!nodes.empty()){
        int value = nodes.top();
        printf("%d\n",value);
        nodes.pop();
    }
        
#endif
}

void test1()
{
    ListNode node1;
    node1.m_node = nullptr;
    node1.m_value = 1; 
    ListNode *head = &node1;
    PrintListNodeReverse(head);
}

void test2()
{
    ListNode node1,node2,node3;
    node1.m_node = &node2;
    node1.m_value = 1; 
    node2.m_node = &node3;
    node2.m_value = 2; 
    node3.m_node = nullptr;
    node3.m_value = 3; 
    ListNode *head = &node1;
    PrintListNodeReverse(head);
}

int main()
{
    test1();
    test2();
    return 0;
}