#include "comm_channel.h"

// dinh nghia protocol don gian : [len | Payload]...// 
int encode_message(Message *msg, const char *data)
{
    size_t len = strlen(data); 
    if (len >= MAX_MSG_SIZE) return -1; 
    memcpy(msg -> data, data, len); 
    msg ->length = len ; 
    return 0; 
}

void decode_message(Message *msg, char *out)
{
    memcpy(out, msg -> data , msg -> length); 
    out[msg-> length] = '\0'; 
}