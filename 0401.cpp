// 17：打印1到最大的n位数
// 题目：输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则
// 打印出1、2、3一直到最大的3位数即999。
//
#include <iostream>

void print1ToNCore(char *a, int idx, unsigned int n)
{
    if (idx >= n) return;

    while(a[idx] <= 9 + '0'){
        print1ToNCore(a, idx + 1, n);
        a[idx] += 1;
        if(a[idx] > 9 + '0') continue;
        printf("%s ", a);
    }
    a[idx] = '0';
    printf("\n");
}

//void print1ToNCore(char *a, int idx)
//{
//    if (idx < 0) return;
//    while (a[idx] <= 9 + '0') {
//        print1ToNCore(a, idx - 1);
//        a[idx] += 1;
//        if (a[idx] > 9 + '0') continue;
//        printf("%s ", a);
//    }
//    a[idx] = '0';
//    printf("\n");
//}

void print1ToN(int n)
{
    if(n <= 0) {
        printf("input illegal!\n"); 
        return;
    }

    char a[n + 1] = {0};
    a[n] = '\0';
    for(int i = 0; i < n; i++){
        a[i] = '0';
    }

    print1ToNCore(a, 0, n);
    //print1ToNCore(a, n - 1);
}


void test1()
{
    print1ToN(2);
}

void test2()
{
    print1ToN(-1);
}

int main()
{
    test1();
    test2();
}
