// 13：机器人的运动范围
// 题目：地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，它
// 每一次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和
// 大于k的格子。例如，当k为18时，机器人能够进入方格(35, 37)，因为3+5+3+7=18。
// 但它不能进入方格(35, 38)，因为3+5+3+8=19。请问该机器人能够到达多少个格子？


#include <iostream>

int getSum(int row, int col)
{
    int sum = 0;
    while(row != 0){
        sum += row%10;
        row = row/10;
    }
    while(col != 0){
        sum += col%10;
        col = col/10;
    }
    return sum;
}

int coverBoxesCore(int curRow, int row, int curCol, int col, int *visit, int k)
{
    

    if(curRow < 0 || curRow > row -1 || curCol < 0 || curCol > col -1) return 0;

    int sum = 0;
    int curSum = getSum(curRow, curCol);
    if(curSum <= k && visit[curRow * col + curCol] == 0){
        sum += 1;
        visit[curRow * col + curCol] = 1;
    
        sum +=  coverBoxesCore(curRow + 1, row, curCol, col, visit, k) +
                coverBoxesCore(curRow - 1, row, curCol, col, visit, k) +
                coverBoxesCore(curRow, row, curCol + 1, col, visit, k) +
                coverBoxesCore(curRow, row, curCol - 1, col, visit, k);
    }
    return sum;
}

int coverBoxes(int m, int n, int k)
{
    int covered = 0;
    int visit[m*n] = {0};

    if(m <= 0 || n <= 0 || k<= 0) return covered;

    covered = coverBoxesCore(0, m, 0, n, visit, k);

    return covered;
}

void test1()
{
    int result = coverBoxes(4, 5, 5);
    std::cout << "compute result: " << result << " expected result: 17" << std::endl;
}

void test2()
{
    int result = coverBoxes(10, 10, 5);
    std::cout << "compute result: " << result << " expected result: 21" << std::endl;
}

void test3()
{
    int result = coverBoxes(20, 20, 15);
    std::cout << "compute result: " << result << " expected result: 359" << std::endl;
}

void test4()
{
    int result = coverBoxes(1, 10, 10);
    std::cout << "compute result: " << result << " expected result: 10" << std::endl;
}

void test5()
{
    int result = coverBoxes(1, 1, 0);
    std::cout << "compute result: " << result << " expected result: 0" << std::endl;
}

void test6()
{
    int result = coverBoxes(1, 1, 10);
    std::cout << "compute result: " << result << " expected result: 1" << std::endl;
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
}