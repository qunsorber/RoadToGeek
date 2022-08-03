// 50（一）：字符串中第一个只出现一次的字符
// 题目：在字符串中找出第一个只出现一次的字符。如输入"abaccdeff"，则输出
// 'b'。
//
#include <iostream>
#include <string>


char GetFirstSingleDigital(char *str){
    if (str == nullptr) return '\0';
    const int LEN = 256;
    unsigned int hashtable[LEN] = {0};
    char *p = str;
    while(*p != '\0'){
        int index = *p - '0';
        std::cout << "index:" <<  index << std::endl; 
        hashtable[index] ++;
        p ++;
    }

    p = str;
    char result = str[0];
    while(*p != '\0'){
        int index = *p - '0';
        if (hashtable[index] == 1){
            std::cout << "result index:" <<  index << std::endl; 
            result = index + '0';
            break;
        }
        p++;
    }
    return result;

}

void test(char *testname, char *str, char expected){
    char result = GetFirstSingleDigital(str);
    if (result == expected){
        printf("[%s passed!]\n", testname); 
    }
    else{
        printf("[%s failed!]\n", testname); 
    }

}

void test1(){
    char str[] = "abaccdeff";
    test("test1", str, 'b');
}

void test2(){
    char str[] = "gogole";
    test("test2", str, 'l');
}

void test3(){
    char str[] = "";
    test("test3", str, '\0');
}

int main(){
    test1();
    test2();
    test3();
}
