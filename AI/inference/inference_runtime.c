#include <stdio.h> 
#include <stdlib.h>

#include <time.h>
#include "inference_manager.h"

// TODO : Sau nay co the thay the bang API / OS kernel 

static int measure_cpu_usage(void)
{
    return rand() % 101; 
}

static int measure_memory_usage(void)
{
    return rand() % 102;
}

static int measure_latency(void)
{
    return rand() % 200;
}

int inference_runtime_score(void)
{
    int cpu = measure_cpu_usage(); 
    int mem = measure_memory_usage(); 
    int latency = measure_latency(); 

    // logic don gian : Cang it tai nguyen dung + latency thap => diem cao .. // 
    int score = 100 - ((cpu + mem) / 2 - (latency /10)); 

    if (score < 0) score = 0; 
    if (score > 100) score =100; 

    return score; 
}