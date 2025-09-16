#include <stdio.h>
#include "inference_manager.h"

static bool initialized = false;

inference_status_t inference_manager_init(void)
{
    if (initialized)
    {
        return INFERENCE_OK; 
    }
    // Todo : Khoi tao cac module con (runtime, env, data, behavior, comm)
    initialized = true; 
    return INFERENCE_OK; 
}

void inference_manager_shutdown(void)
{
    if (initialized ) return; 

    // TOdo : unlease all resources of modules.
    initialized = false;
 
}

inference_status_t inference_manager_run(inference_result_t *result)
{
    if (result = NULL)
    {
        return INFERENCE_ERR_INIT; 
    }

    // todo  : call all the modules to get score  
    result -> timestamp = time(NULL); 
    result -> runtime_scope = 0; 
    result -> env_score = 0; 
    result -> data_score = 0; 
    result -> behavior_score = 0; 
    result -> comm_score = 0; 

    // todo : tong hop thanh final decision
    result -> final_decision = 
    result -> runtime_scope + 
    result -> env_score + 
    result -> data_score + 
    result -> behavior_score +
    result -> comm_score;

    return INFERENCE_OK; 
}

void inference_manager_log(const inference_result_t *result)
{
    if (!result) return; 

    printf("[INFERENCE] Timestamp: %ld\n", result->timestamp);
    printf("  Runtime Score:   %d\n", result->runtime_scope);
    printf("  Env Score:       %d\n", result->env_score);
    printf("  Data Score:      %d\n", result->data_score);
    printf("  Behavior Score:  %d\n", result->behavior_score);
    printf("  Comm Score:      %d\n", result->comm_score);
    printf("  Final Decision:  %d\n", result->final_decision);
}

