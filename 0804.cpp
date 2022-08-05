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
    if (head1 == nullptr || head2 == nullptr) 
        return nullptr;
    ListNode *ph1 = head1;
    ListNode *ph2 = head2;
    int length1 = 0;
    int length2 = 0;
    while(ph1){
        length1 ++; 
        ph1 = ph1->next;
    }
    while(ph2){
        length2 ++; 
        ph2 = ph2->next;
    }
    ph1 = head1;
    ph2 = head2;
    int dis = length1 - length2;
    if(dis > 0){
        while(dis){
            ph1 = ph1->next; 
            dis--;
        }
    }
    else {
        dis = -dis;
        while(dis){
            ph2 = ph2->next; 
            dis--;
        }
    }

    ListNode *result = nullptr;
    while(ph1){
        if (ph1 == ph2){
            result = ph1; 
            break;
        }
        ph1 = ph1->next;
        ph2 = ph2->next;
    }
    return result;
}

void test(char *testname, ListNode *h1, ListNode *h2, int expected){
    ListNode *result = GetFirstCommonNode(h1, h2);
    if (result == nullptr){
        printf("there is no common list node\n"); 
        return;
    }
    if (result->value == expected){
        printf("[%s passed!]\n", testname); 
    }
    else {
        printf("[%s failed!]\n", testname); 
    }
    
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
    test("test1", head1, head2, 7);
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

void test2(){
    ListNode *head1 = new ListNode(1);
    ListNode *node1 = new ListNode(2);
    test("test2", head1, nullptr, -1);
    delete head1;
    delete node1;
}

int main(){
    test1();
    test2();

int main(){
    test1();
}
