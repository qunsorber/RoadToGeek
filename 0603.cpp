// 29：顺时针打印矩阵
// 题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
//
#include <iostream>

void PrintMatrix(int *mat, int row, int col){
    if (!mat || row <= 0 || col <= 0) 
       return;
    int flag[row][col] = {0};

    int i = 0;
    int j = 0;
    int start = 0;
    while (start * 2 < row && start * 2 < col){
        while (j < col - start - 1) {
            printf("%d--", mat[i*col + j]);
            j ++;
        }
        // i = 0; j = col - 1
        while (i < row - start - 1) {
            printf("%d--", mat[i*col + j]);
            i ++;
        }
        // i = row - 1; j = col -1
        while (j > start){
            printf("%d--", mat[i*col + j]);
            j --;
        }
        // i = row - 1; j = 0
        while (i > start) {
            printf("%d--", mat[i*col + j]);
            i --;
        }
        // i = 0; j = 0;
        i ++;
        j ++;
        start ++;
        //break;
    }
    printf("\n");
}

//  3 5 7 8
//  2 4 3 1
//  3 5 2 3
void test1()
{
    int matrix[3][4] = {{3,5,7,8},
                        {2,4,3,1},
                        {3,5,2,3}};
    PrintMatrix((int *)matrix, 3, 4);

}

void test2()
{
    int matrix[2][3] = {{3,5,8},
                        {3,5,3}};
    PrintMatrix((int *)matrix, 2, 3);

}

int main()
{
    test1();
    test2();
}


