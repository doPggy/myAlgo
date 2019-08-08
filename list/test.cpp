#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void testMerge()
{
    // 测试链表合并
    List *aList1 = new List();
    aList1->ascendingOrderInsert(1);
    aList1->ascendingOrderInsert(5);
    aList1->ascendingOrderInsert(3);
    aList1->ascendingOrderInsert(66);
    aList1->ascendingOrderInsert(33);
    aList1->ascendingOrderInsert(22);
    aList1->print();
    
    List *aList2 = new List();
    aList2->ascendingOrderInsert(2);
    aList2->ascendingOrderInsert(4);
    aList2->ascendingOrderInsert(7);
    aList2->ascendingOrderInsert(21);
    aList2->ascendingOrderInsert(26);
    // aList2->ascendingOrderInsert(77);
    aList2->print();

    List *mergeList = List::mergeAsendingList(aList1, aList2);
    mergeList->print();
}

void testOrderInsert()
{
    List *aList = new List();
    aList->ascendingOrderInsert(1);
    aList->ascendingOrderInsert(5);
    aList->ascendingOrderInsert(3);
    aList->ascendingOrderInsert(66);
    aList->ascendingOrderInsert(33);
    aList->ascendingOrderInsert(22);
    aList->print();
    aList->destroy();

    List *dList = new List();
    dList->descendingOrderInsert(1);
    dList->descendingOrderInsert(5);
    dList->descendingOrderInsert(3);
    dList->descendingOrderInsert(66);
    dList->descendingOrderInsert(33);
    dList->descendingOrderInsert(22);
    dList->print();
    dList->destroy();
}

int main()
{
    if(char * l = NULL)
    {
        printf("i m in\n");
    }

    List *list = new List();
    list->insertElemByIndex(1, 3);
    list->insertElemByIndex(1, 4);
    list->insertElemByIndex(1, 5);
    list->insertElemByIndex(1, 6);
    list->insertHead(10);
    list->insertTail(100);
    list->print();
    // 10 3 6 5 4 100

    elemType elem;
    list->delElemByIndex(2, elem);
    list->print();
    // 10 6 5 4 100

    list->delElemByIndex(3, elem);
    list->print();
    // 10 6 4 100

    list->delTail(elem);
    list->print();
    // 10 6 4
    
    list->delHead(elem);
    list->print();
    // 6 4

    cout << "is exsit ring ? " << (list->isExistRing() ? "yes" : "no") << endl;
    list->destroy();

    testOrderInsert();
    testMerge();
    
    return 0;
}