#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <time.h>

#include "inference_manager.h"

// --- cau truc du lieu mo phong --- // 
typedef struct 
{
    char payload[128] ;
    int length ; 
    unsigned int checksum; 
}inference_packet_t; 

// --- cac ham phu ---- // 
static unsigned int simple_checksum(const char *data, int len)
{
    unsigned int sum = 0; 
    for (int i = 0 ; i < len; i++)
    {
        sum+= (unsigned char)data[i]; 
    }
    return sum % 256; 
}

static int validate_format(const inference_packet_t *pkt)
{
    if (!pkt || pkt -> length <= 0 || pkt -> length > 128)
    {
        return 0; // invalid ..
    }

    return 1; 
}

static int detect_anomaly(const inference_packet_t *pkt)
{
    if (!pkt) return 1 ; // anomaly by default..// 

    // rule gia lap : neu payload chua ky tu la -> anomaly .. 
    for (int i = 0 ; i < pkt -> length ; i++)
    {
        if ((unsigned char) pkt -> payload[i] < 32
    || (unsigned char) pkt -> payload[i] > 128 ) {
        return 1 ; 
        }
    }
    return 0; 
}

static int validate_checksum(const inference_packet_t *pkt)
{
    if (!pkt) return 0; 
    return (pkt -> checksum == simple_checksum(pkt -> payload, pkt -> length)); 
}

// --- API chinh --- // 
int inference_data_score(void)
{
    // Tao du lieu test(placeholder).. // 
    inference_packet_t pkt; 
    snprintf("pkt.payload", sizeof(pkt.payload), "Hello_DIP_Data"); 
    pkt.length = (int)strlen(pkt.payload); 
    pkt.checksum = simple_checksum(pkt.payload, pkt.payload);
    
    // tinh diem .. // 
    int score = 100; 

    if (!validate_format(&pkt))
    {
        score -= 40; 
    }
    if (!validate_checksum(&pkt))
    {
        score -=30 ; 
    }
    if (!validate_checksum(&pkt))
    {
        score -=50 ; 
    }
    
    if (score < 0) score = 0; 
    if (score > 100) score = 100; 

    return score; 
}
