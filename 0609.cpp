// 32（三）：之字形打印二叉树
// 题目：请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺
// 序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，
// 其他行以此类推。
//
#include <iostream>
#include <deque>

struct Tree {
    int m_value;
    Tree *m_left;
    Tree *m_right;
    Tree(int value):m_value(value) {}
};


void PrintTreeLeftRight(Tree *root)
{
    if (!root) return;
    int sum = 0;
    int left = 1;
    bool left2right = true;
    std::deque<Tree *> deTree;
    deTree.push_back(root);

    while (deTree.size()){
        Tree *curTree = nullptr;
        if (left2right){
            curTree = deTree.front();
            deTree.pop_front();
        }
        else {
            curTree = deTree.back(); 
            deTree.pop_back();
        }
        printf("%d ", curTree->m_value);
        if (left2right){
            if (curTree->m_left){
                deTree.push_back(curTree->m_left);
                sum ++;
            }
            if (curTree->m_right){
                deTree.push_back(curTree->m_right);
                sum ++;
            }
        }
        else {
            if (curTree->m_right){
                deTree.push_front(curTree->m_right); 
                sum ++;
            }
            if (curTree->m_left){
                deTree.push_front(curTree->m_left);
                sum ++;
            }
        }
        //if (curTree->m_left){
        //    if (left2right)
        //        deTree.push_back(curTree->m_left);
        //    else
        //        deTree.push_front(curTree->m_left);
        //    sum ++;
        //}
        //if (curTree->m_right){
        //    if (left2right)
        //        deTree.push_back(curTree->m_right);
        //    else 
        //        deTree.push_front(curTree->m_right);
        //    sum ++;
        //}
        left --;
        if (!left){
            printf("\n");
            left = sum;
            sum = 0;
            left2right = !left2right; 
        }
    }

}

//              5
//      3                9
//  1      4          6     7
// 2 6    3 0        2 4   5 1
void test1()
{
    Tree *root = new Tree(5); 
    Tree *tree1 = new Tree(3);
    Tree *tree2 = new Tree(9);
    Tree *tree3 = new Tree(1);
    Tree *tree4 = new Tree(4);
    Tree *tree5 = new Tree(6);
    Tree *tree6 = new Tree(7);
    Tree *tree7 = new Tree(2);
    Tree *tree8 = new Tree(6);
    Tree *tree9 = new Tree(3);
    Tree *tree10 = new Tree(0);
    Tree *tree11 = new Tree(2);
    Tree *tree12 = new Tree(4);
    Tree *tree13 = new Tree(5);
    Tree *tree14 = new Tree(1);
    root->m_left = tree1;
    root->m_right = tree2;
    tree1->m_left = tree3;
    tree1->m_right = tree4;
    tree2->m_left = tree5;
    tree2->m_right = tree6;
    tree3->m_left = tree7;
    tree3->m_right = tree8;
    tree4->m_left = tree9;
    tree4->m_right = tree10;
    tree5->m_left = tree11;
    tree5->m_right = tree12;
    tree6->m_left = tree13;
    tree6->m_right = tree14;
    PrintTreeLeftRight(root);
    delete root;
    delete tree1;
    delete tree2;
    delete tree3;
    delete tree4;
    delete tree5;
    delete tree6;
    delete tree7;
    delete tree8;
    delete tree9;
    delete tree10;
    delete tree11;
    delete tree12;
    delete tree13;
    delete tree14;
}

int main()
{
    test1();
}
