#include <stdio.h> 
#include "hook_manager.h"

static void on_drive_read(const char *target, void *ctx)
{
    printf("[DriveHOOK] Intercepted%s\n", target); 
}

static void on_drive_write(const char *target, void *ctx)
{
    printf("[Drive Hook] Intercepted %s\n", target); 
}

void init_drive_hook()
{
    hook_manager_add("drive_read" , on_drive_read); 
    hook_manager_add("drive write", on_drive_write); 
}
