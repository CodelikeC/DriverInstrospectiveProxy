#include <stdio.h>
#include <string.h>
#include "comm_channel.h"

#define CHANNEL_CAPACITY 64 
// 64 bits 

static CommMessage buffer[CHANNEL_CAPACITY]; 
static int head = 0 , tail = 0 , count = 0; 

int comm_channel_init()
{
    head = tail = count = 0  ; 
    return CHANNEL_OK; 
}

int comm_channel_send(const CommMessage *msg)
{
    if (count == CHANNEL_CAPACITY) 
    return CHANNEL_FULL; 

    buffer[tail] = *msg; 
    tail = (tail + 1) % CHANNEL_CAPACITY; 
    count++; 
    return CHANNEL_OK;
}

void comm_channel_close()
{
    head = tail = count = 0; 
}