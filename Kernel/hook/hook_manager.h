#pragma once 
#include <stdio.h>
#include <stddef.h>

typedef enum 
{
    HOOK_OK = 0 , 
    HOOK_ERROR = -1, 
    HOOK_NOT_FOUND = -2
}HookStatus; 

typedef void (*HookCallBack)(const char *target, void *context); 

typedef struct 
{
    int id; 
    char target[64]; // ten ham syscall- driver 
    HookCallBack callback; // ham xu ly khi bi hook
}HookEntry;

int hook_manager_init(); 
int hook_manager_add(const char *target, HookCallBack cb);
int hook_manager_remove(const char *target); 

int hook_manager_invoke(const char *target, void *context); 
void hook_manager_shutdown();