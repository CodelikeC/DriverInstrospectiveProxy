#pragma once 
/*
    Responsible: 
    - On/off observe_demon 
    - Register/non-register observer modules (kernel, hook,vv.)
    - Manage the loop of observation
    - Supplying API for other modules to be reused. 
*/
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

// forward declaration for observer callback .. .. 
typedef void (*observe_callback_t)(const char *event, void *userdata);

// observer module structures... // 
typedef struct 
{
    const char *name; // tem module quan sat .. // 
    observe_callback_t callback; 
    void *userdata; 
}observer_t;

// === API main of Observe Manager === // 

/*
    Create an observing system.. .
    @return true if it get success, false if got errors. 
*/

bool observe_manager_init(void); 

/*
    @brief Register one of observer module .. 
    @param observer module if we needed to add more. 
    @return true if the register gets success.. //
*/

bool observe_manager_register(const observer_t *observer); 

/*
@brief Activate the observing event 
@param event description (For ex: syscall open()); 
*/

void observe_manager_notify(const char *event);
