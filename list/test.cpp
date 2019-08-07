#include <stdio.h>
#include <stdlib.h>
#include "list.h"

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
    return 0;
}