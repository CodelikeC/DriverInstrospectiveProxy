#include "comm_channel.h"
#include <stdio.h>
#include <string.h>

#include "comm_channel.c"
// Declare tu comm_protocol.c 

typedef enum{
    CMD_PING, 
    CMD_PONG, 
    CMD_DATA, 
    CMD_SHUTDOWN
}CommandType;

void build_message(CommMessage *msg, const char *sender, const char *receiver, CommandType cmd, const char *data );
void process_message(const CommMessage *msg); 

// declare tu comm_util.c 
void log_message(const CommMessage *msg); 

// -- Gia lap 2 module --- // 
void module_A_send(const char *target, CommandType cmd, const char *data)
{
    CommMessage msg; 
    build_message(&msg, "ModuleA", target, cmd, data) ; 
    comm_channel_send(&msg); 
    log_message(&msg);
}

void module_B_receive_and_reply()
{
    CommMessage msg;
    if (comm_channel_receive(&msg) == CHANNEL_OK)
    {
        process_message(&msg);
        // neu la PING thi tra PONG .. // 

        if (msg.id == CMD_PING){
            CommMessage reply; 
            build_message(&reply, "ModuleA", msg.sender, CMD_PONG, "Hello from B") ; 
            comm_channel_send(&reply);
            log_message(&reply); 
        }
    }
}

int main ()
{
    printf("===== Test Comm Module Start =====\n"); 

    comm_channel_init();

    // 1. A gui PING .. // 
    module_A_send("ModuleB" , CMD_PONG, "Are you alive?");
    module_B_receive_and_reply(); 

    // 2. A gui DATA ..// 
    module_A_send("ModuleB", CMD_DATA, "Some important data"); 
    module_B_receive_and_reply(); 

    // 3. A gui SHUTDOWN..// 
     module_A_send("ModuleB", CMD_SHUTDOWN, "Goodbye!");
    module_B_receive_and_reply();

    // 4. B gửi PONG đã nằm trong queue, A nhận lại
    CommMessage reply;
    if (comm_channel_receive(&reply) == CHANNEL_OK) {
        process_message(&reply);
    }

    comm_channel_close();

    printf("=== TEST COMM MODULE END ===\n");
    return 0;
}