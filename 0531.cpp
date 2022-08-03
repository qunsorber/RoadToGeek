// 23：链表中环的入口结点
// 题目：一个链表中包含环，如何找出环的入口结点？例如，在图3.8的链表中，
// 环的入口结点是结点3。
// 1-->2-->3-->4-->5-->3
//
#include <iostream>

struct ListNode{
    int m_value;
    ListNode *m_next = nullptr;
    ListNode(int value):m_value(value){}
};

bool HasCircle(ListNode *head){
    if (head == nullptr) return false;
    
    ListNode *fast = head;
    ListNode *slow = head;

    while (fast != nullptr && slow != nullptr){
        if (fast == slow) return true;
        fast = fast->m_next->m_next; 
        slow = slow->m_next;
    }
    return false;
}

int GetCircleLen(ListNode *head){
    if (!HasCircle(head)) 
        return 0;
    else 
        printf("input listnode has circle\n");

    ListNode *fast = head;
    ListNode *slow = head;

    bool secondmeet = false;
    int len = 0;
    while (fast != nullptr && slow != nullptr) {
        if (fast == slow){
            if (secondmeet) return len;
            else secondmeet = true;
        }
        fast = fast->m_next->m_next;
        slow = slow->m_next;
        len ++;
    }
}


ListNode *GetEntrance(ListNode *head){
    if (head == nullptr) return nullptr;

    int circlelen = GetCircleLen(head);
    printf("circle len:%d\n",circlelen);

    ListNode *front = head;
    ListNode *back = head;
    for (int i = 0; i < circlelen; i++) {
        front = front->m_next;
    }

    while(front != back){
        front = front->m_next; 
        back = back->m_next;
    }
    return back; 
}


void DeleteListNodeWithCircle(ListNode *head)
{
#if 0
    if (head == nullptr) return;
    DeleteListNode(head->m_next);
    delete head;
#else
    while(head != nullptr){
        ListNode *pNode = head->m_next;
        delete head;
        head = pNode;
    }
#endif
}

void test1()
{
    ListNode *node1 = new ListNode(1); 
    ListNode *node2 = new ListNode(2); 
    ListNode *node3 = new ListNode(3); 
    ListNode *node4 = new ListNode(4); 
    ListNode *node5 = new ListNode(5); 
    ListNode *node6 = node3; 
    node1->m_next = node2;
    node2->m_next = node3;
    node3->m_next = node4;
    node4->m_next = node5;
    node5->m_next = node6;
    ListNode *entry = GetEntrance(node1);
    printf("entrance node's value :%d\n",entry->m_value);
    //DeleteListNode(node1);
    delete node1;
    node1 = nullptr;
    delete node2;
    node2 = nullptr;
    delete node3;
    node3 = nullptr;
    delete node4;
    node4 = nullptr;
    delete node5;
    node5 = nullptr;
}

int main()
{
    test1();
}
