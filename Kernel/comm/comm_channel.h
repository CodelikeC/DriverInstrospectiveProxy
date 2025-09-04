#pragma once 
#include <stdio.h>
#include <stddef.h>

// kieu du lieu thong diep co ban .. // 
typedef struct 
{
    int id; // ID thong diep 
    char sender[32]; // Module gui ...// 
    char receiver[32]; // Module nhan ...// 
    char payload[256]; // noi dung .. //  
} CommMessage;

// enum trang thai kenh .... 
typedef enum 
{
    CHANNEL_OK = 0 ,
    CHANNEL_ERROR = -1, 
    CHANNEL_FULL = -2, 
    CHANNEL_EMPTY = -3
}ChannelStatus; 

// API chinh .. // 
int comm_channel_init(); 
int comm_channel_send(const CommMessage *msg); 
int comm_channel_receive(CommMessage *msg_out); 
void comm_channel_close();  