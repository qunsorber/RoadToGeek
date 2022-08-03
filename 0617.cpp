// 37：序列化二叉树
// 题目：请实现两个函数，分别用来序列化和反序列化二叉树。
//
#include <iostream>

struct TreeNode{
    int m_value;
    TreeNode *m_left = nullptr;
    TreeNode *m_right = nullptr;
    TreeNode(int value):m_value(value){}
};

void Serialize(TreeNode *root){
    if (root == nullptr){ 
        printf("#,\n");
        return;
    }

    printf("%d,\n",root->m_value);

    Serialize(root->m_left);
    Serialize(root->m_right);
}


// convert list to Tree
TreeNode* Deserialize(char* &head){
    TreeNode *root = nullptr; 
        
    int value = 0;
    while (*head != ',' && *head != '\0'){
        if (*head >= 0 + '0' && *head <= 9 + '0'){
            value = value * 10 + *head - '0'; 
        }
        head ++;
    }
    if (value){
        //printf("Node Value:%d\n", value);
        root = new TreeNode(-1);
        root->m_value = value;
    }
    else{
        //printf("#\n");
        return nullptr; 
    }
    //head = head ++;
    root->m_left = Deserialize(++head);
    root->m_right = Deserialize(++head);
    
    return root;
}

void PrintTreeNode(TreeNode *root)
{
    if (root == nullptr){ 
        printf("node is nullptr!\n");
        return;
    }
    printf("Node Value:%d!\n", root->m_value);
    PrintTreeNode(root->m_left);
    PrintTreeNode(root->m_right);
}

void DestroyTreeNode(TreeNode *root)
{
    if (root == nullptr) 
        return;
    DestroyTreeNode(root->m_left);
    DestroyTreeNode(root->m_right);
    delete root;
    root = nullptr;
}
//         5
//   3          7
// 6   4      2    9
//    1     4   7    0
void test1()
{
    TreeNode *root = new TreeNode(5);
    TreeNode *tree1 = new TreeNode(3);
    TreeNode *tree2 = new TreeNode(7);
    TreeNode *tree3 = new TreeNode(6);
    TreeNode *tree4 = new TreeNode(4);
    TreeNode *tree5 = new TreeNode(2);
    TreeNode *tree6 = new TreeNode(9);
    TreeNode *tree7 = new TreeNode(1);
    TreeNode *tree8 = new TreeNode(4);
    TreeNode *tree9 = new TreeNode(7);
    TreeNode *tree10 = new TreeNode(0);
    root->m_left = tree1;
    root->m_right = tree2;
    tree1->m_left = tree3;
    tree1->m_right = tree4;
    tree2->m_left = tree5;
    tree2->m_right = tree6;
    tree4->m_left = tree7;
    tree5->m_left = tree8;
    tree5->m_right = tree9;
    tree6->m_right = tree10;
    Serialize(root);
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
}

void test(const char *testname, char *str){
    TreeNode *root = Deserialize(str);
    printf("%s begin\n", testname);
    PrintTreeNode(root);
    DestroyTreeNode(root);
    printf("%s end\n", testname);
}
// 4, #, #,
void test2()
{
    char *str = "41, #, #";
    test("test2", str);
}

// 4, 1, #, #, #,
void test3()
{
    char *str = "4, 1, #, #, #";
    test("test3", str);
}

// 4, #, 2, #, #,
void test4()
{
    char *str = "4, #, 2, #, #";
    test("test4", str);
}

// 4, 1, #, #, 2, #, #,
void test5()
{
    char *str = "4, 1, #, #, 2, #, #";
    test("test5", str);
}

int main()
{
    //test1();
    test2();
    test3();
    test4();
    test5();
}
