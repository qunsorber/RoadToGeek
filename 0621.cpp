// 40：最小的k个数
// 题目：输入n个整数，找出其中最小的k个数。例如输入4、5、1、6、2、7、3、8
// 这8个数字，则最小的4个数字是1、2、3、4。

#include <iostream>

int QuickSortOnce(int *arr, int k, int len){
    int base = arr[k]; 
    int i = 0;
    int j = len - 1;
    arr[k] = arr[i];
    arr[i] = base;
    while (i < j){
        while (arr[j] >= base && i < j) {
            j--; 
        }
        arr[i] = arr[j];
        
        while (arr[i] < base && i < j) {
            i++;
        }
        arr[j] = arr[i];
    }
    arr[i] = base;
    return i; 
}

void GetKMinNum(int* arr, int len, int k)
{
    if (arr == nullptr || len <= 0 || k > len) 
        return;

    int index = QuickSortOnce(arr, k, len); 
    printf("index :%d\n", index);
    for (int i = 0; i < len; i++){
        printf("%d ", arr[i]); 
    }
    printf("\n");
    //if (index >= k - 1) // index compare to num
    //    return;
    //else 
    //    GetKMinNum(arr, len, k); 
}

void test(char *testname, int *arr, int len, int k, int *expected){
    GetKMinNum(arr, len, k); 
    for (int i = 0; i < len; i++){
        printf("%d ", arr[i]); 
    }
    printf("\n");

    //for (int i = 0; i < k; i++){
    //    if (expected[i] != arr[i]){
    //        printf("%s failed\n", testname); 
    //        return;
    //    }
    //}
    //printf("%s passed", testname);
}

//4、5、1、6、2、7、3、8
void test1()
{
    int len = 8;
    int k = 4;
    int arr[len] = {4, 5, 1, 6, 2, 7, 3, 8};
    int res[k] = {1, 2, 3, 4};
    test("test1", arr, len, 4, res);
}


int main()
{
    test1();
}
