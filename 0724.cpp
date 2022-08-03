// 45：把数组排成最小的数
// 题目：输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼
// 接出的所有数字中最小的一个。例如输入数组{3, 32, 321}，则打印出这3个数
// 字能排成的最小数字321323。
//
#include <iostream>
#include <cstring>

int GetIntLength(int n){
    int len = 0;
    while(n){
       n = n / 10; 
       len ++;
    }
    return len;
}

void Int2Str(char* dst, int input, int len){
    for (int i = len - 1; i >= 0; i--){
        dst[i] = input % 10 + '0';
        input = input / 10;
    }
}

int MySort(int a, int b){
    int len_a = GetIntLength(a); 
    int len_b = GetIntLength(b); 
    char sa[len_a + 1] = {0};
    char sb[len_b + 1] = {0};
    Int2Str(sa, a, len_a);
    Int2Str(sb, b, len_b);

    int len_ab = len_a + len_b + 1;
    char sasb[len_ab] = {0};
    char sbsa[len_ab] = {0};
    memcpy(sasb, sa, len_a);
    memcpy(sasb + len_a, sb, len_b);
    //printf("sasb:%s\n",sasb);
    memcpy(sbsa, sb, len_b);
    memcpy(sbsa + len_b, sa, len_a);
    //printf("sbsa:%s\n", sbsa);

    for (int i = 0; i < len_ab; i++){
        if (sasb[i] < sbsa[i]) 
            return 0;
        else if (sasb[i] > sbsa[i])
            return 1;
    }
    return 2;
}

void SortMinDigital(int *data, int len){
    int base = data[0];
    int i = 0;
    int j = len - 1;
    while(i < j){
        while(MySort(base, data[j]) == 0 && i < j){
            j--;     
        }
        data[i] = data[j];

        while(MySort(base, data[i]) == 1 && i < j){
            i++; 
        }
        data[j] = data[i];
        data[i] = base;
        SortMinDigital(data, i); 
        SortMinDigital(data + i + 1, len - i - 1); 
    }
}

void PrintStringOfArr(int *data, int len){
    SortMinDigital(data, len);
    for (int i = 0; i < len; i++){
        printf("%d", data[i]);
    }
    printf("\n");
}

void test1(){
    int data[] = {123, 45, 8, 7, 55, 32, 11, 22, 321}; 
    PrintStringOfArr(data, sizeof(data)/sizeof(int));
}

void test2(){
    int data[] = {1, 12, 123}; 
    PrintStringOfArr(data, sizeof(data)/sizeof(int));
}

int main(){
    test1();
    test2();
}
