#include <stdio.h> 
#include "comm_channel.h"
#include <stdio.h>

// dinh nghia mot so loai command 

typedef enum{
    CMD_PING, 
    CMD_PONG, 
    CMD_DATA, 
    CMD_SHUTDOWN
} CommandType; 

// ham build message ...//
void process_message(const CommMessage *msg)
{
    switch(msg -> id){
        case CMD_PING: 
        printf("[%s + %s] PING : %s\n", msg -> sender, msg ->payload, msg-> id, msg ->receiver);
        break;  

        case CMD_PONG:
        printf("[%s + %s] PONG : %s\n", msg -> sender, msg ->payload, msg-> id, msg ->receiver); 
        break; 

        case CMD_DATA: 
        printf("[%s + %s] Data : %s\n", msg -> sender, msg ->payload, msg-> id, msg ->receiver);
        break; 

        case CMD_SHUTDOWN:
        printf("[%s + %s] SHUTDOWN : %s\n", msg -> sender, msg ->payload, msg-> id, msg ->receiver);
        break; 

        default: 
        printf("Unknown command\n"); 
    }
}
