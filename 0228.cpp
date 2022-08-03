// 8：二叉树的下一个结点
// 题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
// 树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。

/*
        a
       / \
      b   c
     / \   \
    d   e   h
       / \    
      f   g
     /   / \
    j   i   m
         \
          o
  b-->j
  f-->e  d-->b
  e-->g
  g-->a
*/
#include <iostream>

struct BinaryTreeNode 
{
    char m_value;
    BinaryTreeNode *m_left = nullptr;
    BinaryTreeNode *m_right = nullptr;
    BinaryTreeNode *m_father = nullptr;
    BinaryTreeNode(char value):m_value(value){}
};

BinaryTreeNode *getNextNode(BinaryTreeNode *curNode)
{
    if(curNode == nullptr) return nullptr;
    BinaryTreeNode *pNext = nullptr;
    if(curNode->m_right == nullptr) {
        if(curNode == curNode->m_father->m_left){
            pNext = curNode->m_father;
        }
        else{
            pNext = curNode->m_father;
            while(pNext != pNext->m_father->m_left){
                pNext = pNext->m_father;
            }
            pNext = pNext->m_father;
        }
    }
    else{
        pNext = curNode->m_right;
        while(pNext->m_left != nullptr){
            pNext = pNext->m_left;
        }
    }
    return pNext;
}

void test1()
{
/*
        a
       / \
      b   c
     / \   \
    d   e   h
       / \    
      f   g
     /   / \
    j   i   m
         \
          o
*/    
    BinaryTreeNode node1('a');
    BinaryTreeNode node2('b');
    BinaryTreeNode node3('c');
    BinaryTreeNode node4('d');
    BinaryTreeNode node5('e');
    BinaryTreeNode node6('f');
    BinaryTreeNode node7('g');
    BinaryTreeNode node8('h');
    BinaryTreeNode node9('i');
    BinaryTreeNode node10('j');
    BinaryTreeNode node11('m');
    BinaryTreeNode node12('o');
    node1.m_left = &node2;node1.m_right = &node3;
    node2.m_left = &node4;node2.m_right = &node5;
    node5.m_left = &node6;node5.m_right = &node7;
    node7.m_left = &node9;node7.m_right = &node11;
    node6.m_left = &node10;node9.m_right = &node12;
    node3.m_right = &node8;
    /// add father
    node2.m_father = &node1;node3.m_father = &node1;
    node4.m_father = &node2;node5.m_father = &node2;
    node6.m_father = &node5;node7.m_father = &node5;
    node9.m_father = &node7;node11.m_father = &node7;
    node10.m_father = &node6;node12.m_father = &node9;
    node8.m_father = &node3;
    BinaryTreeNode *res = getNextNode(&node4);
    std::cout << res->m_value << " expect value : b" << std::endl;
    res = getNextNode(&node5);
    std::cout << res->m_value << " expect value : i" << std::endl;
    res = getNextNode(&node7);
    std::cout << res->m_value << " expect value : m" << std::endl;
    res = getNextNode(&node9);
    std::cout << res->m_value << " expect value : o" << std::endl;
    res = getNextNode(&node11);
    std::cout << res->m_value << " expect value : a" << std::endl;
}

int main()
{
    test1();
}