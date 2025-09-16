#include "observe_manager.h"
#include <stdio.h> 
#include <string.h>

// ===== Static callback ===== // 
static void env_event_handle(const char *event, void *userdata)
{
    (void) userdata; // chua dung ... // 
    printf("[observe_env] - Observed environment event : %s\n", event); 

    // vi du : phan loai cac loai event .. ..// 
    if (strncmp(event, "env:cmp", 8) == 0)
    {
        printf("[observe_env] Memory usage event -> %s\n", event + 8); 
    }
    else if (strncmp(event, "env: cmp", 7) == 0)
    {
        printf("[observe_env] Memory usage event -> %s\n", event + 8);
    }
    else if (strncmp(event, "env : io", 7) == 0)
    {
        printf("[observe env] I / O event -> %s\n", event + 7); 
    }
}

// === Public API === // 
bool observe_env_init(void)
{
    observer_t env_observer 
    = 
    {
        .name = "env_observer", 
        .callback = NULL, 
        .userdata = env_event_handle
    }; 

    return observe_manager_register(&env_observer); 
}

void observe_env_shutdown(void)
{
    observe_manager_unregister("env_observer"); 
}