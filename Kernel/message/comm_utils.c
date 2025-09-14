#include "comm_channel.h"
#include <string.h>
#include <unistd.h>

MessageQueue  q; 

void *producer(void *arg)
{
    for (int i = 0; i < 10 ; i++)
    {
        Message msg; 
        char buffer[64]; 

        sprintf(buffer, "hello %d", i); 
        encode_message(&msg, buffer);
        
        enqueue(&q, &msg); 
        printf("[Producer] Enqueued: %s\n", buffer); 
        usleep(100000); 
    }
    return NULL; 
}

void *consumer(void *arg)
{
    for (int i = 0 ; i < 10 ; i++)
    {
        Message msg;
        char buffer[64];
        dequeue(&q, &msg); 
        decode_message(&msg, buffer); 
        printf("[Consumer] Dequeued : %s\n", buffer); 
    }
    return NULL; 
}

int main ()
{
    pthread_t prod, cons ; 
    init_queue(&q); 
    pthread_create(&prod, NULL, producer, NULL); 
    pthread_create(&cons, NULL, consumer, NULL); 

    pthread_join(prod, NULL); 
    pthread_join(cons, NULL); 

    return 0; 
}