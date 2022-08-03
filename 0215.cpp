// 二维数组中的查找
// 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
// 照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
// 整数，判断数组中是否含有该整数。

#include <iostream>

bool Find(int* matrix, int rows, int columns, int number)
{
    bool find = false;    
    if (matrix == nullptr || rows <0 || columns < 0) return false;
    int curRow = 0;
    int curCol = columns - 1;

    while(curCol >=0 && curRow <= rows - 1){
        int curIdx = curRow * columns + curCol;
        int curVal = matrix[curIdx];
        if(curVal == number){
            return true;
        }
        else if (curVal > number){
            curCol--;
        }
        else{
            curRow++;
        }
    }
    return find;
}

void test1()
{
    int Matrix[3][4] = {{1,2,3,4},{4,5,6,7},{7,8,9,10}};
    int res = Find((int *)Matrix,3,4,5);
    std::cout << "find result: " << res << std::endl;
}

void test2()
{
    int Matrix[3][4] = {{1,2,3,4},{4,5,8,9},{5,8,9,10}};
    int res = Find((int *)Matrix,3,4,6);
    std::cout << "find result: " << res << std::endl;
}

void test3()
{
    int Matrix[3][4] = {{1,2,3,4},{4,5,8,9},{5,8,9,10}};
    int res = Find((int *)Matrix,3,4,7);
    std::cout << "find result: " << res << std::endl;
}

void test4()
{
    int Matrix[1][1] = {{1}};
    int res = Find((int *)Matrix,1,1,1);
    std::cout << "find result: " << res << std::endl;
}

void test5()
{
    int Matrix[1][1] = {{4}};
    int res = Find((int *)Matrix,1,1,1);
    std::cout << "find result: " << res << std::endl;
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
}