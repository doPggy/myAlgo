#ifndef _ARRAYSTACK_H_
#define _ARRAYSTACK_H_


#include <iostream>
using namespace std;

#define     INIT        20

template <class T> 
class ArrayStack
{
public:
    ArrayStack();
    ~ArrayStack();

    void push(T item);
    T pop();
    T getTop();
    void dump();


private:
    T * array; //顺序栈数组
    int head; //栈顶指针，指向栈顶元素的下一个
    int size; //当前栈最大长度
    int len; //栈当前长度
};

#endif



