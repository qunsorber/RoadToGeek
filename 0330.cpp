// 15：二进制中1的个数
// 题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如
// 把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。
//

#include <iostream>

int getNumOf1InBin1(int n)
{
    int cnt = 0;
    while (n != 0){
        if ((n & 0x80000000) == 0x80000000) 
            cnt++;
        n <<= 1;
    }
    return cnt;
}

int getNumOf1InBin2(int n)
{
    int cnt = 0;
    while (n != 0){
        cnt ++;
        n = n & (n - 1);
    }
    return cnt;
}

void test(const char* testName, int input, int expected)
{
    int res = getNumOf1InBin2(input);
    if(res == expected)
        std::cout << "[" << testName << "-->passed]" << std::endl;
    else
        std::cout << "[" << testName << "-->failed]" << std::endl;
}


void test1()
{
    test("test1", 9, 2);
}

void test2()
{
    test("test2", -1, 32);
}

void test3()
{
    test("test3", 15, 4);
}

int main()
{
    test1();
    test2();
    test3();
}
