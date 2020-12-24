/**
 * @file queue.c
 * @author fengyang (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-12-07
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "queue.h"



#define IS_QUEUE_EMPTY(q)  q->front == q->tail
#define IS_QUEUE_FULL(q)   (q->tail+1)%q->maxlen == q->front
// static int is_queue_empty(queue_t *q )
// {
//     return (q->front == q->tail)? 1:0;
// }

// static int is_queue_full(queue_t *q )
// {
//     return  ((q->tail + 1) % q->maxlen == q->front)?1:0;
// }


void queue_init(queue_t * q,  char *buf,  uint16_t  maxlen)
{
    q->buf = buf;
    q->maxlen = maxlen;
    q->front = q->tail = 0;
}

int queue_push(queue_t * q,  uint8_t data)
{
    if (IS_QUEUE_FULL(q))
        return -1;

    q->buf[q->tail++] = data;
    q->tail %=  q->maxlen;

    return 0;
}

int   queue_pop(queue_t *q, uint8_t *data)
{
    if (IS_QUEUE_EMPTY(q))
        return -1;

    *data = q->buf[q->front++];
    q->front %= q->maxlen;

     return 0; 
}


uint16_t queue_item_counts(queue_t * q)
{
    return (q->front + q->maxlen - q->tail) % q->maxlen;
}


void queue_traverse(queue_t * q , void (*fun)(char dat))
{
    int f = q->front;
    int t = q->tail;
    
    while(t != f)
    {
        fun(q->buf[f++]);
        f  %= q->maxlen;
    }
}