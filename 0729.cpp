// 48：最长不含重复字符的子字符串
// 题目：请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子
// 字符串的长度。假设字符串中只包含从'a'到'z'的字符。

#include <iostream>

int GetMaxSubStrLen(char *str, int len){
    if (str == nullptr || len <= 1) return 0;
    int maxlen = 1;
    char *head = str;
    char *cur = str++;
    while(*cur != '\0'){
        char *tmpsub = head;
        int len = 1;
        while(tmpsub != cur){
            if (*cur != *tmpsub){
                len ++;
                maxlen = maxlen > len ? maxlen : len;
            }
            else{
                head = ++tmpsub;
                break;
            }
            tmpsub++;
        }
        cur++; 
    }
    return maxlen;
}

void test(char *testname, char *str, int len, int expected){
    int result = GetMaxSubStrLen(str, len);
    if (result == expected){
        printf("[%s passed!]\n", testname); 
    }
    else{
        printf("[%s failed!]\n", testname); 
    }
}

void test1(){
    char str[] = "abcacfrar";
    test("test1", str, 10, 4);
}

void test2(){
    char str[] = "acfrarabc";
    test("test2", str, 10, 4);
}

void test3(){
    char str[] = "arabcacfr";
    test("test3", str, 10, 4);
}

void test4(){
    char str[] = "aaaa";
    test("test4", str, 5, 1);
}

void test5(){
    char str[] = "abcdefg";
    test("test5", str, 8, 7);
}

void test6(){
    char str[] = "aaabbbccc";
    test("test6", str, 10, 2);
}

void test7(){
    char str[] = "abcdcba";
    test("test7", str, 8, 4);
}

void test8(){
    char str[] = "abcdaef";
    test("test8", str, 10, 6);
}

void test9(){
    char str[] = "a";
    test("test9", str, 2, 1);
}

void test10(){
    char str[] = "";
    test("test10", str, 1, 0);
}


int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
}
