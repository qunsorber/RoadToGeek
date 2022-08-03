// 43：从1到n整数中1出现的次数
// 题目：输入一个整数n，求从1到n这n个整数的十进制表示中1出现的次数。例如
// 输入12，从1到12这些整数中包含1 的数字有1，10，11和12，1一共出现了5次。
//
#include <iostream>

int CountIhas1(int i){
    int has1 = 0;
    while (i){
        if (i % 10 == 1){
            has1 ++;
        }
        i = i / 10;
    }
    return has1;
}

int Count1ToN(int n){
    int sum = 0;
    int i = 1;
    while(i <= n){
        sum += CountIhas1(i);
        i ++;
    }
    return sum;
}

void test(char *testname, int n, int expected){
    int result = Count1ToN(n);
    if (result == expected)
        printf("[%s passed]\n", testname);
    else
        printf("[%s failed]\n", testname);
}

void test1()
{
    test("test1", 12, 5); 
}

int main()
{
    test1();
}
