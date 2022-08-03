// 42：连续子数组的最大和
// 题目：输入一个整型数组，数组里有正数也有负数。数组中一个或连续的多个整
// 数组成一个子数组。求所有子数组的和的最大值。要求时间复杂度为O(n)。

#include <iostream>

int GetMaxSum(int* arr, int len){
    int max = 0; 
    int i = 0;
    int sum = 0;
    while (i < len){
        if (arr[i] < 0) max = sum;

        sum += arr[i];  
        if (sum < 0) sum = 0;
        i++;
    }
    if (sum > max) max = sum;
    return max;
}

void test(char* testName, int*arr, int len, int expectedMax){
    int result = GetMaxSum(arr, len);
    if (result == expectedMax){
        printf("[%s passed!]\n", testName);
    }
    else{
        printf("[%s failed!]\n", testName);
    }
}

void test1()
{
    int array[] = {1, -3, 8, 2, -4, 9, 5};
    test("test1", array, sizeof(array)/sizeof(int), 20);
}


int main()
{
    test1();
}
