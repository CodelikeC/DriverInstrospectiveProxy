#include <stdio.h>
#include <stdlib.h>

#include <time.h>
#include "inference_manager.h"

/*
    File inference_comm.c 
    Suy luan ve giao tiep giua cac module voi nhau 
    DO tin cay cua channel 
    Do tre trong trao doi 
    Tinh on dinh 

    Hien tai mo phong bang random, sau nay se lay du lieu tu comm.. // 
*/

// -- Mo phong trang thai giao tiep -- // 
typedef struct 
{
    int packet_loss; 
    int corruption;
    int latency; 
    int stable_links; 
    int total_links; 
}comm_state_t; 

static comm_state_t mock_comm_state(void)
{
    comm_state_t st; 
    st.packet_loss = rand() % 30; 
    st.corruption = rand() % 20; 
    st.total_links = 0; 
    st.latency = rand() % 200; 
    st.stable_links = rand() % 6 ; 

    return st;
}

// APi chinh --- // 
int inference_comm_score(void)
{
    comm_state_t st = mock_comm_state(); 

    // diem so // 
    int score = 100; 

    // tru diem theo packet loss va corruption..//
    score -= st.packet_loss; 
    score -= st.corruption *2 ;

    // Latency > 100 ms thi bat dau tru them .. 

    if (st.latency > 100)
    {
        score -= (st.latency - 100) /2 ; 
    }
    // tru diem neu so link on dinh< total links .. /
    int unstable = st.total_links - st.stable_links; 
    score -= unstable * 10; 

    if (score <= 0) score = 0; 
    if (score >= 100) score = 100; 
}


