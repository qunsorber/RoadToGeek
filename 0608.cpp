// 32（二）：分行从上到下打印二叉树
// 题目：从上到下按层打印二叉树，同一层的结点按从左到右的顺序打印，每一层
// 打印到一行。

#include <iostream>
#include <deque>

struct tree{
    int m_value;
    tree *m_left = nullptr;
    tree *m_right = nullptr;
    tree(int value):m_value(value){}
};


void PrintTreeByLine(tree *root){
    if (!root) return;

    std::deque<tree *> detree;
    detree.push_back(root);
    int curLineSumNum = 0;
    int curLineLeftNum = 1;
    while(detree.size()) {
        tree *curtree = detree.front();
        printf("%d--",curtree->m_value);
        curLineLeftNum --;
        if (curtree->m_left) {
            detree.push_back(curtree->m_left);
            curLineSumNum ++;
        }
        if (curtree->m_right) {
            detree.push_back(curtree->m_right);
            curLineSumNum ++;
        }
        if (!curLineLeftNum) {
            printf("\n");
            curLineLeftNum = curLineSumNum;
            curLineSumNum = 0;
        }
        detree.pop_front();
    }

}

//          4
//     3          8
//  2    7      4   9
void test1()
{
    tree *root = new tree(4);
    tree *tree1 = new tree(3);
    tree *tree2 = new tree(8);
    tree *tree3 = new tree(2);
    tree *tree4 = new tree(7);
    tree *tree5 = new tree(4);
    tree *tree6 = new tree(9);
    root->m_left = tree1;
    root->m_right= tree2;
    tree1->m_left = tree3;
    tree1->m_right = tree4;
    tree2->m_left = tree5;
    tree2->m_right = tree6;
    PrintTreeByLine(root);
    delete root;
    delete tree1;
    delete tree2;
    delete tree3;
    delete tree4;
    delete tree5;
    delete tree6;

}

int main()
{
    test1();
}
