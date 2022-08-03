// 10：斐波那契数列
// 题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。

#include <iostream>

int Fab(int n)
{
    if(n <= 0) return 0;
    if(n == 1) return 1;
    int a = 0;
    int b = 1;
    int c = 0;
    int i = 2;
    while(i++ <= n){
       c = a + b; 
       a = b;
       b = c;
    }
    return c;
}

void test1()
{
    int res = Fab(0);
    std::cout << res << " expected res: 0" << std::endl;
    res = Fab(1);
    std::cout << res << " expected res: 1" << std::endl;
    res = Fab(2);
    std::cout << res << " expected res: 1" << std::endl;
    res = Fab(3);
    std::cout << res << " expected res: 2" << std::endl;
    res = Fab(4);
    std::cout << res << " expected res: 3" << std::endl;
    res = Fab(5);
    std::cout << res << " expected res: 5" << std::endl;
    res = Fab(6);
    std::cout << res << " expected res: 8" << std::endl;
}

int main()
{
    test1();
}