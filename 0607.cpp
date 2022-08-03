// 32（一）：不分行从上往下打印二叉树
// 题目：从上往下打印出二叉树的每个结点，同一层的结点按照从左到右的顺序打印。
//
#include <iostream>
#include <deque>

struct tree{
    int value;
    tree *left;
    tree *right;
    tree(int v):value(v){}
};

void PrintTreeTopToDown(tree *root)
{

    std::deque<tree *> detree;
    detree.push_back(root);

    while(detree.size()){
        tree *curtree = detree.front();
        detree.pop_front();
        printf("%d--",curtree->value);
        if (curtree->left)
            detree.push_back(curtree->left);
        if (curtree->right)
            detree.push_back(curtree->right);
    }
}


//               4
//      3                 8
//  2      9           5     7
//    1  4   5       3      2 6
//
void test1()
{
    tree *root = new tree(4);
    tree *tree1 = new tree(3);
    tree *tree2 = new tree(8);
    tree *tree3 = new tree(2);
    tree *tree4 = new tree(9);
    tree *tree5 = new tree(5);
    tree *tree6 = new tree(7);
    tree *tree7 = new tree(1);
    tree *tree8 = new tree(4);
    tree *tree9 = new tree(5);
    tree *tree10 = new tree(3);
    tree *tree11 = new tree(2);
    tree *tree12 = new tree(6);
    root->left = tree1;
    root->right = tree2;
    tree1->left = tree3;
    tree1->right = tree4;
    tree2->left = tree5;
    tree2->right = tree6;
    tree3->right = tree7;
    tree4->left = tree8;
    tree4->right = tree9;
    tree5->left = tree10;
    tree6->left = tree11;
    tree6->right = tree12;
    PrintTreeTopToDown(root);
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
}

int main()
{
    test1();
}


