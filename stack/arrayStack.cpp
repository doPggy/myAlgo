#include "arrayStack.h"
using namespace std;
/*
    不做动态扩容
*/

//构造函数，创建栈
//类模板成员函数的写法  template<class T> 返回值类型 类名<T>::成员函数名(参数列表){}
template<class T> ArrayStack<T>::ArrayStack()
{
    this->array = new T[INIT];
    if (NULL == this->array)
    {
        cout << "mem error! " << endl;
        return ;
    }

    this->head = 0;
    this->size = INIT;
    this->len  = 0;
}


template<class T> ArrayStack<T>::~ArrayStack()
{
    this->head = 0;
    this->size = 0;
    this->len  = 0;

    if (this->array)
    {
        delete []this->array;
        this->array = NULL;
    }

}


template<class T> void ArrayStack<T>::push(T item)
{
    // 栈满了
    if (this->len == this->size)
    {
        cout << "full !" << endl;
        return ;
    }

    this->array[this->head++] = item;
    this->len++;
}

template<class T> T ArrayStack<T>::pop()
{
    //栈空
    if (0 == this->len)
    {
        cout << "empty!" << endl;
    }

    this->len--;
    return this->array[--this->head];
}

template<class T> void ArrayStack<T>::dump()
{
    int i = 0;

    for(i = 0; i < this->head; i++)
    {
        cout << "stack[" << i << "] is " << this->array[i]  << endl;
    }

    return ;
}
template<class T> T ArrayStack<T>::getTop()
{
    if (this->len)
    {
        return this->array[this->head - 1];
    }
}

int main(int argc, char const *argv[])
{
    // 模拟浏览器前进后退
    ArrayStack <int> back;
    ArrayStack <int> gohead;

    // ArrayStack<int> *array = new ArrayStack<int>();
    cout << "networking !" << endl;
    cout << "3 page !" << endl;

    back.push(1);
    back.push(2);
    back.push(3);

    cout << "i have see 3 page, list: " << endl;
    back.dump();

    cout << "now) , i want to back to view twice " << endl;
    gohead.push(back.pop());
    gohead.push(back.pop());

    cout << "now i want to gohead to view"  << endl;
    back.push(gohead.pop());


    cout << "list: " << endl;
    back.dump();

    cout << "kuohao test =========" << endl;
    char expr[20] = "";
    char *p = expr;
    ArrayStack <char> exprstack;

    cin >> expr;
    cout << "test expr is " << expr << endl;
    while(*p)
    {

        if (*p == '{'
         || *p == '('
         || *p == '[')
        {
            exprstack.push(*p);
        }
        else
        {
            char tmp = *p - exprstack.getTop();
            if (tmp >= 1 && tmp <= 2)
            {
                exprstack.pop();
            }
            else
            {
                cout << "illgal !" << endl;
                break;
            }

        }
        p++;
    }

    return 0;
}
