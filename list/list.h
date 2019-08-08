#ifndef _LIST_H_
#define _LIST_H_

#include <stdlib.h>
#include <iostream>
using namespace std;
typedef int elemType;


class Node
{
private:
    elemType elem;
    Node * next;
    Node * pre;
public:
    Node(elemType elem = 0)
    {
        this->next  = NULL;
        this->pre   = NULL;
        this->elem  = elem;
    }
    ~Node()
    {
        cout << "i be delete! i m " << this->elem << endl;
    }

    void nextPoint2(Node * node = NULL)
    {
        this->next = node;
    }
    void prePoint2(Node * node)
    {
        this->pre = node;
    }

    Node * getNext()
    {
        return this->next;
    }
    
    Node * getPre()
    {
        return this->pre;
    }

    elemType & getElem()
    {
        return this->elem;
    }
};

// 双向循环链表
class List
{
private:
    Node * head;
    Node * tail;
    Node * cur;
    size_t nodeAmount;
public:
    List();
    ~List();

    static List * mergeAsendingList(List *list1, List *list2);
    static Node * _next(Node *node);
    static Node * _pre(Node *node);

    Node * traverse2MiddleNode();
    Node * locateNodeByIndex(int index);
    Node * Head();
    Node * Tail();
    void setHead(Node * head);
    void setTail(Node * tail);
    void setNodeAmount(size_t nodeAmount);

    void insertElemByIndex(int index, elemType elem, bool isFrontInsert = false);
    void delElemByIndex(int index, elemType &elem);
    void modidfyElemByIndex(int index, elemType elem);
    void searchElemByIndex(int index, elemType &elem);
    void insertHead(elemType elem);
    void insertTail(elemType elem);
    void delHead(elemType &elem);
    void delTail(elemType &elem);
    void traverse();
    void print();
    void clear();
    void destroy();


    bool isEmpty();
    bool isExistRing();

    void reverse();
    void ascendingOrderInsert(elemType elem);
    void descendingOrderInsert(elemType elem);


    int getNodeAmount();

};

#endif