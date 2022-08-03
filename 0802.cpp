// 51：数组中的逆序对
// 题目：在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组
// 成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
//
#include <iostream>

int GetNumReversePairs(int *arr, int len){
#if 0
    if (arr == nullptr || len <= 0) return -1;
    int result = 0;
    int i = 1;
    int front = arr[0];
    while(i < len){
        if (front > arr[i]){
            result ++; 
        }
        front = arr[i];
        i++;
    }
    return result;
#else
    if (arr == nullptr || len <= 0) return -1;
    int result = 0;
    int i = 0;
    while(i < len){
        int j = i + 1;
        while(j < len){
            if (arr[j] < arr[i]){
                result ++; 
            }
            j ++;
        }
        i ++;
    }
    std::cout << "result:" << result << std::endl;
    return result;
#endif
}

void test(char *testname, int *arr, int len, int expected){
    int result = GetNumReversePairs(arr, len);
    if (result == expected)
        printf("[%s passed!]\n", testname);
    else
        printf("[%s failed!]\n", testname);
}

void test1(){
    int arr[] = {3, 5, 8, 2, 5, 7, 3, 9, 1};
    test("test1", arr, sizeof(arr)/sizeof(int), 17);
}

int main(){
    test1();
}
