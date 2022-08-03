// 34：二叉树中和为某一值的路径
// 题目：输入一棵二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所
// 有路径。从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

#include <iostream>
#include <vector>


struct Tree{
    int m_value;
    Tree *m_left = nullptr;
    Tree *m_right = nullptr;
    Tree(int value):m_value(value){}
};


void GetNodesPathCore(std::vector<std::vector<Tree *>>& sumPathTree, std::vector<Tree *>& pathTree, Tree *curTree, int sum){
    if (curTree == nullptr){
        return;
    }

    pathTree.push_back(curTree);
    if (curTree->m_left == nullptr && curTree->m_right == nullptr){
        if (sum == curTree->m_value){
            sumPathTree.push_back(pathTree);
            //for (auto tree : pathTree){
            //    printf("value:%d\n", tree->m_value);
            //}
            //printf("one path finish!\n");
        }
    }
     
    GetNodesPathCore(sumPathTree, pathTree, curTree->m_left, sum - curTree->m_value);
    GetNodesPathCore(sumPathTree, pathTree, curTree->m_right, sum - curTree->m_value);
    pathTree.pop_back();
}

std::vector<std::vector<Tree *>> GetNodesPath(Tree *root, int sum){
    std::vector<std::vector<Tree *>> sumVecTree;
    std::vector<Tree *> vecTree;
    GetNodesPathCore(sumVecTree, vecTree, root, sum);
    for (auto pathTree : sumVecTree){
        for (auto curTree : pathTree){
            printf("curTree value:%d\n", curTree->m_value);
        }
        printf("one path finish!\n");
    }
    return sumVecTree;
}
 
//           6
//     4            0
//  1    5       7     9
//             2   3
void test1()
{
    Tree *root = new Tree(6);
    Tree *tree1 = new Tree(4);
    Tree *tree2 = new Tree(0);
    Tree *tree3 = new Tree(1);
    Tree *tree4 = new Tree(5);
    Tree *tree5 = new Tree(7);
    Tree *tree6 = new Tree(9);
    Tree *tree7 = new Tree(2);
    Tree *tree8 = new Tree(3);
    root->m_left = tree1;
    root->m_right = tree2;
    tree1->m_left = tree3;
    tree1->m_right = tree4;
    tree2->m_left = tree5;
    tree2->m_right = tree6;
    tree5->m_left = tree7;
    tree5->m_right = tree8;
    std::vector<std::vector<Tree *>> resVec = GetNodesPath(root, 15);

    delete root;
    delete tree1;
    delete tree2;
    delete tree3;
    delete tree4;
    delete tree5;
    delete tree6;
    delete tree7;
    delete tree8;
}

//            5
//          4
//        3
//      2
//    1
void test2()
{
    Tree *root = new Tree(5);
    Tree *tree1 = new Tree(4);
    Tree *tree2 = new Tree(3);
    Tree *tree3 = new Tree(2);
    Tree *tree4 = new Tree(1);
    root->m_left = tree1;
    tree1->m_left = tree2;
    tree2->m_left = tree3;
    tree3->m_left = tree4;
    std::vector<std::vector<Tree *>> resVec = GetNodesPath(root, 6);
    delete root; 
    delete tree1; 
    delete tree2; 
    delete tree3; 
    delete tree4; 
}

//     1
//       2
//         3
//           4
//             5
void test3()
{
    Tree *root = new Tree(1);
    Tree *tree1 = new Tree(2);
    Tree *tree2 = new Tree(3);
    Tree *tree3 = new Tree(4);
    Tree *tree4 = new Tree(5);
    root->m_right = tree1;
    tree1->m_right = tree2;
    tree2->m_right = tree3;
    tree3->m_right = tree4;
    std::vector<std::vector<Tree *>> resVec = GetNodesPath(root, 6);
    delete root; 
    delete tree1; 
    delete tree2; 
    delete tree3; 
    delete tree4; 
}

int main()
{
    test1();
    test2();
    test3();
}
