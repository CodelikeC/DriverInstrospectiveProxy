#pragma once 
#include <iostream> 
#include <stdlib.h>
#include <pthread.h>

#define MAX_MSG_SIZE 1024 
#define QUEUE_CAPACITY 1024 

typedef struct 
{
    char data[MAX_MSG_SIZE]; 
    size_t length; 
}Message; 

typedef struct 
{
    Message queue[QUEUE_CAPACITY]; 
    int front, rear, count; 
    pthread_mutex_t lock;
    pthread_cond_t not_empty; 
    pthread_cond_t not_full;

}MessageQueue;

// API 
void init_queue(MessageQueue *q); 
void enqueue(MessageQueue *q, Message *msg); 
void dequeue(MessageQueue *q, Message *msg); 
