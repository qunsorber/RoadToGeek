// 44：数字序列中某一位的数字
// 题目：数字以0123456789101112131415…的格式序列化到一个字符序列中。在这
// 个序列中，第5位（从0开始计数）是5，第13位是1，第19位是4，等等。请写一
// 个函数求任意位对应的数字。
//
#include <iostream>
#include <cmath>

int IHasNums(int i){
    if (i == 1) 
        return 10;
    else
        return pow(10, i) - pow(10, (i - 1));
}

int StartFromI(int i){
    if (i == 1)
        return 0;
    else
        return pow(10, (i - 1));
}
int GetTheNumber(int rank){
    rank = rank + 1;
    int i = 1;
    while (1){
        int digSum = i * IHasNums(i);
        if (rank > digSum)
            rank = rank - digSum;
        else
            break;
        i ++;
    }
    int a = rank / i;
    int b = rank % i;

    int resultNum = StartFromI(i) + a - 1;
    int result = 0;
    if (b == 0){
        result = resultNum % 10;
    }
    else{
        resultNum ++;
        result = int(resultNum / pow(10, (i - b))) % 10;
    }
    return result;
}

// 321 
// b = 1  3
// b = 2  2 
// 4537
// b = 1  4
// b = 2  5
// b = 3  3
void test(char *testname, int input, int expected){
    int result = GetTheNumber(input);
    if (result == expected){
        printf("[%s test passed!]\n", testname);
    }
    else{
        printf("[%s test failed!]\n", testname);
    }
}

void test1(){
    test("test1", 5, 5);
}


void test2(){
    test("test2", 13, 1);
}


void test3(){
    test("test3", 19, 4);
}

void test4(){
    test("test4", 189, 9);
}

void test5(){
    test("test5", 190, 1);
}

void test6(){
    test("test6", 1000, 3);
}

void test7(){
    test("test7", 1001, 7);
}

void test8(){
    test("test8", 1002, 0);
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
}
