// 38：字符串的排列
// 题目：输入一个字符串，打印出该字符串中字符的所有排列。例如输入字符串abc，
// 则打印出由字符a、b、c所能排列出来的所有字符串abc、acb、bac、bca、cab和cba。
//
#include <iostream>

void Swap2Characters(char *first, char* latter){
    if (first == latter)  
        return;
    char tmp = *first;
    *first = *latter;
    *latter = tmp;
}

void PrintAllArraysCore(char * str, char *begin){
    if (*begin == '\0'){
        return;
    }

    int offset = 0;
    //if (str == begin)
    //    offset = 0;

    while (*(begin + offset) != '\0'){
        Swap2Characters(begin, begin + offset);
        if (str == begin || offset !=0)
            printf("befor: %s\n", str);
        PrintAllArraysCore(str, begin + 1);
        Swap2Characters(begin, begin + offset);
        offset ++;
    }
}

void PrintAllArrays(char *str){
    if (str == nullptr) 
        return;

    PrintAllArraysCore(str, str);
}

void test1()
{
    char str[4] = "abc";
    PrintAllArrays(&str[0]);
}

void test2()
{
    char str[6] = "abcde";
    PrintAllArrays(&str[0]);
}

int main()
{
    test1();
    test2();
}
