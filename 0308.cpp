// 12：矩阵中的路径
// 题目：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有
// 字符的路径。路径可以从矩阵中任意一格开始，每一步可以在矩阵中向左、右、
// 上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入
// 该格子。例如在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字
// 母用下划线标出）。但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个
// 字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
// A B T G
// C F C S
// J D E H

#include <iostream>

bool hasPathCore(const char* matrix, int row, int rows, int col, int cols, const char* str, bool *visit, int len);

bool hasPath(const char* matrix, int rows, int cols, const char* str)
{
    if(matrix == nullptr || rows <= 0 || cols <= 0 || str == nullptr) return false;

    bool visit[rows*cols] = {0};
    int strlen = 0;

    int currow = 0;
    int curcol = 0;
    for(int row = 0; row < rows; row ++){
        for(int col = 0; col < cols; col ++){
            bool hasPath = hasPathCore(matrix, row, rows, col, cols, str, visit, strlen);
            if(hasPath) return true;
        }
    }
    return false;
}

bool hasPathCore(const char* matrix, int row, int rows, int col, int cols, const char* str, bool *visit, int len)
{
    if(str[len]=='\0') return true;

    if(row < 0 || row >= rows || col < 0 || col >= cols) return false;

    if(str[len] == matrix[row*cols+col] && visit[row*cols+col] == 0){ 
        len ++;
        visit[row*cols + col] = 1;
        bool result =  hasPathCore(matrix,row+1,rows,col,cols,str,visit,len) || 
                       hasPathCore(matrix,row-1,rows,col,cols,str,visit,len) ||
                       hasPathCore(matrix,row,rows,col+1,cols,str,visit,len) ||
                       hasPathCore(matrix,row,rows,col-1,cols,str,visit,len);
        if(result) return true;
    }
    else{
       return false;
    }
    
}

void test1()
{
    const char matrix[] = "abtgcfcsjdeh";
    const char str[] = "bfce";
    bool res = hasPath(matrix, 3, 4, str);
    std::cout << "res:" << res << " expected value:1" << std::endl;

}

void test2()
{
    const char matrix[] = "abtgcfcsjdeh";
    const char str[] = "bfcg";
    bool res = hasPath(matrix, 3, 4, str);
    std::cout << "res:" << res << " expected value:0" << std::endl;

}

void test3()
{
    const char matrix[] = "abtgcfcsjdeh";
    const char str[] = "tcfd";
    bool res = hasPath(matrix, 3, 4, str);
    std::cout << "res:" << res << " expected value:1" << std::endl;

}

int main()
{
    test1();
    test2();
    test3();
}
//this is for test vim 
//foobar
//varibale      |       function = 1;
//varibale      |       bar = 'I feel good'; 
//varibale---------------------------
//varibale      |       foobar = + bar;
