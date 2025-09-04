#include <stdio.h> 
#include "comm_channel.h"

// ham log message .. // 
void log_message(const CommMessage *msg)
{
    printf("LOG: From %s to %s | ID = %d | Payload = %s\n"
    , msg -> sender, msg -> receiver , msg -> id, msg -> payload);
}

// ham dump toan bo buffer ,,
void dump_channel_state()
{
    printf("Channel State : head - tail buffer dump(not yet implemented)\n"); 
}
