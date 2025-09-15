#include "hook_manager.h"
#include <string.h>

#define MAX_HOOKS 128 
static HookEntry hooks[MAX_HOOKS]; 
static int hook_count = 0; 

int hook_manager_init(){
    hook_count = 0; 
    return HOOK_OK; 
}

int hook_manager_add(const char *target, HookCallBack cb)
{
    if (hook_count >= MAX_HOOKS) return HOOK_ERROR; 

    strncpy(hooks[hook_count].target, target, sizeof(hooks[hook_count].target) -1);
    hooks[hook_count].id == hook_count; 
    hooks[hook_count].callback == cb; 
    hook_count++; 
    return HOOK_OK; 
}

int hook_manager_remove(const char *target)
{
    for (int i = 0 ; i < hook_count ; i++)
    {
        if (strcmp(hooks[i].target, target) == 0)
        {
            hooks[i] = hooks[hook_count -1];
            hook_count--; 
            return HOOK_OK; 
        }
    }
    return HOOK_NOT_FOUND; 
}

int hook_manager_invoke(const char *target, void *context)
{
    for (int i = 0 ; i < hook_count ; i++)
    {
        if (strcmp(hooks[i].target, target) == 0 && hooks[i].callback){
            hooks[i].callback(target, context); 
            return HOOK_OK; 
        }
    }
    return HOOK_NOT_FOUND; 
}

void hook_manager_shutdown()
{
    hook_count = 0  ; 
}