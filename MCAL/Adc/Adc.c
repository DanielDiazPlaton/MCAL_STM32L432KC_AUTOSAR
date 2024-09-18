/**************************************************************************************************************
 * @file           : Adc.c
 * @date		   : Aug 26, 2024
 * @author         : Daniel Diaz Platon
 * @brief          : The ADC driver initializes and controls the internal Analogue Digital Converter unit(s) 
 *                   of the microcontroller. It provides services to start and stop a conversion respectively 
 *                   to enable and disable the trigger source of a conversion. Furthermore, it provides 
 *                   services to enable and disable a notification mechanism and routines to query the 
 *                   status and result of a conversion.
 **************************************************************************************************************/

/******************************************************************
 **                         Includes                             **
 *****************************************************************/
#include "Adc.h"


/******************************************************************
 **                         FUNCTIONS                            **
 ******************************************************************/

/**
 * @brief 
 * 
 * @param ConfigPtr 
 */
void Adc_Init( const Adc_ConfigType* ConfigPtr )
{
    /*  These bits are set and cleared by software to define the ADC clock scheme (which is 
        common to both master and slave ADCs).
        The software is allowed to write these bits only when the ADCs are disabled 
        (ADCAL=0, JADSTART=0, ADSTART=0, ADSTP=0, ADDIS=0 and ADEN=0). */
    ADC1_COMMON->CCR &= ~ADC_CCR_CKMODE_0;
    ADC1_COMMON->CCR |= ADC_CCR_CKMODE_1;

    /*  In continuous conversion mode, when a software or hardware regular trigger event occurs, 
        the ADC performs once all the regular conversions of the channels and then automatically 
        restarts and continuously converts each conversions of the sequence. This mode is started 
        with the CONT bit at 1 either by external trigger or by setting the ADSTART bit in the 
        ADC_CR register.*/
    ConfigPtr->p_adc->CFGR |= ADC_CFGR_CONT;

    /*  ADC_SQRy registers must not be modified while regular conversions can occur. For this, 
        the ADC regular conversions must be first stopped by writing ADSTP=1 */
     ConfigPtr->p_adc->SQR1 = 0;

    ConfigPtr->p_adc->SQR1 |= ADC_SQR1_SQ1_0;
    ConfigPtr->p_adc->SQR1 |= ADC_SQR1_SQ1_2;

    /** By default, the ADC is in Deep-power-down mode where its supply is internally switched off 
        to reduce the leakage currents (the reset state of bit DEEPPWD is 1 in the ADC_CR 
        register).
        To start ADC operations, it is first needed to exit Deep-power-down mode by setting bit 
        DEEPPWD=0. */
    ConfigPtr->p_adc->CR &= ~ADC_CR_DEEPPWD;

    /*  Then, it is mandatory to enable the ADC internal voltage regulator by setting the bit 
        ADVREGEN=1 into ADC_CR register.*/
    ConfigPtr->p_adc->CR |= ADC_CR_ADVREGEN;

    /*  Calibration can only be initiated when the ADC is disabled (when ADEN=0). ADCAL bit stays at 1 during all the 
        calibration sequence. It is then cleared by hardware as soon the calibration completes.*/
    ConfigPtr->p_adc->CR |= ADC_CR_ADCAL;

    /*   ADEN=1 enables the ADC */
    ConfigPtr->p_adc->CR |= ADC_CR_ADEN;

    /*  The flag ADRDY will be set once the ADC is ready for operation*/
    while(!(ConfigPtr->p_adc->ISR & ADC_ISR_ADRDY));

    /*  Clear the ADRDY bit in the ADC_ISR register by writing ‘1’ (optional). */
    ConfigPtr->p_adc->ISR |= ADC_ISR_ADRDY;
}

Std_ReturnType Adc_SetupResultBuffer( Adc_GroupType Group, const Adc_ValueGroupType* DataBufferPtr ) 
{
    return 0;
}

void Adc_DeInit( void )
{

}

void Adc_StartGroupConversion( Adc_GroupType Group )
{
    if(1U == Group)
    {
        /*Start ADC conversion. Software starts ADC regular conversions by setting ADSTART=1. */
        ADC1->CR |= ADC_CR_ADSTART;
    }
    else
    {
        /* Do nothing */
    }
}

void Adc_StopGroupConversion( Adc_GroupType Group )
{
    /* The software can decide to stop regular conversions ongoing by setting ADSTP=1 */
}

Std_ReturnType Adc_ReadGroup( Adc_GroupType Group, 
                              Adc_ValueGroupType* DataBufferPtr )
{
    if( 1 == Group)
    {
        /* Wait for conversion to be complete. The ADC notifies the application for each end of regular conversion (EOC)*/
        while(!(ADC1->ISR & ADC_ISR_EOC));

        /* EOC flag is cleared by the software either by writing 1*/
        ADC1->ISR |= ADC_ISR_EOC;

        /*Read converted value*/
        *DataBufferPtr = ADC1->DR;
    }
    else
    {
        /* Do nothing */
    }

    return E_OK;
}

void Adc_EnableHardwareTrigger( Adc_GroupType Group )
{

}

void Adc_DisableHardwareTrigger( Adc_GroupType Group )
{

}

void Adc_EnableGroupNotification( Adc_GroupType Group )
{

}

void Adc_DisableGroupNotification( Adc_GroupType Group )
{

}

Adc_StatusType Adc_GetGroupStatus( Adc_GroupType Group )
{
    return 0;
}

Adc_StreamNumSampleType Adc_GetStreamLastPointer( Adc_GroupType Group, 
                                                  Adc_ValueGroupType** PtrToSamplePtr )
{
    return 0;
}

void Adc_GetVersionInfo( Std_VersionInfoType* versioninfo )
{

}

Std_ReturnType Adc_SetPowerState( Adc_PowerStateRequestResultType* Result )
{
    return 0;
}

Std_ReturnType Adc_GetCurrentPowerState( Adc_PowerStateType* CurrentPowerState, 
                                         Adc_PowerStateRequestResultType* Result )
{
    return 0;
}

Std_ReturnType Adc_GetTargetPowerState( Adc_PowerStateType* TargetPowerState, 
                                        Adc_PowerStateRequestResultType* Result )
{
    return 0;
}

Std_ReturnType Adc_PreparePowerState( Adc_PowerStateType PowerState, 
                                      Adc_PowerStateRequestResultType* Result )
{
    return 0;
}

void Adc_Main_PowerTransitionManager( void )
{

}
