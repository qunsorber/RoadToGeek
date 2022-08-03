// 26：树的子结构
// 题目：输入两棵二叉树A和B，判断B是不是A的子结构。
//
#include <iostream>

struct tree{
    int value;
    tree *left = nullptr;
    tree *right = nullptr;
    tree(int v):value(v) {}
};

void DelTree(tree *root){
    if (root == nullptr) return;
    DelTree(root->left);
    DelTree(root->right);
    delete root;
    root = nullptr;
}

bool isSubStruct(tree *b, tree *a){
    if (b == nullptr) return true;

    if (a == nullptr) return false;
    
    bool result = false;
    if (b->value == a->value) {
        result = isSubStruct(b->left, a->left) 
            && isSubStruct(b->right, a->right);
    }
    else{
        result = isSubStruct(b, a->left)
            || isSubStruct(b, a->right);
    }

    return result;
}


void test1()
{
    tree *tree1 = new tree(1);
    tree *tree2 = new tree(2);
    tree *tree3 = new tree(3);
    tree *tree4 = new tree(4);
    tree *tree5 = new tree(5);
    tree1->left = tree2;
    tree1->right = tree3;
    tree2->left = tree4;
    tree2->right = tree5;

    tree *tree11 = new tree(2);
    tree *tree12 = new tree(4);
    tree *tree13 = new tree(5);
    tree11->left = tree12;
    tree11->right = tree13;

    bool result = isSubStruct(tree11, tree1);
    printf("result:%d\n",result);
    DelTree(tree1);
    DelTree(tree11);
}

int main()
{
    test1();
}
