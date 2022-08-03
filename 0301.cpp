//9：用两个栈实现队列
// 题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail
// 和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。

#include <iostream>
#include <stack>

template<typename T>
class MyQueue
{
public:
    MyQueue(){};
    void appendTail(T t);
    void deleteHead();
private:
    std::stack<T> s1;
    std::stack<T> s2;
};

template<typename T>
void MyQueue<T>::appendTail(T t)
{
    s1.push(t);
    std::cout << s1.top() << "  was pushed!" << std::endl;
}

template<typename T>
void MyQueue<T>::deleteHead()
{
    if(!s2.empty()){
        std::cout << s2.top() << "  was deleted!" << std::endl;
        s2.pop();
    } 
    else{
        while(!s1.empty()){
            T t = s1.top();
            s2.push(t);
            s1.pop();
        }
        std::cout << s2.top() << "  was deleted!" << std::endl;
        s2.pop();
    }
}

void test1()
{
    MyQueue<int> q1;
    q1.appendTail(5);
    q1.appendTail(10);
    q1.appendTail(15);
    q1.deleteHead();
    q1.appendTail(25);
    q1.appendTail(35);
    q1.deleteHead();
}

int main()
{
    test1();
}