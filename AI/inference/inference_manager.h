#pragma once 
#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>
#include <time.h> 

typedef enum 
{
    INFERENCE_OK = 0, 
    INFERENCE_ERR_INIT = -1, 
    INFERENCE_ERR_RUNTIME = -2,
    INFERENCE_ERR_ENV = -3, 
    INFERENCE_ERR_DATA = -4, 
    INFERENCE_ERR_BEHAVIOR = -5 ,
    INFERENCE_ERR_COMM  = -6
} inference_status_t;

typedef struct 
{
    time_t timestamp; 
    int runtime_scope; // 
    int env_score;  // diem danh gia moi truong
    int data_score; // diem du lieu
    int behavior_score; // diem danh gia hanh vi
    int comm_score; // diem danh gia giao tiep
    int final_decision; 
}inference_result_t; 

// Khoi tao inference manager .. // 
inference_status_t inference_manager_init(void) ;

// Giai phong inference manager . .. 
void inference_manager_shutdown(void); 

// Chay pipeline suy luan .. // 
inference_status_t inference_manager_init(void); 

// Xuat log suy luan .. ..
void inference_manager_log(const inference_result_t *result); 