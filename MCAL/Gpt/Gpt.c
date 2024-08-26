#include "Gpt.h"



void Gpt_GetVersionInfo( Std_VersionInfoType* VersionInfoPtr ){
    // Do something
}

void Gpt_Init( const Gpt_ConfigType* ConfigPtr ){
    // Initialize timer APB1
    //RCC->APB1ENR |= ConfigPtr->APB1EN_Set_Timer;

    // Initialize timer APB2
    RCC->APB2ENR |= ConfigPtr->APB2EN_Set_Timer;

    //Set Prescaler Value
    for(uint8 i = 0; i < 8; i++){
        ConfigPtr->pTim[i]->PSC = ConfigPtr->PSC[i];
    }

    //Set auto-reload Value
    for(uint8 i = 0; i < 8; i++){
        ConfigPtr->pTim[i]->ARR = ConfigPtr->ARR[i];
    }

    //Set count Value
    for(uint8 i = 0; i < 8; i++){
        ConfigPtr->pTim[i]->CNT = ConfigPtr->CNT[i];
    }

    // Enable timer
    // for(uint8 i = 0; i < 8; i++){
    //     ConfigPtr->pTim[i]->CR1 = TIMx_CR1_CEN;
    // }

}

void Gpt_DeInit( void ){
    // Do something
}

Gpt_ValueType Gpt_GetTimeElapsed( Gpt_ChannelType Channel ){
    // Do something
    return 0U;
}

Gpt_ValueType Gpt_GetTimeRemaining( Gpt_ChannelType Channel ){
    // Do something
    return 0U;
}

void Gpt_StartTimer( Gpt_ChannelType Channel, Gpt_ValueType Value ){
    // Do something
}

void Gpt_StopTimer( Gpt_ChannelType Channel ){
    // Do something
}

void Gpt_EnableNotification( Gpt_ChannelType Channel ){
    // Do something
}

void Gpt_DisableNotification( Gpt_ChannelType Channel ){
    // Do something
}

void Gpt_SetMode( Gpt_ModeType Mode ){
    // Do something
}

void Gpt_DisableWakeup( Gpt_ChannelType Channel ){
    // Do something
}

void Gpt_EnableWakeup( Gpt_ChannelType Channel ){
    // Do something
}

// void Gpt_CheckWakeup( EcuM_WakeupSourceType WakeupSource ){
    // Do something
//}

Std_ReturnType Gpt_GetPredefTimerValue( Gpt_PredefTimerType PredefTimer, uint32* TimeValuePtr ){
    // Do something
    return 0U;
}




