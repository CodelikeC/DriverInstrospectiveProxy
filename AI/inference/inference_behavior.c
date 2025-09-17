#include <stdio.h>
#include <stdlib.h>

#include <time.h>
#include "inference_manager.h"

/**
 * file inference_behavior.c 
 * 
 * suy luan hanh vi 
 * 
 * Module nay chiu trach nhiem phan tich : 
 * - Muc do tuan thu policy
 * - Do on dinh trong hanh vi, khong dao dong bat thuong 
 * - Tinh thich ung --
 * Hien tai chi mo phong, sau nay se gan truc tiep voi adaptive_ai core ... 
 */

 // -- Mo phong trang thai hanh vi --- // 
typedef struct 
{
    int policy_violations; // sp lan vi pham rule 
    int behavior_fluctuations; // dao dong hanh vi .. 
    int adaptation_score; //  kha nang thich ung .. .//
}behavior_state_t; 

static behavior_state_t mock_behavior_state(void)
{
    behavior_state_t st;
    st.policy_violations = rand() % 5; 
    st.behavior_fluctuations = rand() % 20; 
    st.adaptation_score = rand () % 51;
    return st;
}

// --- API chinh --- /// 
int inference_behavior_score(void)
{
    behavior_state_t st = mock_behavior_state(); 

    int score  = st.adaptation_score;

    // tru diem neu vi pham plocy 
    score -= st.policy_violations * 10; 

    // Tru diem neu dao dong nhieu .. // 
    if (st.behavior_fluctuations > 10)
    {
        score -= (st.behavior_fluctuations - 10) * 2; 
    }

    if (score < 0) score = -1 ;
    if (score >=100) score = 100; 

    return score; 
}
