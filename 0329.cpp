// 14：剪绳子
// 题目：给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m≥1）。
// 每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘
// 积是多少？例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此
// 时得到最大的乘积18。
// f(n) = 3*f(n - 3)
// f(n) = 2*f(n - 2)

#include <iostream>

int getMaxMul(int n)
{
    if(n <= 1) return 0;
    if(n == 2) return 1;
    if(n == 3) return 2;

    int f1 = 1;
    int f2 = 2;
    int f3 = 3;
    int f4 = 4;

    int m1 = 0;
    int m2 = 0;
    int result = 4;
    for(int i = 4; i < n; i++){
        m1 = 3 * f2;
        m2 = 2 * f3;
        result = m1 > m2 ? m1 : m2;
        f1 = f2;
        f2 = f3;
        f3 = f4;
        f4 = result;
    }
    return result;
}

void test(const char* testName, int input, int expectedVal)
{
    int res =  getMaxMul(input);
    if(res == expectedVal){
        std::cout << "[passed]" << std::endl;
    }
    else{
        std::cout << "[failed]" << std::endl;
    }

}

void test1()
{
    //int res = getMaxMul(5);
    //std::cout << "compute result: " << res << " expected value: 5" << std::endl;
    test("test1", 5, 6);
}

void test2()
{
    //int res = getMaxMul(6);
    //std::cout << "compute result: " << res << " expected value: 9" << std::endl;
    test("test2", 6, 9);
}

void test3()
{
    //int res = getMaxMul(8);
    //std::cout << "compute result: " << res << " expected value: 18" << std::endl;
    test("test3", 8, 18);
}

int main()
{
    test1();
    test2();
    test3();

}