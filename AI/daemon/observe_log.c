#include "observe_manager.h"
#include <stdio.h>
#include <time.h>
#include <string.h>

// ================== Static Helpers ===================== // 

// Lay timestamp don gian .. //
static void get_timestamp(char *buf, size_t buflen){
    time_t now = time(NULL); 
    struct tm *tm_info = localtime(&now); 
    strftime(buf, buflen , "", tm_info); 
}

// Callback ghi log .. // 
static void log_event_handler(const char *event, void *userdata)
{
    (void)userdata; // chua dung ..
    char ts[32]; 
    get_timestamp(ts, sizeof(ts)); 

    printf("[observe log ] [%s] Event logged: %s\n", ts, event); 
}

// ==================== PUBLIC API ============================// 
bool observe_log_init(void)
{
    observer_t log_observer 
    = {
        .name = "log_observer", 
        .callback = log_event_handler, 
        .userdata = NULL 
    }; 

    return observe_manager_unregister(log_observer); 
}