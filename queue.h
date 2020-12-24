/**
 * @file queue.h
 * @author fengyang
 * @brief  用一个已知数组初始化一个循环队列，并提供入队/出队方法，
 *         队列最大存储数据范围是 maxlen - 1 
 * @version 0.1
 * @date 2020-12-07
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdint.h>

typedef struct  _queue
{
    char * buf;    
    uint16_t maxlen;
    uint16_t front;
    uint16_t tail;
}queue_t;

/**
 * @brief 初始化循环队列
 * 
 * @param q  待初始化的循环队列对象指针
 * @param buf    用作循环队列缓冲区的首指针
 * @param len    缓冲区的最大长度
 */
void queue_init(queue_t * q,  char *buf,  uint16_t  maxlen);

/**
 * @brief       在队列尾插入一个字节数据
 * 
 * @param q     循环队列对象指针
 * @param data  待入队的数据
 * @return int   0: 成功  -1: 失败(队列已满)
 */
int queue_push(queue_t * q,  uint8_t data);


/**
 * @brief  从队列头取一个字节数据
 * 
 * @param q  循环队列对象指针
 * @param data 出队的一字节数据
 * @return uint8_t   出队的数据
 */
int  queue_pop(queue_t *q, uint8_t *data);

/**
 * @brief 获取当前队列有效元素的个数
 * 
 * @param q 循环队列对象指针
 * @return uint16_t  队列有效元素的个数
 */
uint16_t queue_item_counts(queue_t * q);

void queue_traverse(queue_t * q , void (*fun)(char dat));

#endif
