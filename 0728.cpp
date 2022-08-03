// 47：礼物的最大价值
// 题目：在一个m×n的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值
// （价值大于0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向左或
// 者向下移动一格直到到达棋盘的右下角。给定一个棋盘及其上面的礼物，请计
// 算你最多能拿到多少价值的礼物？
//
#include <iostream>

int GetMaxValueGiftCore(int *arr, int row, int col, int rows, int cols){
    int result = 0;
    if (row == 0){
        for (int i = 0; i < col; i++){
            result += arr[i]; 
        }
        return result + arr[col];
    }
    if (col == 0){
        for (int i = 0; i < row; i++){
            result +=arr[i*rows];
        }
        return result + arr[row*cols];
    }
    
    int a = GetMaxValueGiftCore(arr, row-1, col, rows, cols);
    int b = GetMaxValueGiftCore(arr, row, col-1, rows, cols);
    result = a > b ? a : b;
    return  result + arr[row*cols+col];

}

int GetMaxValueGift(int *arr, int rows, int cols){
    if (arr == nullptr || rows < 0 || cols < 0) return 0;

    int result = GetMaxValueGiftCore(arr, rows - 1, cols -1 , rows, cols);
    std::cout << "result:" << result << std::endl;
    return result;
}

//  1   3   7   32   8  
//  4  97   5    2   1  
// 23   5  78    6  10  
//  8   7  23   63   5
void test1(){
    int arr[20] = {1,3,7,32,8,4,97,5,2,1,23,5,78,6,10,8,7,23,63,5};
    int result = GetMaxValueGift(arr, 4, 5);
}

void test2(){
    int arr[4] = {1,3,4,97};
    int result = GetMaxValueGift(arr, 2, 2);
}

int main(){
    test1();
    test2();
}
