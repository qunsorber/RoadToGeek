// 11:旋转数组的最小数字
// 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
// {3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。

#include <iostream>

int getMinFromRotatedArr(int *arr, int len)
{
#if 0
    if(arr == nullptr || len <=0) return -1;
    int min = arr[0];
    int idx = len - 1;
    while(idx > 0){ 
       if(arr[idx] < min) min = arr[idx];
       idx --;
    }
    return min;
#else
    if(arr == nullptr || len <=0) return -1;

    int min = arr[0];

    int strIdx = 0;
    int endIdx = len - 1;
    int midIdx = (endIdx - strIdx) >> 1;
#if 0
    while(strIdx < endIdx){
        if(arr[midIdx] > arr[strIdx] || (arr[midIdx] == arr[strIdx] && arr[midIdx] > arr[endIdx])) {
            strIdx = midIdx;
            midIdx = strIdx + ((endIdx - strIdx) >> 1);
        }
        else if(arr[midIdx] < arr[endIdx] || (arr[midIdx] == arr[endIdx] && arr[midIdx] < arr[strIdx])){
            min = arr[midIdx];
            endIdx = midIdx;
            midIdx = strIdx + ((endIdx - strIdx) >> 1);
        }
        if(strIdx + 1 == endIdx){
            min = arr[endIdx];
            break;
        }
        if(arr[midIdx] == arr[strIdx] && arr[midIdx] == arr[endIdx]) {
            for(int i= 0; i < len; i++){
                if(arr[i] < min) min = arr[i];
            }
            break;
        }
    }
#else
    while(arr[strIdx] >= arr[endIdx]){
        if(arr[strIdx == arr[endIdx]] && arr[strIdx] == arr[midIdx]){
            for(int i= 0; i < len; i++){
                if(arr[i] < min) min = arr[i];
            }
            break;
        }
        if(arr[midIdx] >= arr[strIdx]){
            strIdx = midIdx;
            midIdx = strIdx + ((endIdx - strIdx) >> 1);
        }
        else if(arr[midIdx] <= arr[endIdx]){
            min = arr[endIdx];
            endIdx = midIdx;
            midIdx = strIdx + ((endIdx - strIdx) >> 1);
        }
        if(strIdx + 1 == endIdx){
            min = arr[endIdx];
            break;
        }

    }
    return min;
#endif
#endif
}

void test1()
{
    int arr[] = {3,3,3,3,1,2};
    int res = getMinFromRotatedArr(arr, 6); 
    std::cout << res << " expected result value: 1" << std::endl;
}

void test2()
{
    int arr[] = {2,2,2,2,1,2};
    int res = getMinFromRotatedArr(arr, 6); 
    std::cout << res << " expected result value: 1" << std::endl;
}

void test3()
{
    int arr[] = {3,3,3,3,3,3};
    int res = getMinFromRotatedArr(arr, 6); 
    std::cout << res << " expected result value: 3" << std::endl;
}

void test4()
{
    int arr[] = {3,3,1,3,3,3};
    int res = getMinFromRotatedArr(arr, 6); 
    std::cout << res << " expected result value: 1" << std::endl;
}

void test5()
{
    int arr[] = {3,3,3,1,3,3};
    int res = getMinFromRotatedArr(arr, 6); 
    std::cout << res << " expected result value: 1" << std::endl;
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
}
