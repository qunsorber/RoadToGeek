// 替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。

#include <iostream>
#include <string>

/*length 为字符数组str的总容量，大于或等于字符串str的实际长度*/
void ReplaceBlanks(char str[], int length)
{
    if(str == nullptr || length <=0) return;

    int orglen = 1;
    int blanks = 0;
    int newlen = 0;

    int i = 0;
    while(str[i] != '\0'){
        if(str[i] == ' ') blanks ++;
        orglen ++;
        i ++;
    }
    newlen = orglen + blanks * 2;
    std::cout << orglen << "    " << blanks << "    " << newlen << std::endl;
    
    if(newlen > length) return;
    // str[i--] = a <==>str[i] = a; i--;
    while (orglen >=0 && newlen > orglen){
        if(str[orglen] == ' ') {
            str[newlen--] = '0';
            str[newlen--] = '%';
            str[newlen--] = '2';
            orglen--;
        }
        else{
            str[newlen--] = str[orglen--];
        }
    }
}

void test1()
{
    int length = 32;
    char str[length] = "we are not happy!";
    ReplaceBlanks(str,length);
    std::cout << str << std::endl;
}

void test2()
{
    int length = 32;
    char str[length] = " we are not happy!";
    ReplaceBlanks(str,length);
    std::cout << str << std::endl;
}

void test3()
{
    int length = 32;
    char str[length] = "wearenothappy!";
    ReplaceBlanks(str,length);
    std::cout << str << std::endl;
}

void test4()
{
    int length = 32;
    char str[length] = "we are not happy! ";
    ReplaceBlanks(str,length);
    std::cout << str << std::endl;
}

void test5()
{
    int length = 32;
    char str[length] = "we are  not  happy!";
    ReplaceBlanks(str,length);
    std::cout << str << std::endl;
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
}