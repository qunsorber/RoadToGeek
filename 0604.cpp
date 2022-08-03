// 27：二叉树的镜像
// 题目：请完成一个函数，输入一个二叉树，该函数输出它的镜像。
//
#include <iostream>

struct tree{
    int m_value;
    tree *m_left = nullptr;
    tree *m_right = nullptr;
    tree(int value):m_value(value) {}
};

tree *GetMirrorTree(tree *root){
    if (root == nullptr) return root;

    tree *tmp =  root->m_left;   
    root->m_left = root->m_right;
    root->m_right = tmp;

    if (root->m_left) 
        root->m_left = GetMirrorTree(root->m_left); 
    if (root->m_right)
        root->m_right = GetMirrorTree(root->m_right); 
    
    return root;
    
}

void PrintTree(tree *root){
    if (!root) return;
    PrintTree(root->m_left);
    printf("%d--",root->m_value);
    PrintTree(root->m_right);
}
//            3
//     5              8
// 7      2       4       1
void test1()
{
    tree *root = new tree(3); 
    tree *tree1 = new tree(5); 
    tree *tree2 = new tree(8); 
    tree *tree3 = new tree(7); 
    tree *tree4 = new tree(2); 
    tree *tree5 = new tree(4); 
    tree *tree6 = new tree(1); 
    root->m_left = tree1;
    root->m_right = tree2;
    tree1->m_left = tree3;
    tree1->m_right = tree4;
    tree2->m_left = tree5;
    tree2->m_right = tree6;
    PrintTree(root);
    printf("\n");
    PrintTree(GetMirrorTree(root));
    printf("\n");

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
