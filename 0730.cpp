// 49：丑数
// 题目：我们把只包含因子2、3和5的数称作丑数（Ugly Number）。求按从小到
// 大的顺序的第1500个丑数。例如6、8都是丑数，但14不是，因为它包含因子7。
// 习惯上我们把1当做第一个丑数。
//
#include <iostream>

int GetKthUglyNum(int k){

}

bool IsUglyNum(int num){
    while(num % 2 == 0){
        num = num / 2; 
    }
    while(num % 3 == 0){
        num = num / 3; 
    }
    while(num % 5 == 0){
        num = num / 5; 
    }
    return num == 1;
}

void test1(){
    int result = IsUglyNum(24);
    std::cout << "result:"  << result << std::endl;
}

int main(){
    test1();
}

// 1  == 2^0 * 3^0 * 5^0
// 2  == 2^1 * 3^0 * 5^0
// 3  == 2^0 * 3^1 * 5^0
// 4  == 2^2 * 3^0 * 5^0
// 5  == 2^0 * 3^0 * 5^1
// 6  == 2^1 * 3^1 * 5^0
// 8  == 2^3 * 3^0 * 5^0
// 9  == 2^0 * 3^2 * 5^0
// 10 == 2^1 * 3^0 * 5^1
// 12 == 2^2 * 3^1 * 5^0
// 15 == 2^0 * 3^1 * 5^1
// 18 == 2^1 * 3^2 * 5^0
// 20 == 2^2 * 3^0 * 5^1
//  
