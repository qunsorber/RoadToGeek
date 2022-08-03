#include <iostream>

// 不修改数组找出重复的数字
// 题目：在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至
// 少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
// 数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的
// 输出是重复的数字2或者3。

// 参数:
//        numbers:     一个整数数组
//        length:      数组的长度
// 返回值:             
//        正数  - 输入有效，并且数组中存在重复的数字，返回值为重复的数字
//        负数  - 输入无效，或者数组中没有重复的数字
int countBetweenRange(const int* numbers, int length, int start, int end);

int getDuplication(const int* numbers, int length)
{
    if (numbers == nullptr || length <= 0)
        return false;
    
#if 1
    // allow additional o(n) to copy a new array
    int tmp[length] = {0};

    for(int i = 0; i < length; i++){
        int val = numbers[i];
        if(val < 0 || val >= length)
            return false;

        if(++tmp[val] > 1){
            return val;
            break;
        }
    }

    return false;
#else 
    // not allow o(n) space to put data
    int srt = 1;
    int end = length - 1;
    while (end > srt) {
        int mid = (end + srt) >> 1;

        int cnt = countBetweenRange(numbers,length, srt, mid);
        std::cout << "in circle!!" << srt << "--"<< mid << "--" << end<< "--" << cnt << std::endl;
        if(cnt <= mid - srt + 1){
            srt = mid + 1;
        }
        else{
            end = mid;
        }
        if (srt == end) return numbers[srt];
    }

#endif
}

int countBetweenRange(const int* numbers, int len, int srt, int end){
    if(numbers == nullptr ) return false;
    int cnt = 0;
    for (int i = 0; i <= len; i++){
        if(numbers[i] >= srt && numbers[i] <= end)
            cnt ++;
    }
    return cnt;

}
void test1()
{
    int arr[] = {2, 3, 5, 4, 3, 2, 6, 7};

    int res = getDuplication(arr,8);

    std::cout << "res: " << res << std::endl; 
}

void test2()
{
    int arr[] = {2, 3, 5, 4, 1, 6, 7, 0};

    int res = getDuplication(arr,8);

    std::cout << "res: " << res << std::endl; 

}

void test3()
{
    int arr[] = {2, 3, 5, 4, -1, 6, 7, 0};

    int res = getDuplication(arr,8);

    std::cout << "res: " << res << std::endl; 

}

void test4()
{
    int arr[] = {2, 3, 5, 4, 1, 6, 7, 0};

    int res = getDuplication(arr,2);

    std::cout << "res: " << res << std::endl; 

}

int main()
{
   test1(); 
   test2(); 
   test3(); 
   test4(); 
}
