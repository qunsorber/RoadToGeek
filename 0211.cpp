#include <iostream>

// 找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。
bool duplicate(int numbers[], int length, int* duplication)
{
    *duplication = -1;
    if(numbers == nullptr || length < 2)
        return false;
    for(int idx = 0; idx < length; idx ++){
        while(numbers[idx] != idx){
            if (numbers[idx] < idx){
            //if (numbers[idx] == numbers[numbers[idx]]){
                *duplication = numbers[idx];
                std::cout << "find duplicated number!" << std::endl;
                return true;
            }
            //swap numbers[idx] <--> numbers[numbers[idx]] 
            if(numbers[idx] > idx){
                if(numbers[idx] >= length){
                    std::cout << "input number beyond range!" << std::endl;
                    return false;
                }
                //swap(numbers[idx],numbers[numbers[idx]]);
                int temp = numbers[idx];
                numbers[idx] = numbers[temp];
                numbers[temp] = temp;
            }
        }
    }
    return false;
}

void test1()
{
    int arr[] = {1};
    int dul = 0;
    int res = duplicate(arr,1,&dul);
    std::cout << res << "   " << dul << std::endl;
}

void test2()
{
    int arr[] = {2, 3, 1, 0, 2, 5, 3};
    int dul = 0;
    int res = duplicate(arr,7,&dul);
    std::cout << res << "   " << dul << std::endl;
}

void test3()
{
    int arr[] = {2, 3, 1, 7, 2, 5, 3};
    int dul = 0;
    int res = duplicate(arr,7,&dul);
    std::cout << res << "   " << dul << std::endl;
}

void test4()
{
    int arr[] = {2, 3, 1, 0, 2, 5, 3};
    int dul = 0;
    int res = duplicate(arr,5,&dul);
    std::cout << res << "   " << dul << std::endl;
}


int main()
{
    test1();
    test2();
    test3();
    test4();
}
