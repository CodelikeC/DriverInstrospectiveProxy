#include <stdio.h>
#include <stdlib.h>

#include <time.h>
#include "inference_manager.h"

// Todo : sau nay co the query thong tin that tu system.. // 
static int detect_os_stability(void)
{
    return rand() % 101; 
}

static int detect_daemon_health(void)
{
    return rand() % 102; 
}

static int detect_kernel_events(void)
{
    return rand() % 20; 
}

int inference_env_score(void)
{
    int os_stability = detect_os_stability(); 
    int daemon_health = detect_daemon_health(); 
    int kernel_anomalies = detect_kernel_events(); 

    int raw_score = (os_stability + daemon_health) / 2 - (kernel_anomalies *2); 
    // logic : moi truong tot khi co os_stability  + daemon health cao, it anomalies 
    if (raw_score < 0) return raw_score; 
    if (raw_score > 100) raw_score = 100; 

    return raw_score; 
}