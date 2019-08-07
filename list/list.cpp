#include "list.h"


List::List()
{
    this->head       = new Node();
    this->tail       = this->head;
    this->cur        = this->head;
    this->nodeAmount = 0;
    this->head->nextPoint2(this->head);
    this->head->prePoint2(this->head);
}

List::~List()
{
    cout << "i m be delete " << this->nodeAmount << endl;
}

Node * List::_next(Node *node)
{
    return node->getNext();
}

Node * List::_pre(Node *node)
{
    return node->getPre();
}

Node * List::traverse2MiddleNode()
{

}

Node * List::locateNodeByIndex(int index)
{
    if (index < 0)
    {
        return NULL;
    }

    Node * traverseNode = this->head;
    for(int i = 0; i < index; i++)
    {
        traverseNode = _next(traverseNode);
    }
    return traverseNode;
}

Node * List::Head()
{
    return this->head;
}

Node * List::Tail()
{
    return this->tail;
}

void List::insertElemByIndex(int index, elemType elem, bool isFrontInsert)
{
    // 大于 nodeAmount + 1 因为可能尾插
    if (index < 0 || index > this->nodeAmount + 1)
    {
        return;
    }

    if(Node * locateNode = this->locateNodeByIndex(index))
    {
        Node * newNode          = new Node(elem);
        Node * locateNodeNext   = _next(locateNode);

        this->tail = (locateNode == this->tail) ? newNode : this->tail; 
        newNode->nextPoint2(locateNodeNext);
        newNode->prePoint2(locateNode);
        locateNode->nextPoint2(newNode);
        locateNodeNext->prePoint2(newNode);
        this->nodeAmount++;
    }
}

void List::insertHead(elemType elem)
{
    this->insertElemByIndex(0, elem);
}

void List::insertTail(elemType elem)
{
    this->insertElemByIndex(this->nodeAmount, elem);
}

void List::delHead(elemType &elem)
{
    this->delElemByIndex(1, elem);
}

void List::delTail(elemType &elem)
{
    this->delElemByIndex(this->nodeAmount, elem);
}

void List::delElemByIndex(int index, elemType &elem)
{
    // 不能删除头结点哨兵
    if (index < 1 || index > this->nodeAmount)
    {
        return;
    }

    if(Node * locateNode = this->locateNodeByIndex(index))
    {
        Node * locateNodePre    = _pre(locateNode);
        Node * locateNodeNext   = _next(locateNode);

        this->tail = (locateNode == this->tail) ? locateNodePre : this->tail; 
        locateNodePre->nextPoint2(locateNodeNext);
        locateNodeNext->prePoint2(locateNodePre);
        delete locateNode;
        this->nodeAmount--;
    }

}

void List::modidfyElemByIndex(int index, elemType elem)
{

}

void List::searchElemByIndex(int index, elemType &elem)
{

}

void List::traverse()
{
    // Node * n = this->head;
    // for(int i = 0; i < this->nodeAmount; i++)
    // {
    //     n = _next(n);
    //     cout << "[" << i + 1 <<  "] = " << n->getElem() << endl;
    // }
}

void List::print()
{
    Node * n = this->head;
    for(int i = 0; i < this->nodeAmount; i++)
    {
        n = _next(n);
        cout << "[" << i + 1 <<  "] = " << n->getElem() << endl;
    }
}

void List::clear()
{
    int count = this->nodeAmount;
    elemType elem;
    for(int i = 0; i < count; i++)
    {
        this->delElemByIndex(1, elem);
    }
}

void List::destroy()
{
    delete this->head;
    delete this;
}

bool List::isEmpty()
{
    return this->tail == this->head;
}

// 他妈的双向循环绝对有环，所以还是写一下算法就好
bool List::isExistRing()
{
    // 快指针 两步
    Node *fast = this->head;
    // 慢指针 一步
    Node *slow = this->head;

    // fast next 也要不为 NULL，防止指到 NULL，再操作出现段错误
    while(fast != NULL && _next(fast) != NULL)
    {
        fast = _next(_next(fast));
        slow = _next(slow);
        if(fast == slow)
        {
            return true;
        }
    }

    return false;
}

void List::reverse()
{

}

// 返回两个升序链表的合并的新链表
List * List::createMergeAsendingList(List *list)
{
    // 需要合并的链表不存在
    if (list == NULL)
    {
        return;
    }
    Node * selfNode  = this->Head();
    Node * otherNode = list->Head();
    Node * mergeNode = this->Head();

    // 1 3 4 8 9
    // 2 6 7 10
    while(selfNode->getNext())
    {
        selfNode = _next(selfNode);
    }
}

// 将传入的链表合并
void List::mergeAsendingList(List *list)
{
    // 需要合并的链表不存在
    if (list == NULL)
    {
        return;
    }
    Node * selfNode  = this->Head();
    Node * otherNode = list->Head();
    Node * mergeNode = this->Head();

    // 1 3 4 8 9
    // 2 6 7 10
    while(selfNode->getNext())
    {
        selfNode = _next(selfNode);
    }
}

void List::ascendingOrderInsert(elemType elem)
{
    Node * node = this->head;
    for(int i = 0; i < this->nodeAmount; i++)
    {
        node = _next(node);
        //1 2 3 5 77 10
        if (elem <= node->getElem())
        {
            this->insertElemByIndex(i, elem);
            return;
        }
    }
    this->insertTail(elem);
}

void List::descendingOrderInsert(elemType elem)
{
    Node * node = this->head;
    for(int i = 0; i < this->nodeAmount; i++)
    {
        node = _next(node);
        // 77 5 1 
        if (elem > node->getElem())
        {
            this->insertElemByIndex(i, elem);
            return;
        }
    }
    this->insertHead(elem);
}


int List::getNodeAmount()
{
    return this->nodeAmount;
}