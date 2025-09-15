#include "observe_manager.h"
#include <stdio.h>

// callback when it gets hook .. // 
static void hook_event_handler(const char *event, void *userdata)
{
    (void)userdata; // not used right now .. .. 
    printf("[observe kernel] Kernel event observed: %s\n", event); 

    // For example: syscall event ...// 
    if (event && strstr(event, "syscall") == event)
    {
        printf("[observe kernel] - Detected syscall -> %s\n", event + 8);
    }
}

// Ham khoi tao module kernel observer .. // 
bool observe_kernel_init(void)
{
    observer_t kernel_observer = 
    {
        .name = "kernel_observer", 
        .callback = hook_event_handler, 
        .userdata = NULL 
    };
    return observe_manager_register(&kernel_observer); 
}

// Ha shutdown module kernel observer.. // 
void observe_kernel_shutdown(void)
{
    observe_manager_unregister("kernel observer"); 
}