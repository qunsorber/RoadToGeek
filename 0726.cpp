// 46：把数字翻译成字符串
// 题目：给定一个数字，我们按照如下规则把它翻译为字符串：0翻译成"a"，1翻
// 译成"b"，……，11翻译成"l"，……，25翻译成"z"。一个数字可能有多个翻译。例
// 如12258有5种不同的翻译，它们分别是"bccfi"、"bwfi"、"bczi"、"mcfi"和
// "mzi"。请编程实现一个函数用来计算一个数字有多少种不同的翻译方法。
//
#include <iostream>
#include <string>
#include <vector>

int Num2Str(int number, char *str){
    int len = 0;
    while(number){
        int end = number % 10;
        *(str + len) = end + '0';
        number = number / 10;
        len ++;
    }

    for (int i = 0; i < len/2; i++){
        int tmp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = tmp;
    }
    return len;
}

std::vector<std::string> TranslateToString(int number){
    std::vector<std::string> result;
    char strofnum[128] = {0};
    int length = Num2Str(number, strofnum);
    strofnum[length] = '\0';
    // first one single to single 
    std::string str0;
    int i = 0;
    while(strofnum[i] != '\0'){
        char ch = strofnum[i] - '0' + 'a';
        str0.push_back(ch); 
        i ++;
    }
    result.push_back(str0);
    
    while(strofnum[i] != '\0'){
         
    }

    return result;
}


void test1()
{
    int number = 12258;
    auto result = TranslateToString(number);
    for(auto &i : result){
        std::cout << i << std::endl;
        //printf("%s\n", &i[0]);
    }
}

int main()
{
    test1();
}
