// 53（一）：数字在排序数组中出现的次数
// 题目：统计一个数字在排序数组中出现的次数。例如输入排序数组{1, 2, 3, 3,
// 3, 3, 4, 5}和数字3，由于3在这个数组中出现了4次，因此输出4。
//
#include <iostream>

int GetTimes(int *arr, int len, int num){
    if (arr == nullptr || len <= 0) return 0;
    if (arr[0] > num || arr[len-1] < num) return 0;

    int mid = len / 2;
    int latterlen = len / 2 + len % 2 - 1;
    int cnt = 0;
    if (arr[mid] == num) {
        cnt ++;
        cnt += GetTimes(arr, len / 2, num);
        cnt += GetTimes(arr + len / 2 + 1, latterlen, num);
    }
    else if (arr[mid] > num){
        cnt += GetTimes(arr, len / 2, num);
    }
    else {
        cnt += GetTimes(arr + len / 2 + 1, latterlen, num);
    }
    return cnt;
}

void test(char *testname, int *arr, int len, int num, int expected){
    int result = GetTimes(arr, len, num);
    if (result == expected){
        printf("[%s passed!]\n", testname); 
    }
    else{
        printf("[%s failed!]\n", testname); 
    }
}

void test1(){
    int arr[] = {1, 2, 3, 3, 3, 3, 4, 5};
    test("test1", arr, sizeof(arr)/sizeof(int), 3, 4);
}

int main(){
    test1();
}
