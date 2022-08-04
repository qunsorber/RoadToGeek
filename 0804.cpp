// 52：两个链表的第一个公共结点
// 题目：输入两个链表，找出它们的第一个公共结点。
//

#include <iostream>

struct ListNode{
    int value;
    ListNode *next = nullptr;
    ListNode(int m):value(m){}
};

ListNode *GetFirstCommonNode(ListNode *head1, ListNode *head2){
    
}

void test1(){
    ListNode *head1 = new ListNode(1);
    ListNode *node1 = new ListNode(3);
    ListNode *node2 = new ListNode(5);
    ListNode *node3 = new ListNode(7);
    ListNode *node4 = new ListNode(9);
    ListNode *head2 = new ListNode(2);
    ListNode *node6 = new ListNode(4);
    ListNode *node7 = new ListNode(6);
    // first list node 1-->3-->5-->7-->9
    head1->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    // second list node 2-->4-->6-->7-->9
    head2->next = node6;
    node6->next = node7;
    node7->next = node3;
    ListNode *result = GetFirstCommonNode(head1, head2);
    delete head1;
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete head2;
    delete node6;
    delete node7;
}


int main(){
    test1();
}
