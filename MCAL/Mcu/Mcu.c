/*************************************************************************************************************************************************
 * @file           : Mcu.c
 * @author         : Daniel Diaz Platon
 * @brief          : The MCU Driver [MicroController Unit] provides services for basic microcontroller initialization, power down functionality,
 *                   reset an microcontroller specific functions required from other MCAL software modules.
 *************************************************************************************************************************************************/


#include "Mcu.h"


void Mcu_Init( const Mcu_ConfigType* ConfigPtr )
{
    /* Enable gpio clocks in the MCU  (SWS_Mcu_00248) */
    RCC->AHB2ENR |= ConfigPtr->gpios_clocks_en;
    /* Enable adc clock */
    if(1u == ConfigPtr->adc_en)
        RCC->AHB2ENR |= RCC_AHB2ENR_ADCEN;

    /* Enable FPU */
    #if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
        SCB->CPACR |= ((3UL << 20U) | (3UL << 22U));
    #endif

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

