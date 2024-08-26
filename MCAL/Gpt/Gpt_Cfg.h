/*
 * Gpt_Cfg.h
 *
 *  Created on: Jan 11, 2023
 *      Author: dplaton
 */

#ifndef GPT_CFG_H_
#define GPT_CFG_H_

typedef struct {
    uint32 APB1EN_Set_Timer;        // Pass number of Bit to enable the desire Timer
    uint32 APB2EN_Set_Timer;        // Pass number of Bit to enable the desire Timer
    TIM_TypeDef* pTim[8];
    uint32 CR1[8];                  // Set preescaler value  
    uint32 PSC[8];                  // Set preescaler value  -- 1600
    uint32 ARR[8];                  // Set auto-reload value -- 10000 
    uint32 CNT[8];                  // Set count value       -- 0
}Gpt_ConfigType;

typedef uint32 Gpt_ChannelType;

typedef uint32 Gpt_ValueType;

typedef enum {
    GPT_MODE_NORMAL,
    GPT_MODE_SLEEP
}Gpt_ModeType;

typedef enum {
    GPT_PREDEF_TIMER_1US_16BIT,
    GPT_PREDEF_TIMER_1US_24BIT,
    GPT_PREDEF_TIMER_1US_32BIT,
    GPT_PREDEF_TIMER_100US_32BIT
}Gpt_PredefTimerType;


#endif /* GPT_CFG_H_ */
