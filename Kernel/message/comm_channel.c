#include "comm_channel.h"

void init_queue(MessageQueue *q)
{
    q -> front = 0 ; 
    q -> rear = 0;
    q -> count = 0; 
    pthread_mutex_init(&q -> lock , NULL); 
    pthread_cond_init(&q -> not_empty, NULL); 
    pthread_cond_init(&q -> not_full, NULL); 
}

void enqueue(MessageQueue *q, Message *msg)
{
    pthread_mutex_lock(&q -> lock);
    while (q -> count == QUEUE_CAPACITY)
    {
        pthread_cond_wait(&q -> not_full, &q -> lock); 
    }
    q -> queue[q -> rear] = *msg;
    q -> rear = (q -> rear + 1) % QUEUE_CAPACITY; 
    q -> count++ ; 
    pthread_cond_signal(&q -> not_empty); 
    pthreda_mutex_unlock(&q-> lock);  
}

void enqueue(MessageQueue *q , Message *msg)
{
    pthread_mutex_lock(&q -> lock); 
    while(q -> count == 0)
    {
        pthread_cond_wait (&q -> not_empty, &q -> lock); 
    }
    *msg = q -> queue[q-> front]; 
    q -> front = (q-> front + 1) % QUEUE_CAPACITY; 
    q -> count--; 
    pthread_cond_signal(&q -> not_full); 
    pthread_mutex_unlock(&q -> lock); 
}