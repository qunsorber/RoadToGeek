// 21：调整数组顺序使奇数位于偶数前面
// 题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有
// 奇数位于数组的前半部分，所有偶数位于数组的后半部分。
//
#include <iostream>

void printArr(int *arr, int len);

void reorder(int *arr, int len)
{
    if (arr == nullptr || len <= 0)
        return;

    int *bgn = arr;
    int *end = arr + len - 1;

    while (bgn < end)
    {
        //while (*bgn % 2 == 1) 
        while (*bgn & 0x1)
            bgn ++;

        //while (*end % 2 == 0)
        while (!(*end & 0x1))
            end --;

        if (bgn < end){
            int tmp = *bgn;
            *bgn = *end;
            *end = tmp;
            bgn ++;
            end --;
        }
    }
}

void printArr(int *arr, int len)
{
    for (int i = 0; i < len; i++){
        printf("%d",arr[i]);
    }
    printf("\n");
}

void test1()
{
    int arr1[6] = {1, 2, 3, 4, 5, 6};
    printArr(arr1, 6);
    reorder(arr1, 6);
    printArr(arr1, 6);
}

void test2()
{
    int arr1[6] = {1, 3, 2, 5, 4, 6};
    printArr(arr1, 6);
    reorder(arr1, 6);
    printArr(arr1, 6);
}

void test3()
{
    int arr1[6] = {1, 3, 5, 2, 4, 6};
    printArr(arr1, 6);
    reorder(arr1, 6);
    printArr(arr1, 6);
}

void test4()
{
    int arr1[7] = {1, 3, 2, 7, 5, 4, 6};
    printArr(arr1, 7);
    reorder(arr1, 7);
    printArr(arr1, 7);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
}
