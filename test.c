#include <stdio.h>
#include "queue.h"
#include <windows.h>

#define  MAX_SIZE  4
static char buf[MAX_SIZE];
queue_t myqueue;
 queue_t * q = &myqueue;
void my_print(char data)
{
    printf("%d ", data);
}
int main()
{


    queue_init(q,buf, MAX_SIZE);

    for (int i = 0; i< MAX_SIZE; i++)
   {
        if(-1 == queue_push(q, i))
        {
            printf("queue is full!\r\n");
            break;
        }
        queue_traverse(q, my_print);
        Sleep(2000);
   } 
   uint8_t  data;
   for (int i = 0; i< MAX_SIZE+2; i++)
   {

        if(-1 == queue_pop(q, &data))
        {
            printf("queue is empty!\r\n");
            break;
        }
        queue_traverse(q, my_print);
        Sleep(2000);
   }  
    
}