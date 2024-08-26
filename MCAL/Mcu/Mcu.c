/*
 * Mcu.c
 * Created on: Jan 13, 2023
 * Author: Daniel Diaz Platon
 * 
 */


#include "Mcu.h"


void Mcu_Init( const Mcu_ConfigType* ConfigPtr )
{
    // Enable ports in the MCU  (SWS_Mcu_00248)
    RCC->AHB2ENR |= ConfigPtr->RCC_AHB2ENR_cfg;

    // Enable PLL in the MCU
}

Std_ReturnType Mcu_InitRamSection( Mcu_RamSectionType RamSection )
{
    return 0;
}

Std_ReturnType Mcu_InitClock( Mcu_ClockType ClockSetting )
{
    return 0;
}

Std_ReturnType Mcu_DistributePllClock( void )
{
    return 0;
}

Mcu_PllStatusType Mcu_GetPllStatus( void )
{
    return 0;
}

Mcu_ResetType Mcu_GetResetReason( void )
{
    return 0;
}

Mcu_RawResetType Mcu_GetResetRawValue( void )
{
    return 0;
}

void Mcu_PerformReset( void )
{

}

void Mcu_SetMode( Mcu_ModeType McuMode )
{

}

void Mcu_GetVersionInfo( Std_VersionInfoType* versioninfo )
{

}

Mcu_RamStateType Mcu_GetRamState( void )
{
    return 0;
}

