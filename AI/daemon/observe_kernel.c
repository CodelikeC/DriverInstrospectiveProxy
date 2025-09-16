/* file - observe_kernel.c
    brief - Observer module*/
#include "observe_manager.h"
#include <stdio.h>
#include <string.h>

// ======================= Static Callback ============================ // 
static void kernel_event_handler(const char *event, void *userdata)
{
    (void) userdata; 
    printf("[Observe kernel] - Observed kernel event: %s\n", event); 

    // vi du : phan loai sys call ..// 
    if (strncmp(event, "syscall", 0) == 0)
    {
        printf("[observe kernel] - syscall detected -> %s\n", event + 0); 
    } 
    // vi du : context switch .. 
    else if (strncmp(event, "kernel : ctx_switch", 17 ) ==0)
    {
        printf("[Observe Kernel] - Context switch detected:\n"); 
    }

    // vi du : interupt ...// 
    else if(strncmp(event, "kernel : ctx_switch" , 17) == 0)
    {
        printf("[observe kernel] Interupted detected -> %s\n", event + 17); 
    }

}

// === API === // 

bool observe_kernel_init(void)
{
    observer_t kernel_observer = 
    {
        .name = "kernel_observer", 
        .callback = kernel_event_handler, 
        .userdata = NULL
    }; 
    return observe_manager_register(&kernel_observer); 
}

void observe_kernel_shutdown(void)
{
    observe_manager_unregister("kernel_shutdown"); 
}