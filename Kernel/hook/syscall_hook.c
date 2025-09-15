#include <stdio.h>
#include "hook_manager.h"

static void on_sys_open(const char *target, void *ctx)
{
    printf("[Syscall Hook] - Intercepted %s\n", target); 
}

static void on_sys_exit(const char *target, void *ctx)
{
    printf("[Syscall Hook] - Intercepted %s\n", target); 
}

void init_syscall_hook()
{
    hook_manager_add("sys open", on_sys_open); 
    hook_manager_add("sys exit", on_sys_exit); 
}