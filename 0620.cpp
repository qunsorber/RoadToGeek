// 39：数组中出现次数超过一半的数字
// 题目：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例
// 如输入一个长度为9的数组{1, 2, 3, 2, 2, 2, 5, 4, 2}。由于数字2在数组中
// 出现了5次，超过数组长度的一半，因此输出2。
//
#include <iostream>

void quickSort(int *arr, int len) {
    if (arr == nullptr || len <= 0)
        return; 

    int cmpValue = arr[0];

    int i = 0;
    int j = len - 1;
    while (i < j){

        while (arr[j] >= cmpValue && i < j){
            j--;
        }
        arr[i] = arr[j];

        while (arr[i] <= cmpValue && i < j){
            i++;
        }
        arr[j] = arr[i];
        arr[i] = cmpValue;

        if (i == j)
            break;
    }
    quickSort(arr, i);
    quickSort(arr + i + 1, len - i - 1);
}

int GetTheNum(int *arr, int len){

    quickSort(arr, len);

    int index = len / 2;
    int result = arr[index];
    for (int i = 0; i < len; i ++){
        printf("%d ",arr[i]); 
    }
    printf("\n");
    
    return result;
}

void test(char *testname, int *arr, int len, int expected){
    int res = GetTheNum(arr, len);
    if (res == expected){
        printf("[%s passed]\n", testname);
    }
    else {
        printf("[%s failed]\n", testname);
    }
}


void test1(){
    int len = 9;
    int arr[len] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    test("test1", arr, len, 2);
}

int main()
{
    test1();
}
