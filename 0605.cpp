// 28：对称的二叉树
// 题目：请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和
// 它的镜像一样，那么它是对称的。
//
#include <iostream>

struct tree{
    int value;
    tree* left = nullptr;
    tree* right = nullptr;
    tree(int v):value(v){}
};

bool IsSymmetricalCore(tree* left, tree* right){
#if 1
    if (left ==  nullptr && right == nullptr) 
        return true;
    else if (!left || !right)
        return false;
    //if ((left == nullptr && right != nullptr) || (left != nullptr && right == nullptr))
    //    return false;
#else
    if (long(left) ^ long(right))
        return true;
    else 
        return false;
#endif
    if (left->value != right->value) 
        return false;
    else 
        return IsSymmetricalCore(left->right, right->left)
            && IsSymmetricalCore(left->left, right->right);
}

bool IsSymmetrical(tree *root){
    if (!root) return false;
    
    return IsSymmetricalCore(root->left, root->right);
}

//             3
//      5            5 
//   6     7      7     6
//  1 2   4 5    5 4   2 1
//
void test1()
{
    tree* root = new tree(3); 
    tree* tree1 = new tree(5); 
    tree* tree2 = new tree(5); 
    tree* tree3 = new tree(6); 
    tree* tree4 = new tree(7); 
    tree* tree5 = new tree(7); 
    tree* tree6 = new tree(6); 
    tree* tree7 = new tree(1); 
    tree* tree8 = new tree(2); 
    tree* tree9 = new tree(4); 
    tree* tree10 = new tree(5); 
    tree* tree11 = new tree(5); 
    tree* tree12 = new tree(4); 
    tree* tree13 = new tree(2); 
    tree* tree14 = new tree(1); 
    root->left = tree1;
    root->right = tree2;
    tree1->left = tree3;
    tree1->right = tree4;
    tree2->left = tree5;
    tree2->right = tree6;
    tree3->left = tree7;
    tree3->right = tree8;
    tree4->left = tree9;
    tree4->right = tree10;
    tree5->left = tree11;
    tree5->right = tree12;
    tree6->left = tree13;
    tree6->right = tree14;

    bool result = IsSymmetrical(root);
    printf("result:%d\n",result);
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
