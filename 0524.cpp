// 19：正则表达式匹配
// 题目：请实现一个函数用来匹配包含'.'和'*'的正则表达式。模式中的字符'.'
// 表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题
// 中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"
// 和"ab*ac*a"匹配，但与"aa.a"及"ab*a"均不匹配。

#include <iostream>

bool Match(char* str, char* pattern)
{
    if (str == nullptr || pattern == nullptr) return false;

    char *pStr = str;
    char *pPat = pattern;

    while (*pStr != '\0' && *pPat !='\0'){
        if (*pStr == *pPat || *pPat == '.') {
            pStr ++;
            pPat ++;
            if (*pPat  == '*') pPat --;

        }
        else {
            pPat ++;
            if (*pPat != '*') return false;
            else pPat ++;

        }
    }
    if (*pStr == '\0' && *pPat == '\0') return true;
    else return false;
}

void test(char* testname,bool expected, char* str, char* pattern)
{
    bool res = Match(str, pattern);
    if (expected == res)
        std::cout << testname << " [pass]" << std::endl;
    else
        std::cout << testname << " [failed]" << std::endl;
}

void test1()
{
    test("test1", 1, "aaa", "a.a");
}

void test2()
{
    test("test2", 1, "aaa", "ab*ac*a");
}

void test3()
{
    test("test3", 0, "aaa", "aa.a");
}

void test4()
{
    test("test4", 0, "aaa", "ab*a");
}


int main()
{
    test1();
    test2();
    test3();
    test4();
}
