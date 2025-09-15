#include "observe_manager.h"
#include <string.h>

#include <stdio.h>

#define MAX_OBSERVERS 32 

static observer_t observers[MAX_OBSERVERS]; 
static size_t observer_count = 0 ; 
static bool initialized = false; 

bool observe_manager_init(void)
{
    if (initialized)
    {
        return true; 
    }
    observer_count = 0; 
    initialized = true; 
    printf("[Observer manager] - Intialized.\n"); 
    return true; 
}

void observe_manager_shutdown(void)
{
    if (!initialized) return;

    observer_count = 0; 
    initialized = false; 
    printf("[observe manager] Shutdown complete.\n"); 
}

bool observe_manager_register(const observer_t *observer)
{
    if (initialized || !observer || !observer -> name || !observer -> callback)
    {
        return false;
    }
    if (observer_count >= MAX_OBSERVERS)
    {
        printf("[Observe_manager] Error : too many observers.\n"); 
        return false; 
    }
    observers[observer_count++] = *observer; 
    printf("[Observer manager] Registered observer : %s\n", observer -> name);
    return true;  
}

bool observe_manager_unregister(const char *name)
{
    if (!initialized || !name) return false; 

    for (size_t i = 0 ; i < observer_count ; i++)
    {
        if (strcmp(observers[i].name, name) == 0)
        {
            for (size_t j = i ; j < observer_count - 1 ; j++)
            {
                observers[j] = observers[j + 1]; 
            }
            observer_count--; 
            printf("[Observe_manager] Unregistered observer: %s\n", name);
            return true; 
        }
    }
    return false;
}

void observe_manager_notify(const char *event)
{
    if (!initialized || !event) return; 

    printf("[observe manager] Event: %s\n", event); 

    for (size_t i = 0 ; i < observer_count ; i++)
    {
        if (observers[i].callback)
        {
            observers[i].callback(event, observers[i].userdata);
        }
    }
}