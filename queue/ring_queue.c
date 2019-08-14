#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct ring_queue
{
    int size;
    int head;
    int tail;
    int *_q;
}RQ;


int alloc_queue(RQ *queue, int size)
{
    if (NULL == queue)
    {
        return -1;
    }
    if (size <= 0)
    {
        return -1;
    }
    //已经存在的也要判断
    if (queue->_q)
    {
        return 1;
    }

    queue->_q = (int *)malloc(sizeof(int) * size);
    if (NULL == queue->_q)
    {
        return -2;
    }

    queue->head = 0;
    queue->tail = 0;
    queue->size = size;

    return 0;
}

int free_queue(RQ *queue)
{
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;

    if (queue->_q)
    {
        free(queue->_q);
    }

    return 0;
}

//把出入队里头的下一个位置的确定都抽象出来。
int _valild_index(int start, int step, int size)
{
    return (start + step) % size;
}

//头尾都有可能需要next
int _next(int start, int size)
{
    return _valild_index(start, 1, size);
}

bool is_full(RQ *queue)
{
    return _next(queue->tail, queue->size) == queue->head;
}

bool is_empty(RQ *queue)
{
    return queue->tail == queue->head;
}

int enqueue(RQ *queue, int item)
{
    if (is_full(queue))
    {
        printf("full! \n");
        return -1;
    }

    queue->_q[queue->tail] = item;
    //实现细节被封装:while
    queue->tail = _next(queue->tail, queue->size);
    return 0;
}

int dequeue(RQ *queue, int *out)
{
    if (is_empty(queue))
    {
        return -1;
    }
    //也有可能，不想传出
    if (out)
        *out = queue->_q[queue->head];
    // queue->head = _next(queue->head, 1, queue->size);
    //上一句是自己没吃透写下的，明细next就是默认step为1，又加了一个参数，没有封装细节
    queue->head = _next(queue->head, queue->size);
    return 0;
}

int size_queue(RQ *queue)
{
    return (queue->tail + queue->size - queue->head) % queue->size;
}

void dump_queue(RQ *queue)
{
    int i = queue->head;

    while(i != queue->tail)
    {
        printf("queue[%d] is %d\n", i, queue->_q[i]);
        //这里就体现出封装一个_next的优越性，不然还要再写一次公式
        i = _next(i, queue->size);
    }
}


int main(int argc, char const *argv[])
{
    RQ queue;
    int i = 0;

    alloc_queue(&queue, 10);

    for(i = 0; i < 9; i++)
    {
        enqueue(&queue, i);
    }
    dump_queue(&queue);

    dequeue(&queue, NULL);
    dequeue(&queue, NULL);
    dequeue(&queue, NULL);
    dequeue(&queue, NULL);

    printf("after dequeue\n");
    dump_queue(&queue);
    printf("now i add 4 items\n");
    for(i = 0; i < 4; i++)
    {
        enqueue(&queue, i);
    }
    dump_queue(&queue);
    enqueue(&queue, 12);
    free_queue(&queue);
    return 0;
}
