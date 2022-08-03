// 20：表示数值的字符串
// 题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，
// 字符串“+100”、“5e2”、“-123”、“3.1416”及“-1E-16”都表示数值，但“12e”、
// “1a3.14”、“1.2.3”、“+-5”及“12e+5.4”都不是
//
// [+/-][1~9][E/e][+/-][1~9][.][0~9]
// [A.[E/e]]
#include <iostream>

bool IsNumerical(const char *str){
    const char *pStr = str;
    bool sign = false;
    bool dot = false;
    bool exp = false;
    while(*pStr != '\0'){
        if (*pStr == '+' || *pStr == '-'){
            if (!sign) 
                sign = true;
            else 
                return false;
        }
        else if (*pStr == '.'){
            if (!dot)
                dot = true;
            else
                return false;
        }
        else if (*pStr == 'e' || *pStr == 'E'){
            sign = false;
            dot = true;
        }
        else if (*pStr < 0 + '0' || *pStr > 9 + '0')
            return false;
        
        pStr ++;
    }
    
    return true;;
}

void test(const char* testname, const char *str, bool expected){
    bool res = IsNumerical(str);
    if (res == expected)
        printf("%s,[pass!]\n",testname);
    else
        printf("%s,[failed!]\n",testname);
}

int test1()
{
    const char *str = "+100";
    test("test1", str, 1);
}

int test2()
{
    const char *str = "5e2";
    test("test2", str, 1);
}

int test3()
{
    const char *str = "3.1416";
    test("test3", str, 1);
}

int test4()
{
    const char *str = "-E-16";
    test("test4", str, 1);
}

int test5()
{
    const char *str = "1a3.14";
    test("test5", str, 0);
}

int test6()
{
    const char *str = "1.2.4";
    test("test6", str, 0);
}

int test7()
{
    const char *str = "+-5";
    test("test7", str, 0);
}

int test8()
{
    const char *str = "12e+5.4";
    test("test8", str, 0);
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
