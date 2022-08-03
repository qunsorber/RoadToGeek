// 41：数据流中的中位数
// 题目：如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么
// 中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，
// 那么中位数就是所有数值排序之后中间两个数的平均值。

#include <iostream>

double GetMidNum(double *arr, int len){

}


void test(char *testname, double *arr, int len, double expected){
    double result = GetMidNum(arr, len); 
    if (result - expected < 0.01){
        printf("[%s passed]\n", testname); 
    }
    else {
        printf("[%s failed]\n", testname);
    }
}

void test1()
{
    double array = {1, 2, 5, 4, 6, 3};
    test("test1", array, 6, 3.5);
}

void test2()
{
    double array = {1, 2, 5, 4, 3};
    test("test2", array, 5, 3);
}

int main()
{
    test1();
    test2();
}
