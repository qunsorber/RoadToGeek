// 36：二叉搜索树与双向链表
// 题目：输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求
// 不能创建任何新的结点，只能调整树中结点指针的指向。
//
#include <iostream>

struct TreeNode{
    int m_value;
    TreeNode *m_left = nullptr;
    TreeNode *m_right = nullptr;
    TreeNode(int value):m_value(value) {}
};

TreeNode *TreeToList(TreeNode *root){
    if (root == nullptr) return root;

    TreeNode *head = root;
    while(head->m_left != nullptr){
        head = head->m_left;
    }

    if (root->m_left != nullptr){
        TreeNode *leftHead = TreeToList(root->m_left);
        TreeNode *leftEnd = leftHead;
        while(leftEnd->m_right != nullptr){
            leftEnd = leftEnd->m_right;
        }
        leftEnd->m_right = root;
        root->m_left = leftEnd;
    }

    if (root->m_right != nullptr){
        TreeNode *rightHead = TreeToList(root->m_right);
        root->m_right = rightHead;
        rightHead->m_left = root;
    }

    return head;
}

void PrintTreeNode(TreeNode *root){
    if (root == nullptr)
        return;
    PrintTreeNode(root->m_left);
    printf("Tree Node value:%d\n", root->m_value);
    PrintTreeNode(root->m_right);
}

void PrintListNode(TreeNode *head, bool& flag){
#if 1
    if (!flag)
        return;

    if (head == nullptr){ 
        if (flag) 
            flag = false;
        return;
    }

    if (flag){
        printf("List Node value:%d\n", head->m_value);
        PrintListNode(head->m_right, flag);
    }
    
    if (!flag){
        printf("List Node value:%d\n", head->m_value);
        PrintListNode(head->m_left, flag);
    }
#else 
    TreeNode *lastNode = head;
    while(head!=nullptr){
        printf("List Node value:%d\n", head->m_value);
        lastNode = head;
        head = head->m_right;
    }
    head = lastNode;
    while(head!=nullptr){
        printf("List Node value:%d\n", head->m_value);
        head = head->m_left;
    }
#endif
}

void DestroyNodesList(TreeNode *head){
#if 0
    TreeNode *curNode = nullptr;
    while(head != nullptr){
        curNode = head->m_right;
        delete head; 
        head = curNode;
    }
#else
    if (head == nullptr)
        return;
    DestroyNodesList(head->m_right);
    delete head;
    head = nullptr;
#endif
}

//          6
//     3         8
//   1   4     7   9
//
//  1-->3-->4-->6-->7-->8-->9
//
void test1()
{
    TreeNode *root = new TreeNode(6);
    TreeNode *tree1 = new TreeNode(3);
    TreeNode *tree2 = new TreeNode(8);
    TreeNode *tree3 = new TreeNode(1);
    TreeNode *tree4 = new TreeNode(4);
    TreeNode *tree5 = new TreeNode(7);
    TreeNode *tree6 = new TreeNode(9);
    root->m_left = tree1;
    root->m_right = tree2;
    tree1->m_left = tree3;
    tree1->m_right = tree4;
    tree2->m_left = tree5;
    tree2->m_right = tree6;
    PrintTreeNode(root);
    TreeNode *head = TreeToList(root);
    //PrintListNode(head);
    DestroyNodesList(head);
}

void test2()
{
    TreeNode *head = new TreeNode(1);
    TreeNode *tree1 = new TreeNode(2);
    TreeNode *tree2 = new TreeNode(3);
    TreeNode *tree3 = new TreeNode(4);
    TreeNode *tree4 = new TreeNode(5);
    TreeNode *tree5 = new TreeNode(6);
    head->m_right = tree1;
    tree1->m_left = head;
    tree1->m_right = tree2;
    tree2->m_left = tree1;
    tree2->m_right = tree3;
    tree3->m_left = tree2;
    tree3->m_right = tree4;
    tree4->m_left = tree3;
    tree4->m_right = tree5;
    tree5->m_left = tree4;
    bool flag = 1;
    PrintListNode(head, flag);
    DestroyNodesList(head);
}

int main()
{
    //test1();
    test2();
}
