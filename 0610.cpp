// 33：二叉搜索树的后序遍历序列
// 题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
// 如果是则返回true，否则返回false。假设输入的数组的任意两个数字都互不相同。
//
#include <iostream>

struct Tree{
    int m_value;
    Tree *m_left;
    Tree *m_right;
};

bool IsPostOrderTrav(int *arr, int len){
    if (!arr || len <= 0) return false;
    //if (len == 1 || len == 2) return true;
    
    int rootValue = arr[len-1];
    int *pLeft = arr;
    int leftNum = 0;
    for (int i = 0; i < len - 1; i++) {
        if (arr[i] > rootValue){
            break;
        }
        leftNum ++;
    }
    //printf("len:%d--leftNum:%d\n", len, leftNum);

    for (int j = leftNum; j < len - 1; j++){
        if (arr[j] < rootValue) 
            return false;
    }

    bool leftRes = true;
    if (leftNum > 0)
        leftRes = IsPostOrderTrav(pLeft, leftNum);
    bool rightRes = true;
    if (len - leftNum - 1 > 0)
        rightRes = IsPostOrderTrav(pLeft + leftNum, len - leftNum - 1);
    return leftRes && rightRes;
}

void test(const char* testname, int *arr, int len, bool expected){
    bool result = IsPostOrderTrav(arr, len);
    if (expected == result)
        printf("[%s passed!]\n", testname);
    else
        printf("[%s failed!]\n", testname);

}

//        3
//    1       5
//  0   2   4   6
//  post order 0 2 1 4 6 5 3
void test1()
{
    int arr[] = {0, 2, 1, 4, 6, 5, 3};
    test("test1", arr, sizeof(arr)/sizeof(int), 1);
}

//        3
//    1       5
//      2    4   
//  post order  2 1 4 5 3
void test2()
{
    int arr[] = {2, 1, 4, 5, 3};
    test("test2", arr, sizeof(arr)/sizeof(int), 1);
}

//        3
//    1       5
//      6    4   
//  post order  6 1 4 5 3
void test3()
{
    int arr[] = {6, 1, 4, 5, 3};
    test("test3", arr, sizeof(arr)/sizeof(int), 0);
}

void test4()
{
    int arr[] = {1, 2, 3, 4, 5};
    test("test4", arr, sizeof(arr)/sizeof(int), 1);
}

void test5()
{
    int arr[] = {5, 4, 3, 2, 1};
    test("test5", arr, sizeof(arr)/sizeof(int), 1);
}

void test6()
{
    int arr[] = {5};
    test("test6", arr, sizeof(arr)/sizeof(int), 1);
}

void test7()
{
    test("test7", nullptr, 3, 0);
}

void test8()
{
    int arr[] = {5};
    test("test8", arr, 0, 0);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
}
