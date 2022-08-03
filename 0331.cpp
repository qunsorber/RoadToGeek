// 16：数值的整数次方
// 题目：实现函数double Power(double base, int exponent)，求base的exponent
// 次方。不得使用库函数，同时不需要考虑大数问题。

#include <iostream>

double pow(int base, int n)
{
    if (!base) return 0.0;
    if (!n) return 1.0;
    if (n == 1) return base;

    int absn = n;
    if(n < 0) absn = -n;
    int tmp = pow(base, absn >> 1);
    double res = tmp * tmp;
    if((n & 1) == 1)
        res = base * res;

    if(n < 0)
        res = 1.0 / res;

    return res;

    //if ((n & 1) == 0){
    //    double res = tmp * tmp;
    //    if (n < 0) res = 1 / res;
    //    return res;
    //} 
    //else {
    //    double res = tmp * tmp;
    //    res = base * res;
    //    if (n < 0) res = 1 / res;
    //    return res;
    //}
}

void test(const char *testName, int base, int input, double expected)
{
    double res = pow(base, input);
    if(res - expected < 0.001 && expected - res < 0.001)
        std::cout << "[" << testName << "\tpassed]" << std::endl;
    else
        std::cout << "[" << testName << "\tfailed]" << std::endl;
}

void test1()
{
   test("test1", 2, 2, 4.0); 
}

void test2()
{
   test("test2", 2, -2, 0.25); 
}

void test3()
{
   test("test3", 0, 2, 0.0); 
}

void test4()
{
   test("test4", -1, 0, 1.0); 
}

void test5()
{
   test("test5", 3, 3, 27.0); 
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
}
