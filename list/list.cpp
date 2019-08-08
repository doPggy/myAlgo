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

static Node * 
_next(Node *node)
{
    return node->getNext();
}

static Node * 
_pre(Node *node)
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
        traverseNode = List::_next(traverseNode);
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

void List::setHead(Node * head)
{
    this->head = head;
}

void List::setTail(Node * tail)
{
    this->tail = tail;
}

void List::setNodeAmount(size_t nodeAmount)
{
    this->nodeAmount = (nodeAmount >= 0) ? nodeAmount : this->nodeAmount;
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
        Node * locateNodeNext   = List::_next(locateNode);

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
        Node * locateNodeNext   = List::_next(locateNode);

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
        n = List::_next(n);
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
    while(fast != NULL && List::_next(fast) != NULL)
    {
        fast = List::_next(List::_next(fast));
        slow = List::_next(slow);
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
// O(m + n) m = list1->nodeAmount, n = list2->nodeAmount
static List * 
mergeAsendingList(List *asendingList1, List *asendingList2)
{
    // 需要合并的链表不存在
    if (asendingList1 == NULL or asendingList2 == NULL)
    {
        return NULL;
    }

    Node * mergeNode = asendingList1->Head();
    Node * node1     = List::_next(asendingList1->Head());
    Node * node2     = List::_next(asendingList2->Head());
    // TODO: 如下算法其实可以使用两个链表的长度去判断，这里只使用遍历这个逻辑

    // 0 2 6 7 
    // 0 1 3 4 8 9
    // list2 会剩下一个 list 和 头结点
    
    // 合并后长度增加
    asendingList1->setNodeAmount(asendingList1->getNodeAmount() + asendingList2->getNodeAmount());
    while(node1 != asendingList1->Head() && node2 != asendingList2->Head())
    {
        if (node1->getElem() < node1->getElem())
        {
            node1->prePoint2(mergeNode);
            mergeNode->nextPoint2(node1);
            node1     = List::_next(node1);
            mergeNode = List::_next(mergeNode);
        }
        else
        {
            node2->prePoint2(mergeNode);
            mergeNode->nextPoint2(node2);
            node2     = List::_next(node2);
            mergeNode = List::_next(mergeNode);
        }
    }

    // 由于 list1/list2 可能不一样长
    if(node1 != asendingList1->Head())
    {
        node1->prePoint2(mergeNode);
        mergeNode->nextPoint2(node1);
    }
    else if(node2 != asendingList2->Head())
    {
        node2->prePoint2(mergeNode);
        mergeNode->nextPoint2(node2);
        // 需要保持循环
        Node * tail = asendingList2->Tail();
        tail->nextPoint2(asendingList1->Head());
        asendingList1->setTail(tail);
    }
    // 两者一样长，指向 list1 的头，保持循环
    else
    {
        asendingList1->setTail(mergeNode);
        mergeNode->nextPoint2(asendingList1->Head());
    }

    // 基于 list1 的合并，list2 会成为没有数据节点的空链表
    asendingList2->destroy();
    return asendingList1;
}

// 将传入的链表合并
// void List::mergeAsendingList(List *list)
// {
//     // 需要合并的链表不存在
//     if (list == NULL)
//     {
//         return;
//     }
//     Node * selfNode  = this->Head();
//     Node * otherNode = list->Head();
//     Node * mergeNode = this->Head();

//     // 1 3 4 8 9
//     // 2 6 7 10
//     while(selfNode->getNext())
//     {
//         selfNode = _next(selfNode);
//     }
// }

void List::ascendingOrderInsert(elemType elem)
{
    Node * node = this->head;
    for(int i = 0; i < this->nodeAmount; i++)
    {
        node = this->_next(node);
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
        node = List::_next(node);
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