/*
 * gpt.h
 *
 *  Created on: Jan 11, 2023
 *      Author: Daniel Diaz Platon
 */

#ifndef GPT_H_
#define GPT_H_

#include "Std_Types.h"
#include "Gpt_Cfg.h"


void Gpt_GetVersionInfo( Std_VersionInfoType* VersionInfoPtr );

void Gpt_Init( const Gpt_ConfigType* ConfigPtr );

void Gpt_DeInit( void );

Gpt_ValueType Gpt_GetTimeElapsed( Gpt_ChannelType Channel );

Gpt_ValueType Gpt_GetTimeRemaining( Gpt_ChannelType Channel );

void Gpt_StartTimer( Gpt_ChannelType Channel, Gpt_ValueType Value );

void Gpt_StopTimer( Gpt_ChannelType Channel );

void Gpt_EnableNotification( Gpt_ChannelType Channel );

void Gpt_DisableNotification( Gpt_ChannelType Channel );

void Gpt_SetMode( Gpt_ModeType Mode );

void Gpt_DisableWakeup( Gpt_ChannelType Channel );

void Gpt_EnableWakeup( Gpt_ChannelType Channel );

// void Gpt_CheckWakeup( EcuM_WakeupSourceType WakeupSource );

Std_ReturnType Gpt_GetPredefTimerValue( Gpt_PredefTimerType PredefTimer, uint32* TimeValuePtr );




#endif /* GPT_H_ */
