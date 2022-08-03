// 重建二叉树
// 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
// 入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,
// 2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建出
// 图2.6所示的二叉树并输出它的头结点。

#include <iostream>
#include <string>

struct BinaryTreeNode
{
    int m_value;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode():m_value(0),left(nullptr),right(nullptr){}
};

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
    if(preorder == nullptr || inorder == nullptr || length <= 0) return nullptr;
    BinaryTreeNode *rootNode = new BinaryTreeNode();
    rootNode->m_value = preorder[0];

    int leftlength = 0;
    int rightlength = 0;
    int *rootIdx = inorder;
    while(*rootIdx != rootNode->m_value){
        rootIdx++;
        leftlength++;
        if(leftlength > length){
            std::cout << "bad input!" << std::endl;
            break;
        }
    }
    rightlength = length - leftlength - 1;

    if(leftlength > 0){ 
        rootNode->left = Construct(preorder + 1, inorder, leftlength);
    }
    if(rightlength > 0){
        rootNode->right = Construct(preorder + leftlength + 1, inorder + leftlength + 1, rightlength);
    }
    return rootNode;
}

void printBinTree(BinaryTreeNode *tree)
{
    if(tree->left != nullptr) printBinTree(tree->left);
    printf("node:%d\n",tree->m_value);
    if(tree->right != nullptr) printBinTree(tree->right);
}

void test1()
{
    int pre[] = {1, 2, 4, 7, 3, 5, 6, 8};
    int in[] = {4, 7, 2, 1, 5, 3, 8, 6};
    BinaryTreeNode *test1 = Construct(pre,in,8);
    printBinTree(test1);
}

void test2()
{
    // no right child tree
    int pre[] = {1, 2, 4, 7};
    int in[] = {4, 7, 2, 1};
    BinaryTreeNode *test1 = Construct(pre,in,4);
    printBinTree(test1);

}

void test3()
{
    // no left child tree
    int pre[] = {1, 3, 5, 6, 8};
    int in[] = {1, 5, 3, 8, 6};
    BinaryTreeNode *test1 = Construct(pre,in,5);
    printBinTree(test1);
}

int main()
{
    test1();
    test2();
    test3();
}